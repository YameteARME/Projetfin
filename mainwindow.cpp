#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);//permet d'etre sur la page de connexion
    ui->lineEdit->setEchoMode(QLineEdit::Password);

    cap.open("http://root:root@192.168.0.101:80/axis-cgi/mjpg/video.cgi"); //Le cap représente un objet de capture vidéo correspondant à un flux vidéo
    cap2.open("http://root:root@192.168.0.103:80/axis-cgi/mjpg/video.cgi");
    cap3.open("http://root:root@192.168.0.106:80/axis-cgi/mjpg/video.cgi");
    cap4.open("http://root:root@192.168.0.107:80/axis-cgi/mjpg/video.cgi");

    if(!cap.isOpened()) //représente un objet de capture vidéo correspondant à un flux vidéo différent
    {
        cout << "camera is not open" << endl;
    }
    else
    {
        cout << "camera is open" << endl;

        connect(timer, SIGNAL(timeout()), this, SLOT(video()));
        connect(timer, SIGNAL(timeout()), this, SLOT(video2()));
        connect(timer, SIGNAL(timeout()), this, SLOT(video3()));
        connect(timer, SIGNAL(timeout()), this, SLOT(video4()));
        timer->start(20);
    }

    connect(ui->pushButton_Barriere1, SIGNAL(clicked()), this, SLOT(OuvertureBarriere1()));
    connect(ui->pushButton_Barriere2, SIGNAL(clicked()), this, SLOT(FermetureBarriere1()));
    connect(ui->pushButton_Barriere3, SIGNAL(clicked()), this, SLOT(OuvertureBarriere2()));
    connect(ui->pushButton_Barriere4, SIGNAL(clicked()), this, SLOT(FermetureBarriere2()));
    connect(ui->pushButton_Barriere5, SIGNAL(clicked()), this, SLOT(FeuVert()));
    connect(ui->pushButton_Barriere6, SIGNAL(clicked()), this, SLOT(FeuRouge()));
    connect(ui->pushButton_Barriere7, SIGNAL(clicked()), this, SLOT(Eclairage()));
    connect(ui->pushButton_Barriere8, SIGNAL(clicked()), this, SLOT(Sirene()));
    connect(ui->pushButton_Barriere9, SIGNAL(clicked()), this, SLOT(Ventilation()));
}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::OuvertureBarriere1()
{


   socket.connectToHost(QHostAddress("192.168.0.105"), 502);
    if(socket.waitForConnected(3000))

    {



        atrame.resize(12);
        atrame[0] = 0x00;
        atrame[1] = 0x00;
        atrame[2] = 0x00;
        atrame[3] = 0x00;
        atrame[4] = 0x00;
        atrame[5] = 0x06;

        atrame[6] = 0x00;
        atrame[7] = 0x06;

        atrame[8] = 0x01;
        atrame[9] = 0x03;

        atrame[10] = 0x00;
        atrame[11] = 0x01;





socket.write(atrame);
qDebug()<<atrame;

    }
}

void MainWindow::FermetureBarriere1()
{

    socket.connectToHost(QHostAddress("192.168.0.105"), 502);

    if(socket.waitForConnected(3000))

    {

atrame.resize(12);
atrame[0] = 0x00;
atrame[1] = 0x00;
atrame[2] = 0x00;
atrame[3] = 0x00;
atrame[4] = 0x00;
atrame[5] = 0x06;

atrame[6] = 0x00;
atrame[7] = 0x06;

atrame[8] = 0x01;
atrame[9] = 0x03;

atrame[10] = 0x00;
atrame[11] = 0x02;


socket.write(atrame);

qDebug()<<atrame;

    }
}

void MainWindow::OuvertureBarriere2()
{

    socket.connectToHost(QHostAddress("192.168.0.105"), 502);

    if(socket.waitForConnected(3000))

    {

atrame.resize(12);
atrame[0] = 0x00;
atrame[1] = 0x00;
atrame[2] = 0x00;
atrame[3] = 0x00;
atrame[4] = 0x00;
atrame[5] = 0x06;

atrame[6] = 0x00;
atrame[7] = 0x06;

atrame[8] = 0x01;
atrame[9] = 0x03;

atrame[10] = 0x00;
atrame[11] = 0x06;


socket.write(atrame);

qDebug()<<atrame;

    }
}

