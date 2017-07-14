/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Mon May 15 16:55:26 2017
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *serial_widget;
    QPushButton *thlButton;
    QWidget *Motor_widget;
    QFrame *Motor_frame;
    QPushButton *forwardButton;
    QPushButton *reversalButton;
    QPushButton *stopButton;
    QPushButton *Motor_Button;
    QPushButton *LED_Button;
    QWidget *LED_widget;
    QFrame *frame_3;
    QPushButton *LED4;
    QPushButton *LED3;
    QPushButton *LED1;
    QPushButton *LED2;
    QPushButton *PWM_button;
    QWidget *thl_widget;
    QFrame *frame_2;
    QLCDNumber *lcd_temp;
    QLCDNumber *lcd_humi;
    QLCDNumber *lcd_light;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *ray_label;
    QLCDNumber *label_ultra;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *IntelButton;
    QPushButton *comButton;
    QLabel *label;
    QLCDNumber *hour_lcd;
    QLCDNumber *testlcd;
    QTextBrowser *ComBrowser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(790, 423);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        serial_widget = new QWidget(centralWidget);
        serial_widget->setObjectName(QString::fromUtf8("serial_widget"));
        serial_widget->setGeometry(QRect(20, 60, 751, 291));
        thlButton = new QPushButton(serial_widget);
        thlButton->setObjectName(QString::fromUtf8("thlButton"));
        thlButton->setGeometry(QRect(520, 10, 111, 41));
        Motor_widget = new QWidget(serial_widget);
        Motor_widget->setObjectName(QString::fromUtf8("Motor_widget"));
        Motor_widget->setGeometry(QRect(20, 60, 251, 221));
        Motor_widget->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/background.jpg);"));
        Motor_frame = new QFrame(Motor_widget);
        Motor_frame->setObjectName(QString::fromUtf8("Motor_frame"));
        Motor_frame->setGeometry(QRect(10, 10, 221, 201));
        Motor_frame->setFrameShape(QFrame::StyledPanel);
        Motor_frame->setFrameShadow(QFrame::Raised);
        forwardButton = new QPushButton(Motor_frame);
        forwardButton->setObjectName(QString::fromUtf8("forwardButton"));
        forwardButton->setGeometry(QRect(10, 10, 91, 41));
        forwardButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        reversalButton = new QPushButton(Motor_frame);
        reversalButton->setObjectName(QString::fromUtf8("reversalButton"));
        reversalButton->setGeometry(QRect(10, 60, 91, 51));
        reversalButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        stopButton = new QPushButton(Motor_frame);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(10, 120, 91, 51));
        stopButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Motor_Button = new QPushButton(serial_widget);
        Motor_Button->setObjectName(QString::fromUtf8("Motor_Button"));
        Motor_Button->setGeometry(QRect(90, 10, 111, 41));
        LED_Button = new QPushButton(serial_widget);
        LED_Button->setObjectName(QString::fromUtf8("LED_Button"));
        LED_Button->setGeometry(QRect(300, 10, 111, 41));
        LED_widget = new QWidget(serial_widget);
        LED_widget->setObjectName(QString::fromUtf8("LED_widget"));
        LED_widget->setGeometry(QRect(280, 60, 171, 221));
        LED_widget->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/background.jpg);"));
        frame_3 = new QFrame(LED_widget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 10, 151, 201));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        LED4 = new QPushButton(frame_3);
        LED4->setObjectName(QString::fromUtf8("LED4"));
        LED4->setGeometry(QRect(90, 70, 51, 51));
        LED3 = new QPushButton(frame_3);
        LED3->setObjectName(QString::fromUtf8("LED3"));
        LED3->setGeometry(QRect(10, 70, 51, 51));
        LED1 = new QPushButton(frame_3);
        LED1->setObjectName(QString::fromUtf8("LED1"));
        LED1->setGeometry(QRect(10, 10, 51, 51));
        LED2 = new QPushButton(frame_3);
        LED2->setObjectName(QString::fromUtf8("LED2"));
        LED2->setGeometry(QRect(90, 10, 51, 51));
        PWM_button = new QPushButton(frame_3);
        PWM_button->setObjectName(QString::fromUtf8("PWM_button"));
        PWM_button->setGeometry(QRect(10, 130, 131, 41));
        thl_widget = new QWidget(serial_widget);
        thl_widget->setObjectName(QString::fromUtf8("thl_widget"));
        thl_widget->setGeometry(QRect(470, 70, 261, 221));
        thl_widget->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/background.jpg);"));
        frame_2 = new QFrame(thl_widget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 10, 241, 81));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        lcd_temp = new QLCDNumber(frame_2);
        lcd_temp->setObjectName(QString::fromUtf8("lcd_temp"));
        lcd_temp->setGeometry(QRect(10, 10, 64, 32));
        lcd_humi = new QLCDNumber(frame_2);
        lcd_humi->setObjectName(QString::fromUtf8("lcd_humi"));
        lcd_humi->setGeometry(QRect(80, 10, 64, 31));
        lcd_light = new QLCDNumber(frame_2);
        lcd_light->setObjectName(QString::fromUtf8("lcd_light"));
        lcd_light->setGeometry(QRect(160, 10, 64, 31));
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 50, 34, 32));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 50, 34, 31));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 50, 34, 31));
        ray_label = new QPushButton(thl_widget);
        ray_label->setObjectName(QString::fromUtf8("ray_label"));
        ray_label->setGeometry(QRect(60, 110, 111, 27));
        label_ultra = new QLCDNumber(thl_widget);
        label_ultra->setObjectName(QString::fromUtf8("label_ultra"));
        label_ultra->setGeometry(QRect(60, 160, 111, 31));
        label_6 = new QLabel(thl_widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 120, 26, 17));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        label_7 = new QLabel(thl_widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 160, 39, 23));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        frame_2->raise();
        label_6->raise();
        label_6->raise();
        ray_label->raise();
        label_ultra->raise();
        label_6->raise();
        label_7->raise();
        IntelButton = new QPushButton(serial_widget);
        IntelButton->setObjectName(QString::fromUtf8("IntelButton"));
        IntelButton->setGeometry(QRect(650, 10, 92, 41));
        comButton = new QPushButton(centralWidget);
        comButton->setObjectName(QString::fromUtf8("comButton"));
        comButton->setGeometry(QRect(60, 6, 101, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(25, 16, 41, 21));
        hour_lcd = new QLCDNumber(centralWidget);
        hour_lcd->setObjectName(QString::fromUtf8("hour_lcd"));
        hour_lcd->setGeometry(QRect(230, 10, 131, 31));
        testlcd = new QLCDNumber(centralWidget);
        testlcd->setObjectName(QString::fromUtf8("testlcd"));
        testlcd->setGeometry(QRect(410, 10, 101, 31));
        ComBrowser = new QTextBrowser(centralWidget);
        ComBrowser->setObjectName(QString::fromUtf8("ComBrowser"));
        ComBrowser->setGeometry(QRect(560, 0, 121, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 790, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        thlButton->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\346\271\277\345\272\246\344\272\256\345\272\246", 0, QApplication::UnicodeUTF8));
        forwardButton->setText(QApplication::translate("MainWindow", "\346\224\276\344\270\213", 0, QApplication::UnicodeUTF8));
        reversalButton->setText(QApplication::translate("MainWindow", "\346\224\266\350\265\267", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        Motor_Button->setText(QApplication::translate("MainWindow", "\351\201\256\345\205\211\347\275\251", 0, QApplication::UnicodeUTF8));
        LED_Button->setText(QApplication::translate("MainWindow", "LED", 0, QApplication::UnicodeUTF8));
        LED4->setText(QApplication::translate("MainWindow", "\351\227\250\345\217\243", 0, QApplication::UnicodeUTF8));
        LED3->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\256\244", 0, QApplication::UnicodeUTF8));
        LED1->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\256\244", 0, QApplication::UnicodeUTF8));
        LED2->setText(QApplication::translate("MainWindow", "\345\215\253\347\224\237\351\227\264", 0, QApplication::UnicodeUTF8));
        PWM_button->setText(QApplication::translate("MainWindow", "PWM", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\346\271\277\345\272\246", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\344\272\256\345\272\246", 0, QApplication::UnicodeUTF8));
        ray_label->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "\347\272\242\345\244\226", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\350\266\205\345\243\260\346\263\242", 0, QApplication::UnicodeUTF8));
        IntelButton->setText(QApplication::translate("MainWindow", "\344\270\252\344\272\272\346\216\247\345\210\266", 0, QApplication::UnicodeUTF8));
        comButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\345\274\200\345\205\263", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
