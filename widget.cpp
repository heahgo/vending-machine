#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    ui->pbCoffee->setEnabled(true);
    ui->pbMilk->setEnabled(true);
    ui->pbMango->setEnabled(true);

    if (money + diff < 100)
        ui->pbCoffee->setEnabled(false);
    if (money + diff < 300)
        ui->pbMilk->setEnabled(false);
    if (money + diff < 500)
        ui->pbMango->setEnabled(false);

    money += diff;
    ui->lcdNumber->display(money);


}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-300);
}

void Widget::on_pbMango_clicked()
{
    changeMoney(-500);
}

void Widget::on_pbReset_clicked()
{
    char str[100] = {0, };
    char tmp[20] = {0, };

    strcat(str, "500 : ");
    sprintf(tmp, "%d", money / 500);
    strcat(str, tmp);
    strcat(str, " \n");
    money %= 500;

    strcat(str, "100 : ");
    sprintf(tmp, "%d", money / 100);
    strcat(str, tmp);
    strcat(str, " \n");
    money %= 100;

    strcat(str, "50 : ");
    sprintf(tmp, "%d", money / 50);
    strcat(str, tmp);
    strcat(str, " \n");
    money %= 50;

    strcat(str, "10 : ");
    sprintf(tmp, "%d", money / 10);
    strcat(str, tmp);
    strcat(str, " \n");
    money %= 10;

    QMessageBox msg;
    msg.information(nullptr, "title", str);
    ui->lcdNumber->display(money);
}

