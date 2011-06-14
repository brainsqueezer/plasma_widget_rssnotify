#include <kdialog.h>
#include <klocale.h>

/********************************************************************************
** Form generated from reading ui file 'config.ui'
**
** Created: Mon Jan 12 18:00:58 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>
#include "kicondialog.h"
#include "knuminput.h"

QT_BEGIN_NAMESPACE

class Ui_config
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_6;
    KIntSpinBox *maxAge;
    KIntSpinBox *intervalSpinBox;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label_21;
    QLineEdit *feedUrl;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    KIconButton *iconbutton;

    void setupUi(QWidget *config)
    {
    if (config->objectName().isEmpty())
        config->setObjectName(QString::fromUtf8("config"));
    config->resize(403, 282);
    config->setStyleSheet(QString::fromUtf8(""));
    gridLayout = new QGridLayout(config);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label = new QLabel(config);
    label->setObjectName(QString::fromUtf8("label"));
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    label->setFont(font);

    gridLayout->addWidget(label, 0, 0, 1, 3);

    horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

    label_6 = new QLabel(config);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout->addWidget(label_6, 7, 1, 1, 3);

    maxAge = new KIntSpinBox(config);
    maxAge->setObjectName(QString::fromUtf8("maxAge"));
    maxAge->setMaximum(525600);

    gridLayout->addWidget(maxAge, 7, 4, 1, 1);

    intervalSpinBox = new KIntSpinBox(config);
    intervalSpinBox->setObjectName(QString::fromUtf8("intervalSpinBox"));
    intervalSpinBox->setMinimum(1);
    intervalSpinBox->setMaximum(525600);
    intervalSpinBox->setValue(5);

    gridLayout->addWidget(intervalSpinBox, 6, 4, 1, 1);

    verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

    gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

    horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(horizontalSpacer_2, 6, 5, 1, 1);

    label_8 = new QLabel(config);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setFont(font);

    gridLayout->addWidget(label_8, 5, 0, 1, 2);

    label_2 = new QLabel(config);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout->addWidget(label_2, 6, 1, 1, 1);

    label_21 = new QLabel(config);
    label_21->setObjectName(QString::fromUtf8("label_21"));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
    label_21->setSizePolicy(sizePolicy);
    label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    gridLayout->addWidget(label_21, 2, 1, 1, 1);

    feedUrl = new QLineEdit(config);
    feedUrl->setObjectName(QString::fromUtf8("feedUrl"));

    gridLayout->addWidget(feedUrl, 8, 2, 1, 3);

    label_3 = new QLabel(config);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout->addWidget(label_3, 8, 1, 1, 1);

    verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_2, 9, 1, 1, 1);

    iconbutton = new KIconButton(config);
    iconbutton->setObjectName(QString::fromUtf8("iconbutton"));
    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(iconbutton->sizePolicy().hasHeightForWidth());
    iconbutton->setSizePolicy(sizePolicy1);
    iconbutton->setIconSize(48);

    gridLayout->addWidget(iconbutton, 2, 4, 1, 1);


    retranslateUi(config);

    QMetaObject::connectSlotsByName(config);
    } // setupUi

    void retranslateUi(QWidget *config)
    {
    label->setText(tr2i18n("Appearence", 0));
    label_6->setText(tr2i18n("Maximum age of items <i>(0 for no limit)</i>:", 0));
    maxAge->setSuffix(tr2i18n(" hours", 0));
    intervalSpinBox->setSuffix(tr2i18n(" minutes", 0));
    label_8->setText(tr2i18n("RSS Source", 0));
    label_2->setText(tr2i18n("Update &interval:", 0));
    label_21->setText(tr2i18n("Custom icon:", 0));
    label_3->setText(tr2i18n("RSS Location:", 0));
    Q_UNUSED(config);
    } // retranslateUi

};

namespace Ui {
    class config: public Ui_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CONFIG_H

