#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include "posix_qextserialport.h"
#include <QPushButton>
#include "serialcom.h"
#include "enddevice.h"
#include "motor.h"
#include "t_h_l.h"
#include <QDateTime>
#include <QTimer>
#include <QTime>
#include "ray.h"
#include "ultra.h"
#include "pwm.h"


#define BACKGROUND_COLOR_WHITE "background-color:rgb(255,255,255)"
#define BACKGROUND_COLOR_GREEN "background-color:rgb(0,255,0)"
#define BACKGROUND_COLOR_RED "background-color:rgb(255,0,0)"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void changeCom(int);

    void getThl();

    int LedState[4];

    int motorstate;

    int led_but_state;

    int thl_but_state;

    int intel_state;

    int ismotoropen;

    void OPENLED();
signals:
    void addLog(QString);
    
private slots:
    void on_comButton_clicked();
    void showLog(QString);

    void on_forwardButton_clicked();

    void on_reversalButton_clicked();

    void on_stopButton_clicked();

    void process(QByteArray);
    void on_LED1_clicked();

    void on_LED2_clicked();

    void on_LED3_clicked();

    void on_LED4_clicked();

    void on_Motor_Button_clicked();

    void on_LED_Button_clicked();

    void on_thlButton_clicked();

    void showTime();

    void on_IntelButton_clicked();
    void test();

    void on_lcd_temp_overflow();

private:
    Ui::MainWindow *ui;
    Posix_QextSerialPort *theCom;
    SerialCom *serial;
    Motor *motor;
    T_H_L *thl;
    Ray *ray;
    Ultra *ultra;
    QTimer *motor_timer;
    Pwm *pwm;
};

#endif // MAINWINDOW_H
