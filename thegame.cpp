#include "thegame.h"
#include <QDebug>


TheGame::TheGame(QObject *parent)
    : QObject{parent}
{

}


long TheGame::getGenerations() const
{
    return generations;
}


void TheGame::setGenerations(long newGenerations)
{
    generations = newGenerations;
}


bool TheGame::checkNeighbor(bool isAlive)
{
    return (isAlive) ? this->checkLiveCell() : this->checkDeadCell();
}


int TheGame::getNeighborCount(Cell cell, bool isAlive)
{

}


bool TheGame::checkLiveCell()
{

}


bool TheGame::checkDeadCell()
{

}
