#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <image_gcode.h>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>


namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    cv::Mat srcImage,dstImage,tempImage;
         QImage img;

private slots:
         void on_openLenaJpg_triggered();

         void on_exitSystem_triggered();

         void on_openCustomeFile_triggered();

         void on_restoreFile_triggered();

         void on_copyright_triggered();

         void on_about_triggered();

         void on_Clear_triggered();

         void on_GcodeImg_triggered();

         void on_GcodePram_triggered();

         void on_GcodePre_triggered();
         void on_clearButton_clicked();

         void on_sendButton_clicked();

         void on_openButton_clicked();
      

         void Read_Data();
		 
		 
			 void on_pushButton_clicked();
		 void msecSleep(int msec);

private:
    Ui::MainWindow *ui;
     QSerialPort *serial;
};

#endif // MAINWINDOW_H