void MainWindow::FermetureBarriere2()
{


    socket.connectToHost(QHostAddress("192.168.0.105"), 502);

    if(socket.waitForConnected(3000))

    {

atrame.resize(12);
atrame[0] = 0x00;
atrame[1] = 0x00;
atrame[2] = 0x00;
atrame[3] = 0x00;
atrame[4] = 0x00;
atrame[5] = 0x06;

atrame[6] = 0x00;
atrame[7] = 0x06;

atrame[8] = 0x01;
atrame[9] = 0x03;

atrame[10] = 0x00;
atrame[11] = 0x08;


socket.write(atrame);

qDebug()<<atrame;

    }
}

void MainWindow::FeuVert()
{

    socket.connectToHost(QHostAddress("192.168.0.105"), 502);

    if(socket.waitForConnected(3000))

    {

atrame.resize(12);
atrame[0] = 0x00;
atrame[1] = 0x00;
atrame[2] = 0x00;
atrame[3] = 0x00;
atrame[4] = 0x00;
atrame[5] = 0x06;

atrame[6] = 0x00;
atrame[7] = 0x06;

atrame[8] = 0x01;
atrame[9] = 0x03;

atrame[10] = 0x00;
atrame[11] = 0x40;


socket.write(atrame);

qDebug()<<atrame;

    }
}

void MainWindow::FeuRouge()
{

    socket.connectToHost(QHostAddress("192.168.0.105"), 502);

    if(socket.waitForConnected(3000))

    {

atrame.resize(12);
atrame[0] = 0x00;
atrame[1] = 0x00;
atrame[2] = 0x00;
atrame[3] = 0x00;
atrame[4] = 0x00;
atrame[5] = 0x06;

atrame[6] = 0x00;
atrame[7] = 0x06;

atrame[8] = 0x01;
atrame[9] = 0x03;

atrame[10] = 0x00;
atrame[11] = 0x80;


socket.write(atrame);

qDebug()<<atrame;

    }
}

void MainWindow::Eclairage()
{


    socket.connectToHost(QHostAddress("192.168.0.105"), 502);

    if(socket.waitForConnected(3000))

    {

atrame.resize(12);
atrame[0] = 0x00;
atrame[1] = 0x00;
atrame[2] = 0x00;
atrame[3] = 0x00;
atrame[4] = 0x00;
atrame[5] = 0x06;

atrame[6] = 0x00;
atrame[7] = 0x06;

atrame[8] = 0x01;
atrame[9] = 0x03;

atrame[10] = 0x01;
atrame[11] = 0x00;


socket.write(atrame);

qDebug()<<atrame;

    }
}

void MainWindow::Sirene()
{

    socket.connectToHost(QHostAddress("192.168.0.105"), 502);

    if(socket.waitForConnected(3000))

    {

atrame.resize(12);
atrame[0] = 0x00;
atrame[1] = 0x00;
atrame[2] = 0x00;
atrame[3] = 0x00;
atrame[4] = 0x00;
atrame[5] = 0x06;

atrame[6] = 0x00;
atrame[7] = 0x06;

atrame[8] = 0x01;
atrame[9] = 0x03;

atrame[10] = 0x04;
atrame[11] = 0x00;

socket.write(atrame);

qDebug()<<atrame;

    }
}

void MainWindow::Ventilation()
{

    socket.connectToHost(QHostAddress("192.168.0.105"), 502);

    if(socket.waitForConnected(3000))

    {

atrame.resize(12);
atrame[0] = 0x00;
atrame[1] = 0x00;
atrame[2] = 0x00;
atrame[3] = 0x00;
atrame[4] = 0x00;
atrame[5] = 0x06;

atrame[6] = 0x00;
atrame[7] = 0x06;

atrame[8] = 0x01;
atrame[9] = 0x03;

atrame[10] = 0x02;
atrame[11] = 0x00;


socket.write(atrame);

qDebug()<<atrame;

    }
}

