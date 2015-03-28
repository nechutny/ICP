/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNov_s_ov;
    QAction *actionNov_lok_ln;
    QAction *actionUlo_it;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuHra;
    QMenu *menuN_pov_da;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(328, 264);
        actionNov_s_ov = new QAction(MainWindow);
        actionNov_s_ov->setObjectName(QStringLiteral("actionNov_s_ov"));
        actionNov_lok_ln = new QAction(MainWindow);
        actionNov_lok_ln->setObjectName(QStringLiteral("actionNov_lok_ln"));
        actionUlo_it = new QAction(MainWindow);
        actionUlo_it->setObjectName(QStringLiteral("actionUlo_it"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 328, 25));
        menuHra = new QMenu(menuBar);
        menuHra->setObjectName(QStringLiteral("menuHra"));
        menuN_pov_da = new QMenu(menuBar);
        menuN_pov_da->setObjectName(QStringLiteral("menuN_pov_da"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuHra->menuAction());
        menuBar->addAction(menuN_pov_da->menuAction());
        menuHra->addAction(actionNov_s_ov);
        menuHra->addAction(actionNov_lok_ln);
        menuHra->addSeparator();
        menuHra->addAction(actionUlo_it);
        menuHra->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNov_s_ov->setText(QApplication::translate("MainWindow", "Nov\303\241 s\303\255\305\245ov\303\241", 0));
        actionNov_lok_ln->setText(QApplication::translate("MainWindow", "Nov\303\241 lok\303\241ln\303\255", 0));
        actionUlo_it->setText(QApplication::translate("MainWindow", "Ulo\305\276it", 0));
        menuHra->setTitle(QApplication::translate("MainWindow", "Hra", 0));
        menuN_pov_da->setTitle(QApplication::translate("MainWindow", "N\303\241pov\304\233da", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
