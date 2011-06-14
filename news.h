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

#ifndef NEWS_HEADER
#define NEWS_HEADER

//Plasma
#include <Plasma/Applet>
#include <Plasma/DataEngine>
#include <plasma/widgets/iconwidget.h>

#include <QTimer>
#include <Phonon/AudioOutput>
#include <Phonon/MediaObject>


//Own
#include "ui_config.h"
#include "feeddata.h"

namespace Plasma {
	class VBoxLayout;
	class Svg;
}

namespace Phonon {
class MediaObject;
class AudioOutput;
}

class Scroller;
//class SingleFeedItem;
class QGraphicsLinearLayout;

class News : public Plasma::Applet
{
   Q_OBJECT
   public:
		News(QObject *parent, const QVariantList &args);
		~News();
		void init();

	public slots:
		void createConfigurationInterface(KConfigDialog *parent);
		//void switchItems();

	protected:
		void constraintsEvent(Plasma::Constraints constraints);
virtual void mousePressEvent ( QGraphicsSceneMouseEvent * event ) ;

	protected Q_SLOTS:
		void dropEvent(QGraphicsSceneDragDropEvent *event);

	private slots:
		void configAccepted();
		void configSave();
void playSound();
		// void addFeed();
		// void removeFeed();
		// void slotItemChanged();
		// void slotChangeText( const QString& text );
		// virtual void openUrls(KUrl::List);

	private:
		QString m_feedUrl;
		// QList<Scroller *>   m_scrollerList;
		Scroller *m_scroller;
		QTimer *m_timer;
		QMap<QString, QString> m_defaultFeeds;
		//QMap<QString, QString> akregatorFeeds();
		uint m_interval;
		uint m_switchInterval;
		// bool m_showdroptarget;
		bool m_collapsed;
		int m_maxAge;


		// Plasma::IconWidget *m_icon;
		QString m_iconName;
		QGraphicsLinearLayout  *m_layout;
		Ui::config ui;
		// Ui::feedsConfig feedsUi;
		void connectToEngine();
		void updateScrollers();
		QString fuzzyDate(const QDateTime& date);
	// For play sound
//	Phonon::MediaObject media;
//	Phonon::AudioOutput audioOutput;
//QString sound_file;
};

K_EXPORT_PLASMA_APPLET(rssnow, News)

#endif
