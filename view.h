#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
class View : public QGraphicsView
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);

    bool getShowGrid() const;
    void setShowGrid(bool newShowGrid);

    QColor getBkgdColor() const;
    void setBkgdColor(const QColor &newBkgdColor);

signals:

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    // background and grid
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void drawForeground(QPainter *painter, const QRectF &rect) override;

private:
    QPoint selectTopLeft;
    bool drawingSelection;
    QGraphicsRectItem *lastRect;
    bool showGrid;
    QColor bkgdColor;
    int CELL_SIZE;

};

#endif // VIEW_H
