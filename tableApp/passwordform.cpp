#include "passwordform.h"
#include "ui_passwordform.h"
PasswordForm::PasswordForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasswordForm)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->lineEdit->setEchoMode(QLineEdit::Password);
}

PasswordForm::~PasswordForm()
{
    delete ui;
}

void PasswordForm::on_okButton_clicked()
{
    QString pswd = ui->lineEdit->text();
    sendPassword(pswd);
    this->close();
}

void PasswordForm::on_cancelButton_clicked()
{
    emit sendCancel();
    this->close();
}
