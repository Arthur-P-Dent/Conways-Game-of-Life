#include "widget.h"
#include "./ui_widget.h"
#include "thegame.h"
#include "cell.h"
#include <QGraphicsView>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget), scaleFactor{1.1}
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(-800, -400, 1600, 800);
    TheGame *game = new TheGame(this);

    Cell *cell = new Cell(QPoint(0, 0), 20, true);
    cell->setRect(0, 0, cell->height(), cell->height());
    cell->setBrush(QBrush(Qt::blue));
    cell->setPen(QPen(Qt::black, 2));

    view = new View(this);
    //scene->addItem(cell);
    view->setScene(scene);

    ui->viewLayout->addWidget(view);
    ui->showGrid_chbx->setChecked(view->getShowGrid());

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_showGrid_chbx_toggled(bool checked)
{
    view->setShowGrid(checked);
}


void Widget::on_zoomOut_bttn_clicked()
{
    view->scale(1/scaleFactor, 1/scaleFactor);
}


void Widget::on_zoomIn_bttn_clicked()
{
    view->scale(scaleFactor, scaleFactor);
}

