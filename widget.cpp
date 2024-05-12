#include "widget.h"
#include "./ui_widget.h"
#include "thegame.h"
#include "cell.h"
#include <QGraphicsView>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    TheGame *game = new TheGame(this);

    Cell *cell = new Cell(QPoint(0, 0), 20, true);
    QGraphicsScene *scene = new QGraphicsScene(this);
    cell->setRect(0, 0, cell->height(), cell->height());
    cell->setBrush(QBrush(Qt::blue));
    cell->setPen(QPen(Qt::black, 2));
    scene->addItem(cell);

    ui->graphicsView->setScene(scene);

}

Widget::~Widget()
{
    delete ui;
}
