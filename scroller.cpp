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

#ifndef SCROLLER_CPP
#define SCROLLER_CPP


#include "scroller.h"
#include "feeddata.h"
#include <sstream>

//QT
#include <QGraphicsItem>
#include <QDateTime>
#include <QPainter>
#include <QFont>
#include <QTimer>
#include <QList>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QIcon>

//KDE
#include <kdebug.h>
#include <kcursor.h>
#include <kicon.h>
#include <krun.h>

//Plasma
#include <plasma/svg.h>
#include <plasma/theme.h>
#include <plasma/widgets/iconwidget.h>
#include <plasma/animator.h>
#define BTN_SIZE 20

using namespace Plasma;

Scroller::Scroller(QGraphicsItem *parent) :
		QGraphicsWidget(parent),
		m_maxAge(0),
		m_counter(0),
		m_list(new QList<FeedData>())
{

	setAcceptedMouseButtons(Qt::LeftButton);
	setMaximumSize(QSizeF(64, 64));
	setMinimumSize(QSizeF(32, 32));
	setPreferredSize(QSizeF(48, 48));
	setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
	//updateSize();


	m_icon = new KIcon();
	listUpdated();
	m_counter=0;
}


Scroller::~Scroller() {
	delete m_list;
}


void Scroller::paint(QPainter *p, const QStyleOptionGraphicsItem *option,
						   QWidget *widget)
{

	kDebug() << "repaint!!";
	Q_UNUSED(option);
	Q_UNUSED(widget);

	qreal width = geometry().width();
	qreal height = geometry().height();


	p->setRenderHint(QPainter::Antialiasing);
	m_icon->paint(p, 0, 0, width, height);

	//circle
	// QCanvasPolygonalItem* i = new QCanvasEllipse(50,50,&_canvas);
	//   i->setBrush( NoBrush);
	//   i->setZ(256);
	if (m_counter != 0){
		p->setPen(QColor("red"));
		//p->setBackgroundMode( Qt::OpaqueMode );             // set opaque mode
		p->setBrush(QBrush(QColor("red"), Qt::SolidPattern) );                // black diagonal cross pattern
		p->drawEllipse(QRectF(width+3.0-height/3,2.0,height/3, height/3));

		//counter
		QFont font = Plasma::Theme::defaultTheme()->font(Plasma::Theme::DefaultFont);
		font.setPixelSize(height/5.0+1); 
		p->setPen(QColor("white"));
		font.setBold(true);
		p->setFont(font);
		QString text;
		text.setNum(m_counter);
	
		p->drawText(QRectF(4, 4, width-2, height-2), Qt::AlignRight | Qt::AlignTop, text);
	}
}


void Scroller::listUpdated()
{

	m_counter = m_list->size();
	this->update();
   
	kDebug() << "listUpdated() items:" << m_counter;
}


void Scroller::clearUnusedItems()
{
	kDebug() << "clearing items";
}

void Scroller::dataUpdated(const QString& source, const Plasma::DataEngine::Data &data)
{
	if (!data.isEmpty()) {
		m_list->clear();

		kDebug() << "feed " << source << " updated.";

		QVariantList items = data["items"].toList();

		foreach (const QVariant &tmp, items) {
			QMap<QString, QVariant> item = tmp.toMap();
			QString title = item["title"].toString();
			QString url = item["link"].toString();
			QString icon = item["icon"].toString();
			QString feedtitle = item["feed_title"].toString();
			QString feedurl = item["feed_url"].toString();

			uint timestamp = item["time"].toUInt();
			QDateTime datetime;
			datetime.setTime_t(timestamp);

			if (!(timestamp > 0 &&  m_maxAge > 0 &&  //Only add if not too old
				datetime.addSecs(m_maxAge * 60) < QDateTime::currentDateTime())) {
				FeedData data;
				data.text = title;

				kDebug() << "feed " << title;
				data.title = feedtitle;
				data.url = url;
				data.time = timestamp;

				data.itemNumber = m_list->size();
				m_list->append(data);
			}


		}
	}
	listUpdated();
}


void Scroller::setIcon(QString iconName)
{
	kDebug() << "setIcon " << iconName;

	//QString test = QString("/home/rap/rss/rssnow/svg/facebook.svg");

	//delete m_icon;
	//m_iconName = iconName;
	//if (iconName.indexOf(QString("/")) == 0) {
	// m_icon = new KIcon(QIcon(iconName));
	//} else {
	m_icon = new KIcon(iconName);
	//}
	listUpdated();
}


#include "scroller.moc"
#endif // SCROLLER_CPP

