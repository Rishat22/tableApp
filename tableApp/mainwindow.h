#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QTableWidget>
#include <QComboBox>
#include <QLabel>
#include <QMessageBox>
#include "smtp.h"
#include "passwordform.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addRowButton_clicked();

    void on_removeRowButton_clicked();

    void on_sendEmailButton_clicked();

    void sendStatus(QString status);

public slots:
    void writeEmail(QString pswd);

private:
    Ui::MainWindow *ui;
    QStringList headers_;
    Smtp *smtp_;
    QModelIndex currentDiscount;
};

#endif // MAINWINDOW_H
