/*
 * Copyright 2009 Ramon Antonio Parada <rap@ramonantonio.net>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.	If not, see <http://www.gnu.org/licenses/>.
 */

// move the data things to a class called feeddata

//Own
#include "news.h"
#include "scroller.h"

//QT
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsLinearLayout>
#include <QTimer>
#include <QPainter>
#include <QDateTime>
#include <QLineEdit>
#include <QDomDocument>
#include <QFile>

//KDE
#include <kglobal.h>
#include <kicon.h>
#include <kconfigdialog.h>
#include <KStandardDirs>
#include <KMimeType>
#include <Phonon/Path>
#include <Phonon/AudioOutput>
#include <Phonon/MediaObject>
#include <KRun>

//Plasma
#include <plasma/containment.h>
#include <plasma/tooltipmanager.h>

News::News(QObject *parent, const QVariantList &args)
	: Plasma::Applet(parent, args),
		m_collapsed(false)
{
	setHasConfigurationInterface(true);
	setBackgroundHints(DefaultBackground);
	setAcceptDrops(true);
	setAcceptedMouseButtons(Qt::LeftButton);
	setAspectRatioMode( Plasma::ConstrainedSquare );

  // connect(parent, SIGNAL(clicked()), this, SLOT(clickEvent()));

    Plasma::ToolTipContent toolTipData("RSS Notify",
                                       "No new items");
    Plasma::ToolTipManager::self()->setContent(this, toolTipData);
	//resize(48,100);
}

News::~News()
{
 if (hasFailedToLaunch()) {
        // Do some cleanup here
    } else {
        // Save settings
    }

}

void News::init()
{
	KConfigGroup cg = config();

	m_interval = cg.readEntry("interval", 5);
	m_maxAge = cg.readEntry("maxAge", 0);
	m_feedUrl = cg.readEntry("feedUrl", QString("http://www.kde.org/dotkdeorg.rdf"));
	m_iconName = cg.readEntry("iconName", QString("application-rss+xml"));

	m_layout = new QGraphicsLinearLayout(this);
	m_layout->setContentsMargins(0, 0, 0, 0);
	m_layout->setSpacing(0);


	m_timer = new QTimer(this);
	m_scroller = new Scroller(this);
	m_scroller->hide();
	m_layout->addItem(m_scroller);
	m_scroller->show();
	updateScrollers();

	m_layout->setGeometry(geometry());

	QRectF layoutRectF = m_layout->geometry();
	QRectF appletRectF = geometry();
	appletRectF.setHeight(layoutRectF.height()+20);
	setGeometry( appletRectF );

	m_scroller->setGeometry(geometry());
	//	 connect(this, SIGNAL(urlsDropped(KUrl::List)), this, SLOT(openUrls(KUrl::List)));
	// connect(m_timer, SIGNAL(timeout()), this, SLOT(switchItems()));
}




void News::connectToEngine()
{
	Plasma::DataEngine* engine = dataEngine("rss");

	kDebug() << "Connect to source: " << m_feedUrl;
	engine->connectSource(m_feedUrl, m_scroller, m_interval * 60 * 1000);

}

void News::createConfigurationInterface(KConfigDialog *parent)
{
	QWidget *widget = new QWidget(0);
	ui.setupUi(widget);
	connect(parent, SIGNAL(accepted()), this, SLOT(configAccepted()));


	ui.intervalSpinBox->setValue(m_interval);
	ui.feedUrl->setText(m_feedUrl);
	ui.maxAge->setValue(m_maxAge);

	ui.iconbutton->setIcon(m_iconName);
	parent->addPage(widget, i18n("General"), icon());
}


void News::configAccepted()
{
	m_interval = ui.intervalSpinBox->value();
	m_feedUrl = ui.feedUrl->text();
	m_maxAge = ui.maxAge->value();
	m_iconName = ui.iconbutton->icon();
   
configSave();

	updateScrollers();
}

void News::configSave()
{
	KConfigGroup cg = config();
	cg.writeEntry("interval", m_interval);
	cg.writeEntry("feedUrl", m_feedUrl);
	cg.writeEntry("iconName", m_iconName);
	cg.writeEntry("maxAge", m_maxAge);


}


void News::updateScrollers()
{

	kDebug() << "News::update" << m_feedUrl;

	m_scroller->listUpdated();
   m_scroller->setIcon(m_iconName);
   

    Plasma::ToolTipContent toolTipData("RSS Notify",
                                       "linea1<br>linea2");
    Plasma::ToolTipManager::self()->setContent(this, toolTipData);
	m_timer->stop();
	m_timer->setInterval(m_switchInterval * 1000);
	m_timer->start();
	connectToEngine();
}

void News::mousePressEvent ( QGraphicsSceneMouseEvent * event )  {

	Q_UNUSED(event);
	kDebug() << "clickEvent";
KRun::runUrl( KUrl("http://ramonantonio.net/"), "text/html", 0 );
}

//TODO: move to scroller to make adding to existing groups by dropping
//possible.
void News::dropEvent(QGraphicsSceneDragDropEvent *event)
{
	if (!KUrl::List::canDecode(event->mimeData())) {
		return;
	}

	// const KUrl::List urls = KUrl::List::fromMimeData(event->mimeData());

		KUrl::List urls = KUrl::List::fromMimeData(event->mimeData());

	foreach (const KUrl url, urls) {
		KMimeType::Ptr mimeType = KMimeType::findByUrl(url, 0, true);
		// mimetype "image/svg+xml"
		//"image/svg+xml-compressed"
		//QString *url2 = QString(url);
		QString realurl = url.pathOrUrl();
		kDebug() << "dropEvent()"<< url;
		kDebug() << "mimetype" << mimeType->name();
		m_iconName = realurl;
		m_scroller->setIcon(realurl);
		event->accept();
		configSave();
		updateScrollers();

//event->ignore()
//		// if (mimeType->is("inode/directory")) {
		//	QDir dir(url.pathOrUrl());
	}

	
	
}

void News::playSound(){
/*    if(!sound_file.compare("(Nothing)") || sound_file.isEmpty())
	return;
    QString file(KGlobal::dirs()->locate("sound",sound_file));    
    if(file.isEmpty())
	return;
    
    createPath(&media, &audioOutput);
    media.setCurrentSource(file);
    media.play();
*/
}



void News::constraintsEvent(Plasma::Constraints constraints)
{
	kDebug() << "constrainsUpdated : " << constraints;
	if (constraints & Plasma::FormFactorConstraint || constraints & Plasma::SizeConstraint ) {
	

	}
}



#include "news.moc"
