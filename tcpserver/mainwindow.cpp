#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QTcpServer>

// https://riptutorial.com/qt/example/29874/tcp-server
// https://github.com/manfredipist/QTcpSocket
// https://doc.qt.io/archives/qt-4.8/qt-network-loopback-example.html

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Server : Basestation");
    com = "-";

    server.listen(QHostAddress::Any, 4242);
    connect(&server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewConnection()
{
   ui->listWidget->addItem("New Connection Detected !");

   socket =  server.nextPendingConnection();
   connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
//   connect(clientSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));

   socket->write(QByteArray::fromStdString(socket->peerAddress().toString().toStdString() + " Connected to server !\n"));

   timer = new QTimer(this);
   connect(timer, SIGNAL(timeout()), this, SLOT(send()));
   timer->start(50);

//   connect(socket, SIGNAL(connected()), this, SLOT(send()));


}

void MainWindow::onReadyRead()
{
    if(socket->waitForConnected()){
        QByteArray datas = socket->readAll();
        ui->listWidget->addItem(datas);
    }
//    else{
//        socket->close();
//        ui->pushButton->click();
//    }

}

void MainWindow::on_sendBtn_clicked()
{
    QString toSent = ui->lineEdit->text();
    socket->write(toSent.toLatin1());
    qDebug()<< "Sending : " << toSent;

}

void MainWindow::send(){
    toSent = com;
    qDebug()<< "Sending : " << toSent;
    socket->write(toSent.toLatin1());

}

void MainWindow::on_connectBtn_clicked()
{

}

void MainWindow::on_qb_clicked()
{
    com = "Q";
}

void MainWindow::on_wb_clicked()
{
    com = "W";
}

void MainWindow::on_eb_clicked()
{
    com = "E";
}
