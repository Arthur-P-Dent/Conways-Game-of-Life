#include "widget.h"
#include "./ui_widget.h"
#include "thegame.h"
#include "cell.h"
#include <QGraphicsView>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget), scaleFactor{1.1}, isRunning{false}, editEnabled{false}
{
    ui->setupUi(this);
    setWindowTitle("Conway's Game of Life");

    ui->genCounter_lcdn->setPalette(QPalette(QColor(51, 255, 51, 150)));

    scene = new QGraphicsScene(this);
    scene->setSceneRect(-800, -400, 1600, 800);
    TheGame *game = new TheGame(this);

    Cell *cell = new Cell(QPoint(0, 0), 20, true);


    view = new View(this);

    scene->addItem(cell);
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


void Widget::on_start_bttn_clicked()
{
    if (isRunning) {
        // simulation is currently running
        isRunning = false;
        ui->start_bttn->setText("Start");
        // stopSimulation()
    } else {
        // if simulation isn't running
        isRunning = true;
        ui->start_bttn->setText("Stop");
        // runSimulation();
    }
}


void Widget::on_next_bttn_clicked()
{

}


void Widget::on_reset_bttn_clicked()
{

}


void Widget::on_edit_chbx_toggled(bool checked)
{
    if (checked) {
        editEnabled = false;
    } else {
        editEnabled = true;
    }
}


void Widget::on_simSpeed_sldr_valueChanged(int value)
{

}


void Widget::on_help_bttn_clicked()
{
    // bring up help menu

}




