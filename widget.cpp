#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    setWindowIcon(QIcon(":/socurce/icon.png"));
    QPixmap icon(":/socurce/icon.png");
    ui->Icon->setScaledContents(true);
    ui->Icon->setPixmap(icon);
    ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

Widget::~Widget()
{
    delete ui;
}

