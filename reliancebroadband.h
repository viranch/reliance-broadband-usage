#ifndef RELIANCEBROADBAND_H
#define RELIANCEBROADBAND_H

#include <QDialog>
#include <QDate>

namespace Ui {
    class RelianceBroadband;
}

class RelianceBroadband : public QDialog
{
    Q_OBJECT

public:
    explicit RelianceBroadband(QWidget *parent = 0);
    ~RelianceBroadband();

private slots:
    void on_goBtn_clicked();

    void on_toolButton_clicked();

private:
    Ui::RelianceBroadband *ui;

    void firstRun();
};

#endif // RELIANCEBROADBAND_H
