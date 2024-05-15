#ifndef THEGAME_H
#define THEGAME_H

#include <QObject>
#include "cell.h"

class TheGame : public QObject
{
    Q_OBJECT
public:
    explicit TheGame(QObject *parent = nullptr);

    long getGenerations() const;
    void setGenerations(long newGenerations);
    bool checkNeighbor(bool isAlive);
    int getNeighborCount(Cell cell, bool isAlive);


private:
    QVector<QVector<Cell *>> cellGrid;
    long int generations;
    long int screenSize;

    bool checkLiveCell();
    bool checkDeadCell();


signals:
};

#endif // THEGAME_H
