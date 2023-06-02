#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QPushButton>

#include <QTimer>
#include <QImage>
#include <QDialog>
#include <QTcpSocket>
#include <QByteArray>
#include <QNetworkProxy>
#include <QPixmap>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
#include <iostream>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
QByteArray atrame;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void OuvertureBarriere1();
    void FermetureBarriere1();
    void OuvertureBarriere2();
    void FermetureBarriere2();
    void FeuVert();
    void FeuRouge();
    void Eclairage();
    void Ventilation();
    void Sirene();

void on_pushButton_clicked();

    void video();
    void video2();
    void video3();
    void video4();
    void on_pushButton_4_clicked();

    void on_retour1_clicked();

    void on_pushButton_5_clicked();

    void on_retour2_clicked();

    void on_pushButton_2_clicked();

    void on_retour3_clicked();

    void on_pushButton_3_clicked();

    void on_retour4_clicked();

private:
    Ui::MainWindow *ui;

    QString mdp="ok";
    QTcpSocket  socket;
    quint64 ancienOctet;
    quint64 hexa;
    QNetworkProxy proxy;

    VideoCapture cap,cap2,cap3,cap4; //déclarent quatre objets
    Mat frame,frame2,frame3,frame4;// permet stocker des images ou des vidéos sous forme de matrices.
    QTimer *timer = new QTimer;
    QImage *qt_image = new QImage;
};
#endif // MAINWINDOW_H
