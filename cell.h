#ifndef CELL_H
#define CELL_H

#include <QObject>
#include <QGraphicsRectItem>

class Cell : public QGraphicsRectItem
{

public:
    explicit Cell(QPoint startPoint, int height, bool isAlive = false);

    bool getIsAlive() const;
    void setIsAlive(bool newIsAlive);
    void addNeighbor();

    int getGeneration() const;
    void setGeneration(int newGeneration);

    int height() const;
    void setHeight(int newHeight);

private:
    int m_height;
    QPoint startPoint;
    bool isAlive;
    bool shouldDie;
    int generation;
    int neighborCount;

};

#endif // CELL_H
