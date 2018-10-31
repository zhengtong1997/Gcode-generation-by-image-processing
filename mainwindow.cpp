
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <opencv/cv.h>
#include <QTextCodec>
#include <fstream>  
#include <iostream>
#include <QDateTime>
#include <string>  
#include <iostream>  

using namespace std;
#define MAX_CMD_SIZE 96

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //查找可用的串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->PortBox->addItem(serial.portName());
            serial.close();
        }
    }
    //设置波特率下拉菜单默认显示第三项
    ui->BaudBox->setCurrentIndex(3);
    //关闭发送按钮的使能
    ui->sendButton->setEnabled(false);
    qDebug() << tr("jjj");
}
//UI界面
MainWindow::~MainWindow()
{
    delete ui;
}
//打开测试文件
void MainWindow::on_openLenaJpg_triggered()
{
    srcImage = cv::imread("../GcodeCreate\\lena.jpg");
    if(!srcImage.data)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle(tr("警告"));
        msgBox.setText(tr("默认的测试文件不存在，可以用以下两种方式的一种：1）复制一个文件到当前目录下，并命名为lena.jpg. 2)使用自定义方式打开一个自定义文件。"));
        msgBox.exec();
    }
    else
    {
        cv::cvtColor(srcImage,srcImage,CV_BGR2RGB);
        img = QImage((const unsigned char*)(srcImage.data),srcImage.cols,srcImage.rows, srcImage.cols*srcImage.channels(), QImage::Format_RGB888);
        ui->label1->clear();
        img=  img.scaled(ui->label1->width(), ui->label1->height());
        ui->label1->setPixmap(QPixmap::fromImage(img));
        //ui->processPushButton->setEnabled(true);
        //   ui->label1->resize(ui->label1->pixmap()->size());//设置当前标签为图像大小
        // ui->label1->resize(img.width(),img.height());

        //this->setWidget(label1);
    }
}
//退出系统
void MainWindow::on_exitSystem_triggered()
{
    exit(0);
}
//打开自定义文件
void MainWindow::on_openCustomeFile_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open Image"),"",tr("Image File(*.bmp *.jpg *.jpeg *.png)"));
    QTextCodec *code = QTextCodec::codecForName("gb18030");
    std::string name = code->fromUnicode(filename).data();
    srcImage = cv::imread(name);
    if(!srcImage.data)
    {
        QMessageBox msgBox;
        msgBox.setText(tr("未找到数据"));
        msgBox.exec();
    }
    else
    {
        cv::cvtColor(srcImage,srcImage,CV_BGR2RGB);
        img = QImage((const unsigned char*)(srcImage.data),srcImage.cols,srcImage.rows, srcImage.cols*srcImage.channels(), QImage::Format_RGB888);
        ui->label1->clear();
        img=  img.scaled(ui->label1->width(), ui->label1->height());
        ui->label1->setPixmap(QPixmap::fromImage(img));
        //ui->processPushButton->setEnabled(true);
        //   ui->label1->resize(ui->label1->pixmap()->size());//设置当前标签为图像大小
        // ui->label1->resize(img.width(),img.height());

        //this->setWidget(label1);
    }
}
//还原
void MainWindow::on_restoreFile_triggered()
{
    srcImage.copyTo(dstImage);
    img = QImage((const unsigned char*)
                 (dstImage.data),dstImage.cols,dstImage.rows,dstImage.cols*dstImage.channels(),
                 QImage::Format_RGB888);
    img=img.scaled(ui->label1->size());
    ui->label2->setPixmap(QPixmap::fromImage(img));
}
//版权信息
void MainWindow::on_copyright_triggered()
{
    QMessageBox::information(this,"版权",tr("本软件版权所有者为：华中科技大学Focus团队"));
}
//关于软件
void MainWindow::on_about_triggered()
{
    QMessageBox::information(this,"关于",tr("本软件当前版本为2.0，由徐政通开发。如果有问题，欢迎联系：764295748@qq.com"));
    return;
}
//清除图像
void MainWindow::on_Clear_triggered()
{
    //菜单：文件=>清除
    //清除标签1的内容。
    ui->label1->clear();
    //清除标签2的内容。
    ui->label2->clear();
}


void MainWindow::on_GcodeImg_triggered()
{
    cv::resize(srcImage,srcImage,Size(ui->label1->width(), ui->label1->height()),0,0,3);
    //色彩空间转换

    Mat dstImage2=Gcode(srcImage);
    //显示处理结果
    img = QImage((const unsigned char*)(dstImage2.data),dstImage2.cols,dstImage2.rows,dstImage2.step,  QImage::Format_Indexed8);
    //  img=img.scaled(ui->label2->size());  //说明：如果经过canny变换后再调整图像大小，显示时会显示全黑，无法观看。
    ui->label2->setPixmap(QPixmap::fromImage(img));
}

//参数预处理
void MainWindow::on_GcodePram_triggered()
{

}
//打印前预处理
void MainWindow::on_GcodePre_triggered()
{

}


//发送数据


