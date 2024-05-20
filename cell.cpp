#include "cell.h"
#include <QPen>


// cell is set to isAlive false
Cell::Cell(QPoint startPoint, int height, bool isAlive)
    : startPoint{startPoint}, m_height{height}, isAlive{isAlive}
{
    this->generation = 1;
    this->neighborCount = 0;

    this->setRect(0, 0, this->height(), this->height());
    this->setBrush(QBrush(Qt::blue));
    this->setPen(QPen(Qt::NoPen));
}


bool Cell::getIsAlive() const
{
    return this->isAlive;
}


void Cell::setIsAlive(bool newIsAlive)
{
    this->isAlive = newIsAlive;
}


void Cell::addNeighbor()
{
    // if neighborCount is 8, it should be a new generation.
    if (this->neighborCount == 8) {
        this->neighborCount = 0;
    } else {
        this->neighborCount += 1;
    }
}


int Cell::getGeneration() const
{
    return this->generation;
}


void Cell::setGeneration(int newGeneration)
{
    this->generation = newGeneration;
}

int Cell::height() const
{
    return this->m_height;
}


void Cell::setHeight(int newHeight)
{
    this->m_height = newHeight;
}
