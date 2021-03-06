#include "title.h"
#include "ui_title.h"

#include <QMouseEvent>

title::title(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::title)
{
    ui->setupUi(this);
    ui->exit_button->setFlat(1);
    ui->min_button->setFlat(1);
    ui->max_button->setFlat(1);
    ui->max_button->hide();
}

title::~title()
{
    delete ui;
}



void title::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        {
            // 记录鼠标左键状态
            m_leftButtonPressed = true;
            //记录鼠标在屏幕中的位置
            m_start = event->globalPos();
}

}

void title::mouseMoveEvent(QMouseEvent *event)
{
    if(m_leftButtonPressed)
        {
            //将父窗体移动到父窗体原来的位置加上鼠标移动的位置：event->globalPos()-m_start
            parentWidget()->move(parentWidget()->geometry().topLeft() +
                                 event->globalPos() - m_start);
            //将鼠标在屏幕中的位置替换为新的位置
            m_start = event->globalPos();
        }
}

void title::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
       {
           // 记录鼠标状态
           m_leftButtonPressed = false;
       }
}



void title::on_min_button_clicked()
{
    this->parentWidget()->showMinimized();
}

void title::on_exit_button_clicked()
{
    this->parentWidget()->close();
}
