#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onReadyRead();
    void onNewConnection();
private slots:
    void on_sendBtn_clicked();
    void on_connectBtn_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QTcpServer server;
};

#endif // MAINWINDOW_H
