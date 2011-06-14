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

#ifndef SCROLLER_HEADER
#define SCROLLER_HEADER

#include "feeddata.h"
#include <QList>
#include <QGraphicsWidget>
#include <plasma/plasma_export.h>
#include <plasma/animator.h>
#include <plasma/dataengine.h>


class KIcon;
//class SingleFeedItem;
class FeedData;

namespace Plasma
{
  // namespace Plasma
  class IconWidget;
  class Svg;
}

class Scroller : public QGraphicsWidget
{
    Q_OBJECT

public:
    Scroller(QGraphicsItem *parent = 0);
    virtual ~Scroller();

   // virtual void setGeometry(const QRectF &geometry);

    QList<FeedData> * list();
   // void delayedMoveNext(int delay);
    void listUpdated();

   // void setAnimations(bool animations);
   // bool animations() const;

    int  maxAge() const;
    void setMaxAge(int maxAge);

   //     void setCounter(int counter);
   // bool dropTarget() const;
   // void setDropTarget(bool droptarget);

        virtual void paint(QPainter *p,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget = 0);
   // bool hovering() const;

public slots:
    void dataUpdated(const QString& source, const Plasma::DataEngine::Data &data);
        void setIcon(QString iconName);

protected:
//    virtual void wheelEvent (QGraphicsSceneWheelEvent *event);
   // virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
  //  virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
   // virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
   // virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

protected slots:
  //  void leftClicked();
  //  void rightClicked();
  //  void moveNext();
  //  void movePrev();
   // void animationComplete(int);
    void clearUnusedItems();
    //void animate(qreal anim);

private:
    void updateSize();
    void doAnimation();
    QString fuzzyDate(const QDateTime& datetime);

    int m_animid;
    int m_animdirection;
    int m_animations;

    //how many times has the user clicked / scrolled next or previous
    //while the current animation is being displayed.
    //int m_delayedNext;
    //int m_delayedPrev;
        KIcon *m_icon;
        int m_counter;
        QRect m_rect;

    int m_maxAge;
//QString m_iconName;
    //bool m_droptarget;

    QList<FeedData> *m_list;
    //itemlist contains all SingleFeedItems that are currently in
    //memory and should be cleared later.
   // QList<FeedData *> *m_itemlist;
   // SingleFeedItem *m_item;
    //activeitemlist contains all SingleFeedItems that are currently
    //displayed (always 1 or 2 in a horizontal scroller, but a future
    //vertical scroller might need more so we use a list
   // QList<SingleFeedItem *> *m_activeitemlist;
   // QMap<QString, KIcon *> m_feedIcons;

   // Plasma::IconWidget *m_left;
   // Plasma::IconWidget *m_right;

};

#endif