//读取接收到的数据
void MainWindow::Read_Data()
{
   /* QByteArray buf;
    buf = serial->readAll();
    if(!buf.isEmpty())
    {
        QString str = ui->textEdit->toPlainText();
        str+=tr(buf);
        ui->textEdit->clear();
        ui->textEdit->append(str);
    }*/
   
}

void MainWindow::on_openButton_clicked()
{
    //if(ui->openButton->text()==tr("打开串口"))
    {
        serial = new QSerialPort;
        //设置串口名
        serial->setPortName(ui->PortBox->currentText());
        //打开串口
        serial->open(QIODevice::ReadWrite);
        //设置波特率
        serial->setBaudRate(ui->BaudBox->currentText().toInt());
        //设置数据位数
        switch (ui->BitNumBox->currentIndex())
        {
        case 8: serial->setDataBits(QSerialPort::Data8); break;
        default: break;
        }
        //设置奇偶校验
        switch (ui->ParityBox->currentIndex())
        {
        case 0: serial->setParity(QSerialPort::NoParity); break;
        default: break;
        }
        //设置停止位
        switch (ui->StopBox->currentIndex())
        {
        case 1: serial->setStopBits(QSerialPort::OneStop); break;
        case 2: serial->setStopBits(QSerialPort::TwoStop); break;
        default: break;
        }
        //设置流控制
        serial->setFlowControl(QSerialPort::NoFlowControl);

        //关闭设置菜单使能
        ui->PortBox->setEnabled(false);
        ui->BaudBox->setEnabled(false);
        ui->BitNumBox->setEnabled(false);
        ui->ParityBox->setEnabled(false);
        ui->StopBox->setEnabled(false);
        ui->openButton->setText(tr("关闭串口"));
        ui->sendButton->setEnabled(true);

        //连接信号槽
        QObject::connect(serial, &QSerialPort::readyRead, this, &MainWindow::Read_Data);
    }
}
   /* else
    {
        //关闭串口
        serial->clear();
        serial->close();
        serial->deleteLater();

        //恢复设置使能
        ui->PortBox->setEnabled(true);
        ui->BaudBox->setEnabled(true);
        ui->BitNumBox->setEnabled(true);
        ui->ParityBox->setEnabled(true);
        ui->StopBox->setEnabled(true);
        ui->openButton->setText(tr("打开串口"));
        ui->sendButton->setEnabled(false);
    }
}
*/

void MainWindow::on_clearButton_clicked()
{
    ui->textEdit->clear();
}

//发送数据
void MainWindow::on_sendButton_clicked()
{
    serial->write(ui->textEdit_2->toPlainText().toLatin1());
}


void MainWindow::on_pushButton_clicked()//打印按钮
{
	char str_1[] = "ok/n";
	int num = 1;
	QByteArray buf;
	buf = serial->readAll();
    ifstream in("gcode.txt");
	string filename;
	string line;
	char com[3];
	do
	{
		char ch1[] = "";
		_itoa(num, ch1, 10);
		int checksum = 0;
		int count = 0;
		getline(in, line);//获取一行G代码
	QByteArray byte;
	const char* p = line.data();
	 char cmdbuffer[MAX_CMD_SIZE]="N";//加N 即第几行代码
	 char cmdbuffer1[MAX_CMD_SIZE];
	strcat_s(cmdbuffer, 96, ch1);
	strcpy(cmdbuffer1, p);
	strcat_s(cmdbuffer, 96, cmdbuffer1);
	strcat_s(cmdbuffer, 96, "*");
	while (cmdbuffer[count] != '*') checksum = checksum^cmdbuffer[count++];//校验和计算
	int i = checksum;
	cout << i << endl;
	char ch[] = "";
	_itoa(i, ch, 10);
	strcat_s(cmdbuffer, 96, ch);
	strcat_s(cmdbuffer, 96, "\r\n");
	byte = QByteArray(cmdbuffer);
	buf.clear();
	serial->write(byte);//发送G代码
	QString str;
	do
	{
		
		
		msecSleep(1300);//延迟
		buf = serial->readAll();
		str += tr(buf);
		QByteArray ba = str.toLatin1();
		char *cstr = ba.data();
		int n = str.length();

		com[0] = cstr[n - 3];
		com[1] = cstr[n - 2];
		com[2] = cstr[n - 1];
	} while (strcmp(com, str_1) == 0);//判断是否收到ok/n
	
	/*	str += tr(buf);
	}
	while (str.compare("ok") buf.isEmpty());*/
	/*QString str;
	char com[3];
	do
	{
		

		
		msecSleep(400);
		buf = serial->readAll();

		str += tr(buf);
		QByteArray ba = str.toLatin1();
		char *cstr = ba.data();
		int n = str.length();
		
		com[0] = cstr[n - 3];
		com[1] = cstr[n -2];
		com[2] = cstr[n-1];
	} while (strcmp(com,str_1)==0);*/
	
	
	num++;
	}while (1);
	
}
//非阻塞延迟函数
void  MainWindow::msecSleep(int msec)
{
	QTime _Timer = QTime::currentTime().addMSecs(msec);
	while (QTime::currentTime() < _Timer)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
