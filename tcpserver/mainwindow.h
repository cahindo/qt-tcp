#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer *timer;
    QString toSent;
    QString com;

public slots:
    void onReadyRead();
    void onNewConnection();
    void send();
private slots:
    void on_sendBtn_clicked();
    void on_connectBtn_clicked();

    void on_qb_clicked();

    void on_wb_clicked();

    void on_eb_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QTcpServer server;
};

#endif // MAINWINDOW_H