void MainWindow::on_pushButton_clicked()
{
    if(mdp==ui->lineEdit->text())
    {
    ui->stackedWidget->setCurrentIndex(1); //permet d'etre sur la page de controle
    }
}

void MainWindow::video()
{
    cap >> frame;  //Cette ligne capture une image à partir de la source vidéo spécifiée par l'objet cap et la stocke dans l'objet frame.
    Mat dest; //Ces lignes créent une nouvelle matrice "dest" pour stocker l'image convertie. La fonction "cvtColor" est utilisée pour convertir l'image de l'espace de couleur BGR (Blue-Green-Red) en RGB (Red-Green-Blue).
    cvtColor(frame,dest,COLOR_BGR2RGB);  //Ces lignes créent une nouvelle matrice "dest" pour stocker l'image convertie. La fonction "cvtColor" est utilisée pour convertir l'image de l'espace de couleur BGR (Blue-Green-Red) en RGB (Red-Green-Blue).
    QImage image1  = QImage((uchar*) dest.data,dest.cols,dest.rows,dest.step,QImage::Format_RGB888); //Cette ligne crée un objet QImage à partir des données de la matrice "dest". Les paramètres spécifiés incluent les données de l'image, les dimensions de la matrice et le format de l'image (RGB888).
    ui->camera1->setPixmap(QPixmap::fromImage(image1)); //Cette ligne affecte l'image convertie à un widget d'interface utilisateur nommé "camera1" en utilisant la classe QPixmap. Cela permet d'afficher l'image capturée sur un label dans l'interface
    ui->cam1->setPixmap(QPixmap::fromImage(image1)); //afficher la camera sur un label
    ui->cam1->setScaledContents(true); //Cette ligne permet de redimensionner automatiquement le contenu du label "cam1" pour s'adapter à sa taille.
    ui->cam1->showFullScreen(); //Cette ligne met le label "cam1" en plein écran, ce qui signifie qu'il occupera tout l'écran de l'application.


}

void MainWindow::video2()
{
    cap2 >> frame2;
    Mat dest;
    cvtColor(frame2,dest,COLOR_BGR2RGB);  //change le format bgr en rgb
    QImage image2  = QImage((uchar*) dest.data,dest.cols,dest.rows,dest.step,QImage::Format_RGB888); //transforme l'image en QPixmap
    ui->camera3->setPixmap(QPixmap::fromImage(image2));
    ui->cam3->setPixmap(QPixmap::fromImage(image2));
    ui->cam3->setScaledContents(true);
    ui->cam3->showFullScreen();


}

void MainWindow::video3()
{
    cap3 >> frame3;
    Mat dest;
    cvtColor(frame3,dest,COLOR_BGR2RGB);  //change le format bgr en rgb
    QImage image3  = QImage((uchar*) dest.data,dest.cols,dest.rows,dest.step,QImage::Format_RGB888); //transforme l'image en QPixmap
    ui->camera6->setPixmap(QPixmap::fromImage(image3));
    ui->cam6->setPixmap(QPixmap::fromImage(image3));
    ui->cam6->setScaledContents(true);
    ui->cam6->showFullScreen();


}

void MainWindow::video4()
{
    cap4 >> frame4;
    Mat dest;
    cvtColor(frame4,dest,COLOR_BGR2RGB);  //change le format bgr en rgb
    QImage image4  = QImage((uchar*) dest.data,dest.cols,dest.rows,dest.step,QImage::Format_RGB888); //transforme l'image en QPixmap
    ui->camera7->setPixmap(QPixmap::fromImage(image4));
    ui->cam7->setPixmap(QPixmap::fromImage(image4));
    ui->cam7->setScaledContents(true);
    ui->cam7->showFullScreen();


}





void MainWindow::on_pushButton_4_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);  //permet de définir l'indice de la page actuellement affichée
}


void MainWindow::on_retour1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_retour2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_retour3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_retour4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

