#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QHostAddress>
// https://riptutorial.com/qt/example/29873/tcp-client
// https://github.com/manfredipist/QTcpSocket

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Client : Robot");

    connect(&socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onReadyRead()
{
    if(socket.waitForConnected()){
        QByteArray toRead = socket.readAll();
        ui->listWidget->addItem(toRead);
    }else{
        socket.close();
    }

}

void MainWindow::on_connectBtn_clicked()
{
    if(socket.waitForConnected()){
        ui->listWidget->addItem("Already Connected");
    }else{
        ui->listWidget->addItem("Connecting..");
        socket.connectToHost(QHostAddress("127.0.0.1"), 4242);
    }

}

void MainWindow::on_sendBtn_clicked()
{
    QString toSent = ui->lineEdit->text();
    socket.write(toSent.toLatin1());
    qDebug()<< "Sending :" << toSent;
}
