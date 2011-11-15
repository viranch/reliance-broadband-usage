#include "reliancebroadband.h"
#include "ui_reliancebroadband.h"

#include <QDebug>
#include <QCalendarWidget>
#include <QMessageBox>
#include <QInputDialog>
#include <QSettings>

RelianceBroadband::RelianceBroadband(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RelianceBroadband)
{
    ui->setupUi(this);
    ui->fromDateEdit->setDate(QDate::currentDate());
    ui->toDateEdit->setDate(QDate::currentDate());
    ui->progressBar->hide();

    firstRun();
}

RelianceBroadband::~RelianceBroadband()
{
    delete ui;
}

void RelianceBroadband::firstRun()
{
    QSettings s;
    if (!s.contains("number"))
        ui->toolButton->click();
}

void RelianceBroadband::on_goBtn_clicked()
{
    QDate fromDate = ui->fromDateEdit->date();
    QDate toDate = ui->toDateEdit->date();
    if (fromDate > toDate) {
        QMessageBox::warning(this, "Invalid Range", "The end date later than the start date.");
        return;
    }

    QString from = fromDate.toString("yyyy-MM-dd");
    QString to = toDate.toString("yyyy-MM-dd");
    QSettings s;
    QString num = s.value("number").toString();
    QString link = "http://myservices.relianceada.com/datausage/jsp/ProcessCDRRequest?Mdn="+num+"&StartDate="+from+"&EndDate="+to+"&ProductType=1&RequestType=Query";
    ui->webView->stop();
    ui->webView->load(QUrl(link));
}

void RelianceBroadband::on_toolButton_clicked()
{
    QSettings s;
    bool ok;
    QString num = QInputDialog::getText(this, "Settings", "Enter your modem number:",
                                        QLineEdit::Normal, s.value("number", QString()).toString(), &ok);
    if (ok && !num.isEmpty()) {
        s.setValue("number", num);
        ui->goBtn->click();
    }
}
