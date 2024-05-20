#include "view.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QPainterPath>

View::View(QWidget *parent)
    : QGraphicsView{parent}, drawingSelection{false}, lastRect{nullptr}, showGrid{true}, bkgdColor{Qt::gray}, CELL_SIZE{20}
{}


void View::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "View mouse press at: " << event->pos();
    QGraphicsItem *sceneItem = scene()->itemAt(mapToScene(event->pos()), transform());
    // flags that we are drawing our selection area
    if (!sceneItem) {
        selectTopLeft = event->pos();
        drawingSelection = true;
    }

    QGraphicsView::mousePressEvent(event);
}


void View::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "View mouse moved at: " << event->pos();
    if (drawingSelection) {
        // selection region expands as the mouse moves
        QRectF selectRegion = QRectF(selectTopLeft, event->pos());

        QPainterPath path;
        path.addRect(selectRegion);

        scene()->setSelectionArea(mapToScene(path));
        QGraphicsItem *itemToRemove = lastRect;
        if (itemToRemove != nullptr)
            scene()->removeItem(itemToRemove);
        // draw visual square
        lastRect = scene()->addRect(QRectF(mapToScene(selectTopLeft), mapToScene(event->pos())).normalized());
        // give 50% transparent red
        lastRect->setBrush(QBrush(QColor(255, 0, 0, 50)));
        // dont forget to free up memory
        delete itemToRemove;
    }

    QGraphicsView::mouseMoveEvent(event);
}



void View::mouseReleaseEvent(QMouseEvent *event)
{
    if (drawingSelection) {
        QGraphicsItem *itemToRemove = lastRect;
        if (itemToRemove) {
            scene()->removeItem(itemToRemove);
            delete itemToRemove;
            lastRect = nullptr;
        }
    }

    drawingSelection = false;
    QGraphicsView::mouseReleaseEvent(event);
}



void View::drawBackground(QPainter *painter, const QRectF &rect)
{
    // painter is used by other parts of the app so make sure to save before using...
    painter->save();

    painter->setBrush(QBrush(View::getBkgdColor()));

    painter->drawRect(-800, -400, 1600, 800);

    // and restore painter after using
    painter->restore();
    // parent implimentation will overwrite whats done in here
    //QGraphicsView::drawBackground(painter, rect);
}

void View::drawForeground(QPainter *painter, const QRectF &rect)
{
    if (showGrid) {

        // -800, -400, 1600, 800
        // painter is used by other parts of the app so make sure to save before using...
        painter->save();

        painter->setPen(QColor(100, 100, 100, 50));
        // vertical lines =====
        for (auto i{0}; i < 80; i++) {
            if (i % 10) {
                painter->setPen(QPen(QColor(100, 100, 100, 50), 1));
            } else {
                painter->setPen(QPen(QColor(100, 100, 100, 50), 2));
            }
            painter->drawLine(-800 + (CELL_SIZE * i), -400, -800 + (CELL_SIZE * i), 400);
        }
        // horizontal lines |||
        for (auto i{0}; i < 40; i++) {
            if (i % 10) {
                painter->setPen(QPen(QColor(100, 100, 100, 50), 1));
            } else {
                painter->setPen(QPen(QColor(100, 100, 100, 50), 2));
            }
            painter->drawLine(-800, -400 + (CELL_SIZE * i), 800, -400 + (CELL_SIZE * i));
        }
        // and restore painter after using
        painter->restore();
    } else {
        QGraphicsView::drawForeground(painter, rect);
    }
}

QColor View::getBkgdColor() const
{
    return bkgdColor;
}

void View::setBkgdColor(const QColor &newBkgdColor)
{
    bkgdColor = newBkgdColor;
}

bool View::getShowGrid() const
{
    return showGrid;
}

void View::setShowGrid(bool newShowGrid)
{
    if (showGrid != newShowGrid) {
        showGrid = newShowGrid;
        scene()->update();
    }
}
