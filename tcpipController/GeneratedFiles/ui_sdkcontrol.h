/********************************************************************************
** Form generated from reading UI file 'sdkcontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SDKCONTROL_H
#define UI_SDKCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SDkform
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QTableWidget *tab;
    QTextEdit *textEdit;

    void setupUi(QWidget *SDkform)
    {
        if (SDkform->objectName().isEmpty())
            SDkform->setObjectName(QStringLiteral("SDkform"));
        SDkform->resize(759, 511);
        verticalLayout = new QVBoxLayout(SDkform);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter = new QSplitter(SDkform);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        tab = new QTableWidget(splitter);
        if (tab->columnCount() < 2)
            tab->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tab->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tab->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tab->setObjectName(QStringLiteral("tab"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy);
        tab->setMinimumSize(QSize(415, 0));
        tab->setMaximumSize(QSize(100000, 100000));
        tab->setAutoFillBackground(false);
        tab->setFrameShape(QFrame::Box);
        tab->setFrameShadow(QFrame::Sunken);
        tab->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tab->setProperty("showDropIndicator", QVariant(false));
        tab->setAlternatingRowColors(false);
        tab->setSelectionMode(QAbstractItemView::SingleSelection);
        tab->setSelectionBehavior(QAbstractItemView::SelectRows);
        tab->setTextElideMode(Qt::ElideLeft);
        tab->setShowGrid(true);
        tab->setGridStyle(Qt::CustomDashLine);
        tab->setSortingEnabled(true);
        splitter->addWidget(tab);
        tab->horizontalHeader()->setCascadingSectionResizes(true);
        tab->horizontalHeader()->setHighlightSections(false);
        tab->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tab->horizontalHeader()->setStretchLastSection(false);
        tab->verticalHeader()->setVisible(true);
        tab->verticalHeader()->setStretchLastSection(false);
        textEdit = new QTextEdit(splitter);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);
        splitter->addWidget(textEdit);

        verticalLayout->addWidget(splitter);


        retranslateUi(SDkform);

        QMetaObject::connectSlotsByName(SDkform);
    } // setupUi

    void retranslateUi(QWidget *SDkform)
    {
        SDkform->setWindowTitle(QApplication::translate("SDkform", "\345\267\241\346\233\264\344\277\241\346\201\257\345\205\245\345\272\223", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tab->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SDkform", "\350\256\276\345\244\207IP", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tab->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SDkform", "\346\216\247\345\210\266\345\231\250\345\234\260\345\235\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SDkform: public Ui_SDkform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SDKCONTROL_H
