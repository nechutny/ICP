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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNov_s_ov;
    QAction *novaHra;
    QAction *actionUlo_it;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *scoreGreen;
    QLabel *scoreYellow;
    QLabel *scoreRed;
    QLabel *scoreBlue;
    QLabel *card;
    QPushButton *rotateR;
    QPushButton *rotateL;
    QPushButton *square;
    QSpinBox *spinBox;
    QLabel *label_5;
    QSpinBox *spinBox_2;
    QLabel *label_6;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuHra;
    QMenu *menuN_pov_da;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(512, 411);
        actionNov_s_ov = new QAction(MainWindow);
        actionNov_s_ov->setObjectName(QStringLiteral("actionNov_s_ov"));
        novaHra = new QAction(MainWindow);
        novaHra->setObjectName(QStringLiteral("novaHra"));
        actionUlo_it = new QAction(MainWindow);
        actionUlo_it->setObjectName(QStringLiteral("actionUlo_it"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 290, 51, 17));
        QPalette palette;
        QBrush brush(QColor(0, 170, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(0, 255, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        QBrush brush2(QColor(0, 212, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(0, 85, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(0, 113, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush5(QColor(255, 255, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        QBrush brush7(QColor(127, 212, 127, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        label->setPalette(palette);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 290, 51, 17));
        QPalette palette1;
        QBrush brush9(QColor(255, 255, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush9);
        QBrush brush10(QColor(255, 255, 127, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush10);
        QBrush brush11(QColor(255, 255, 63, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        QBrush brush12(QColor(127, 127, 0, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush12);
        QBrush brush13(QColor(170, 170, 0, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        label_2->setPalette(palette1);
        label_2->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 290, 61, 17));
        QPalette palette2;
        QBrush brush14(QColor(255, 0, 0, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush14);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush14);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush14);
        QBrush brush15(QColor(133, 133, 133, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        label_3->setPalette(palette2);
        label_3->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(290, 290, 51, 17));
        QPalette palette3;
        QBrush brush16(QColor(0, 0, 255, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush16);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        label_4->setPalette(palette3);
        label_4->setFont(font);
        scoreGreen = new QLabel(centralWidget);
        scoreGreen->setObjectName(QStringLiteral("scoreGreen"));
        scoreGreen->setGeometry(QRect(50, 250, 31, 17));
        scoreYellow = new QLabel(centralWidget);
        scoreYellow->setObjectName(QStringLiteral("scoreYellow"));
        scoreYellow->setGeometry(QRect(130, 250, 31, 17));
        scoreRed = new QLabel(centralWidget);
        scoreRed->setObjectName(QStringLiteral("scoreRed"));
        scoreRed->setGeometry(QRect(230, 250, 31, 17));
        scoreBlue = new QLabel(centralWidget);
        scoreBlue->setObjectName(QStringLiteral("scoreBlue"));
        scoreBlue->setGeometry(QRect(330, 250, 31, 17));
        card = new QLabel(centralWidget);
        card->setObjectName(QStringLiteral("card"));
        card->setGeometry(QRect(400, 0, 64, 128));
        rotateR = new QPushButton(centralWidget);
        rotateR->setObjectName(QStringLiteral("rotateR"));
        rotateR->setGeometry(QRect(390, 150, 85, 27));
        rotateL = new QPushButton(centralWidget);
        rotateL->setObjectName(QStringLiteral("rotateL"));
        rotateL->setGeometry(QRect(390, 230, 85, 27));
        square = new QPushButton(centralWidget);
        square->setObjectName(QStringLiteral("square"));
        square->setGeometry(QRect(390, 190, 85, 27));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(410, 290, 46, 27));
        spinBox->setMinimum(5);
        spinBox->setMaximum(11);
        spinBox->setSingleStep(2);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(400, 270, 55, 17));
        spinBox_2 = new QSpinBox(centralWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(350, 290, 46, 27));
        spinBox_2->setMinimum(12);
        spinBox_2->setMaximum(24);
        spinBox_2->setSingleStep(12);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(340, 260, 55, 17));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(400, 330, 85, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 512, 27));
        menuHra = new QMenu(menuBar);
        menuHra->setObjectName(QStringLiteral("menuHra"));
        menuN_pov_da = new QMenu(menuBar);
        menuN_pov_da->setObjectName(QStringLiteral("menuN_pov_da"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setEnabled(true);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuHra->menuAction());
        menuBar->addAction(menuN_pov_da->menuAction());
        menuHra->addAction(actionUlo_it);
        menuHra->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNov_s_ov->setText(QApplication::translate("MainWindow", "Nov\303\241 s\303\255\305\245ov\303\241", 0));
        novaHra->setText(QApplication::translate("MainWindow", "Nov\303\241 hra", 0));
        actionUlo_it->setText(QApplication::translate("MainWindow", "Ulo\305\276it", 0));
        label->setText(QApplication::translate("MainWindow", "Zelen\303\275:", 0));
        label_2->setText(QApplication::translate("MainWindow", "\305\275lut\303\275:", 0));
        label_3->setText(QApplication::translate("MainWindow", "\304\214erven\303\275:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Modr\303\275:", 0));
        scoreGreen->setText(QApplication::translate("MainWindow", "0", 0));
        scoreYellow->setText(QApplication::translate("MainWindow", "0", 0));
        scoreRed->setText(QApplication::translate("MainWindow", "0", 0));
        scoreBlue->setText(QApplication::translate("MainWindow", "0", 0));
        card->setText(QApplication::translate("MainWindow", "card", 0));
        rotateR->setText(QString());
        rotateL->setText(QString());
        square->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Velikost", 0));
        label_6->setText(QApplication::translate("MainWindow", "Po\304\215et karet", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Nov\303\241 hra", 0));
        menuHra->setTitle(QApplication::translate("MainWindow", "Hra", 0));
        menuN_pov_da->setTitle(QApplication::translate("MainWindow", "N\303\241pov\304\233da", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
