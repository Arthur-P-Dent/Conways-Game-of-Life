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
    QPoint m_startPoint;
    bool m_isAlive;
    bool m_shouldDie;
    int m_generation;
    int m_neighborCount;

};

#endif // CELL_H
