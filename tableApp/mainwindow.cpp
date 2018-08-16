#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    headers_ << trUtf8("Name")
             <<trUtf8("Second Name")
             << trUtf8("Email")
             << trUtf8("Age")
             << trUtf8("Children")
             << trUtf8("Likes")
             << trUtf8("Actions");

    ui->table->setColumnCount(7);
    ui->table->setShowGrid(true);//сетка
    ui->table->setSelectionMode(QAbstractItemView::SingleSelection);//выделение отдельной ячейки
     ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);//построчное выделения
    ui->table->horizontalHeader()->setStretchLastSection(true);//увеличение ширины последнего столбца для заполнения пустого пространства
    ui->table->setHorizontalHeaderLabels(headers_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addRowButton_clicked()
{
    ui->table->insertRow(ui->table->rowCount());
    QTableWidgetItem *item = new QTableWidgetItem();
    item->data(Qt::CheckStateRole);
    item->setCheckState(Qt::Unchecked);
    ui->table->setItem(ui->table->rowCount() - 1, 4, item);

    QLabel *label = new QLabel();
    label->setText("<a href=\"http://example.com/\">Click Here!</a>");
    label->setTextFormat(Qt::RichText);
    label->setTextInteractionFlags(Qt::TextBrowserInteraction);
    label->setOpenExternalLinks(true);
    ui->table->setCellWidget(ui->table->rowCount() - 1, 6, label);

}

void MainWindow::on_removeRowButton_clicked()
{
    currentDiscount = ui->table->currentIndex();
    ui->table->removeRow(currentDiscount.row());
}

void MainWindow::on_sendEmailButton_clicked()
{
    currentDiscount = ui->table->currentIndex();
    PasswordForm *form = new PasswordForm();
    connect(form, SIGNAL(sendPassword(QString)), this, SLOT(writeEmail(QString)));
    if(!ui->emaillineEdit->text().isEmpty())
        form->show();
    else
        QMessageBox::warning(this, "Attention!","Please, enter the email address");

}

void MainWindow::sendStatus(QString status)
{
    if(status == "Message sent")
           QMessageBox::warning( 0, tr( "Send status" ), tr( "Message is sent!\n\n" ) );
}

void MainWindow::writeEmail(QString pswd)
{
    smtp_ = new Smtp(ui->table->item(currentDiscount.row(), 2)->text(),//адрес отправителя
                     pswd, //пароль отправителя
                     "smtp.gmail.com"); // сервер

    connect(smtp_, SIGNAL(status(QString)), this, SLOT(sendStatus(QString)));

     smtp_->sendMail(ui->table->item(currentDiscount.row(), 2)->text(),//адрес отправителя
                     ui->emaillineEdit->text(),//адрес получателя
                     (ui->table->item(currentDiscount.row(), 0)->text() + ui->table->item(currentDiscount.row(), 1)->text()),//тема
                     ui->table->item(currentDiscount.row(), 3)->text());
}
