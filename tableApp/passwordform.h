#ifndef PASSWORDFORM_H
#define PASSWORDFORM_H

#include <QWidget>

namespace Ui {
class PasswordForm;
}

class PasswordForm : public QWidget
{
    Q_OBJECT

public:
    explicit PasswordForm(QWidget *parent = 0);
    ~PasswordForm();

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::PasswordForm *ui;

signals:
    void sendPassword(QString pswd);
    void sendCancel();
};

#endif // PASSWORDFORM_H
