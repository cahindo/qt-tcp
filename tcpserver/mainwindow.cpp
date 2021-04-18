#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QTcpServer>
// https://riptutorial.com/qt/example/29874/tcp-server
// https://github.com/manfredipist/QTcpSocket

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Server : Basestation");

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

void MainWindow::on_connectBtn_clicked()
{

}
