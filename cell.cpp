#include "cell.h"


Cell::Cell(QObject *parent) : QObject{parent}
{

}


bool Cell::getIsAlive() const
{
    return isAlive;
}


void Cell::setIsAlive(bool newIsAlive)
{
    isAlive = newIsAlive;
}
