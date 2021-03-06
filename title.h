#ifndef TITLE_H
#define TITLE_H

#include <QPoint>
#include <QPushButton>
#include <QWidget>

namespace Ui {
class title;
}

class title : public QWidget
{
    Q_OBJECT

public:
    explicit title(QWidget *parent = nullptr);
    ~title();

private slots:

    void on_min_button_clicked();

    void on_exit_button_clicked();

protected:
    // 进行鼠界面的拖动
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
private:
    Ui::title *ui;
    QPushButton* m_minimizeButton;
    QPushButton* m_maximizeButton;
    QPushButton* m_closeButton;
    QPoint m_start;//起始点
    QPoint m_end;//结束点
    bool m_leftButtonPressed;//鼠标左键按下标记
};

#endif // TITLE_H
