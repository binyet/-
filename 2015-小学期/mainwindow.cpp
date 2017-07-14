#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new SerialCom();
    motor = new Motor();
    thl = new T_H_L();
    ray = new Ray();
    ultra = new Ultra();
    motor_timer = new QTimer();
    LedState[0] = 0;
    LedState[1] = 0;
    LedState[2] = 0;
    LedState[3] = 0;
    motorstate = 0;
    led_but_state = 0;
    thl_but_state = 0;
    intel_state = 0;
    ismotoropen = 0;
    ui->Motor_widget->hide();
    ui->LED_widget->hide();
    ui->serial_widget->hide();
    ui->thl_widget->hide();

    ui->hour_lcd->setNumDigits(8);
    QTimer *tm = new QTimer(this);
    connect(tm,SIGNAL(timeout()),this,SLOT(showTime()));
    tm->start(500);
    connect(motor_timer,SIGNAL(timeout()),this,SLOT(test()));
    connect(this, SIGNAL(addLog(QString)), this, SLOT(showLog(QString)));
    connect(this->serial,SIGNAL(receiveMsgFromSerial(QByteArray)),this,SLOT(process(QByteArray)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showLog(QString log)
{
    ui->ComBrowser->append(log);
}


void MainWindow::on_comButton_clicked()
{
    changeCom(serial->getComState());
}

void MainWindow::changeCom(int state)
{
    //开启端口
    if(state == 1){
        if(serial->closeCom()){
            ui->serial_widget->hide();
            ui->comButton->setText("open");
            ui->comButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
            emit addLog("close success!");
        }
        else
            emit addLog("close failed!");
    }
    else if(state == 0){
        if(serial->openCom()){
            ui->serial_widget->show();
            ui->comButton->setText("close");
            ui->comButton->setStyleSheet(BACKGROUND_COLOR_GREEN);
            emit addLog("open success!");
        }
        else
            emit addLog("open close!");
    }
}


void MainWindow::on_forwardButton_clicked()
{
//电机正转

    ui->IntelButton->setText("person");
    ui->IntelButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
    intel_state = 0;
    if(serial->writeToSerial(Motor::TURN_FORWARD) == -1){
        emit addLog("forward turn failed!");
        return ;
    }
    motor->setState(1);
    ui->forwardButton->setStyleSheet(BACKGROUND_COLOR_GREEN);
    ui->reversalButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
    ui->stopButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
    emit addLog("forward turn success!");
}

void MainWindow::on_reversalButton_clicked()
{//电机反转

    ui->IntelButton->setText("person");
    ui->IntelButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
    intel_state = 0;
    if(serial->writeToSerial(Motor::TURN_REVERSAL) == -1){
        emit addLog("reversal turn failed!");
        return ;
    }
    motor->setState(2);
    ui->reversalButton->setStyleSheet(BACKGROUND_COLOR_GREEN);
    ui->forwardButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
    ui->stopButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
    emit addLog("reserval turn success!");
}

void MainWindow::on_stopButton_clicked()
{//电机停转

    ui->IntelButton->setText("person");
    ui->IntelButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
    intel_state = 0;
    if(serial->writeToSerial(Motor::TURN_STOP) == -1){
        emit addLog("stop turn failed!");
        return ;
    }
    motor->setState(0);
    ui->stopButton->setStyleSheet(BACKGROUND_COLOR_GREEN);
    ui->forwardButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
    ui->reversalButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
    emit addLog("stop turn success!");
}

void MainWindow::getThl(){
    //获取温湿度光照
    ui->lcd_temp->display(thl->getTemp());
    ui->lcd_humi->display(thl->getHumi());
    ui->lcd_light->display(QString::number(thl->getLight(),'f',1));
    //根据亮度打开关闭pwm

    if(thl->getLight() < 450){
        serial->writeToSerial(Pwm::MSG_PWM);
        ui->PWM_button->setStyleSheet(BACKGROUND_COLOR_GREEN);
    }
    else if(thl->getLight() > 550 ){
        serial->writeToSerial(Pwm::RANGE);
        ui->PWM_button->setStyleSheet(BACKGROUND_COLOR_WHITE);
    }

}

void MainWindow::process(QByteArray msg){

    if(msg.length() < 6)
        return ;
    //温湿度事件
    if(msg[3] == 0x02 && msg[4] == 0x01){
        thl->setValue(msg);
        getThl();
    }
    //热释红外事件,2灯表示是否有人
    else if(msg[3] == 0x05 && msg[4] == 0x01)
    {
        if(msg[5] == 0x01)
        {
            ray->setState(1);
            //ui->ray_label->setPalette(pe_red);
            ui->ray_label->setText("light");
            ui->ray_label->setStyleSheet(BACKGROUND_COLOR_GREEN);
            serial->writeToSerial(Motor::OPEN_LED2);
            ui->LED2->setStyleSheet(BACKGROUND_COLOR_GREEN);
            LedState[1] = 1;//检测到有人时自动亮灯
        }
        else if(msg[5] == 0x00)
        {
            ray->setState(0);
            //ui->ray_label->setPalette(pe_black);
            ui->ray_label->setText("nobody");
            ui->ray_label->setStyleSheet(BACKGROUND_COLOR_WHITE);
            serial->writeToSerial(Motor::CLOSE_LED2);
            ui->LED2->setStyleSheet(BACKGROUND_COLOR_WHITE);
        }
    }
    //超声波事件,4灯表示门是否关闭
    else if(msg[3] == 0x08 && msg[4] == 0x01)
    {
        int len = msg[5] * 256 + msg[6];
        ui->label_ultra->display(QString::number(len));
        ultra->setState(len);
        if(len < 1000){
            serial->writeToSerial(Motor::OPEN_LED4);
            ui->LED4->setStyleSheet(BACKGROUND_COLOR_RED);
            LedState[3] = 1;
        }
        else{
            serial->writeToSerial(Motor::CLOSE_LED4);
            ui->LED4->setStyleSheet(BACKGROUND_COLOR_GREEN);
            LedState[3] = 0;
        }
    }
    //emit addLog(msg.toHex());
}

void MainWindow::on_LED1_clicked()
{//LED1按钮,模拟客厅灯

    ui->IntelButton->setText("person");
    ui->IntelButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
    intel_state = 0;
    if(LedState[0] == 0){
        if(serial->writeToSerial(Motor::OPEN_LED1) == -1){
            emit addLog("open LED1 failed!");
            return ;
        }
        else{
            emit addLog("open LED1 success!");
            ui->LED1->setStyleSheet(BACKGROUND_COLOR_GREEN);
            LedState[0] = 1;

        }
    }
    else if(LedState[0] ==1 ){
        if(serial->writeToSerial(Motor::CLOSE_LED1) == -1){
            emit addLog("close LED1 failed!");
            return ;
        }
        else{
            emit addLog("close LED1 success!");
            ui->LED1->setStyleSheet(BACKGROUND_COLOR_WHITE);
            LedState[0] = 0;
        }
    }
}

void MainWindow::on_LED2_clicked()
{//LED2按钮

    ui->IntelButton->setText("person");
    ui->IntelButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
    intel_state = 0;
    if(LedState[1] == 0){
        if(serial->writeToSerial(Motor::OPEN_LED2) == -1){
            emit addLog("open LED2 failed!");
            return ;
        }
        else{
            emit addLog("open LED2 success!");
            ui->LED2->setStyleSheet(BACKGROUND_COLOR_GREEN);
            LedState[1] = 1;
        }
    }
    else if(LedState[1] ==1 ){
        if(serial->writeToSerial(Motor::CLOSE_LED2) == -1){
            emit addLog("close LED2 failed!");
            return ;
        }
        else{
            emit addLog("close LED2 success!");
            ui->LED2->setStyleSheet(BACKGROUND_COLOR_WHITE);
            LedState[1] = 0;

        }
    }
}

void MainWindow::on_LED3_clicked()
{//LED3按钮

    ui->IntelButton->setText("person");
    ui->IntelButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
    intel_state = 0;
    if(LedState[2] == 0){
        if(serial->writeToSerial(Motor::OPEN_LED3) == -1){
            emit addLog("open LED3 failed!");
            return ;
        }
        else{
            emit addLog("open LED3 success!");
            ui->LED3->setStyleSheet(BACKGROUND_COLOR_GREEN);
            LedState[2] = 1;
        }

    }
    else if(LedState[2] ==1 ){
        if(serial->writeToSerial(Motor::CLOSE_LED3) == -1){
            emit addLog("close LED3 failed!");
            return ;
        }else{
            emit addLog("close LED3 success!");
            ui->LED3->setStyleSheet(BACKGROUND_COLOR_WHITE);
            LedState[2] = 0;

        }
    }
}

void MainWindow::on_LED4_clicked()
{//LED4按钮

    ui->IntelButton->setText("person");
    ui->IntelButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
    intel_state = 0;
    if(LedState[3] == 0){
        if(serial->writeToSerial(Motor::OPEN_LED4) == -1){
            emit addLog("open LED4 failed!");
            return ;
        }
        else{
            emit addLog("open LED4 success!");
            ui->LED4->setStyleSheet(BACKGROUND_COLOR_GREEN);
            LedState[3] = 1;
        }
    }
    else if(LedState[3] ==1 ){
        if(serial->writeToSerial(Motor::CLOSE_LED4) == -1){
            emit addLog("close LED4 failed!");
            return ;
        }else{
            emit addLog("close LED4 success!");
            ui->LED4->setStyleSheet(BACKGROUND_COLOR_WHITE);
            LedState[3] = 0;
        }
    }
}

void MainWindow::on_Motor_Button_clicked()
{//电机按钮
    if(motorstate == 1){
        ui->Motor_widget->hide();
        motorstate = 0;
        ui->Motor_Button->setStyleSheet(BACKGROUND_COLOR_WHITE);
    }
    else if(motorstate == 0){
        ui->Motor_widget->show();
        ui->Motor_Button->setStyleSheet(BACKGROUND_COLOR_GREEN);
        motorstate =1;
    }
}

void MainWindow::on_LED_Button_clicked()
{//LED按钮
    if(led_but_state == 0){
        ui->LED_widget->show();
        ui->LED_Button->setStyleSheet(BACKGROUND_COLOR_GREEN);
        led_but_state = 1;
    }
    else if(led_but_state == 1){
        ui->LED_widget->hide();
        ui->LED_Button->setStyleSheet(BACKGROUND_COLOR_WHITE);
        led_but_state = 0;
    }
}

void MainWindow::on_thlButton_clicked()
{//温湿度按钮
    if(thl_but_state == 0){
        ui->thl_widget->show();
        ui->thlButton->setStyleSheet(BACKGROUND_COLOR_GREEN);
        thl_but_state = 1;
    }
    else if(thl_but_state == 1){
        ui->thl_widget->hide();
        ui->thlButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
        thl_but_state = 0;
    }
}

void MainWindow::showTime(){
    QTime qtm = QTime::currentTime();
    QString str = qtm.toString("hh:mm:ss");
    str = str.left(str.length());
    ui->hour_lcd->display(str);
    //ui->ComBrowser->append(str);
    str = str.left(str.length()-6);
    ui->testlcd->display(str);
    int b = str.toInt();
    QTime t;
    if((b > 19|| b < 6)&&intel_state == 1 && ismotoropen == 0){

//        t.start();
//        while(t.elapsed() < 3000){
//            on_forwardButton_clicked();
//        }
//        on_stopButton_clicked();
        if(motor_timer == NULL){
            motor_timer = new QTimer();
        }
        motor_timer->start(3000);
        serial->writeToSerial(Motor::TURN_FORWARD);
        ui->forwardButton->setStyleSheet(BACKGROUND_COLOR_GREEN);
        ui->reversalButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
        ui->stopButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
        ismotoropen = 1;//表示大棚已经降下
    }
    else if((b > 5 && b < 20 ) && intel_state == 1 && ismotoropen == 1){

        if(motor_timer == NULL){
            motor_timer = new QTimer();
        }
        motor_timer->start(3000);
        serial->writeToSerial(Motor::TURN_REVERSAL);
        ui->forwardButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
        ui->reversalButton->setStyleSheet(BACKGROUND_COLOR_GREEN);
        ui->stopButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
        ismotoropen = 0;//表示大棚已经升起
    }


}



void MainWindow::on_IntelButton_clicked()
{
    if(intel_state == 0){
        ui->IntelButton->setText("intel");
        ui->IntelButton->setStyleSheet(BACKGROUND_COLOR_GREEN);
        intel_state = 1;
    }
    else{
        ui->IntelButton->setText("person");
        ui->IntelButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
        intel_state = 0;
    }
}


void MainWindow::test(){
    if(intel_state == 1){
        serial->writeToSerial(Motor::TURN_STOP);
        ui->stopButton->setStyleSheet(BACKGROUND_COLOR_GREEN);
        ui->forwardButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
        ui->reversalButton->setStyleSheet(BACKGROUND_COLOR_WHITE);
        motor->setState(0);
        motor_timer = NULL;
        delete(motor_timer);
    }

}


void MainWindow::on_lcd_temp_overflow()
{

}
