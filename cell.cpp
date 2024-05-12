#include "cell.h"

// cell is set to isAlive false
Cell::Cell(QPoint startPoint, int height, bool isAlive)
    : m_startPoint{startPoint}, m_height{height}, m_isAlive{isAlive}
{
    m_generation = 1;
    m_neighborCount = 0;
}


bool Cell::getIsAlive() const
{
    return m_isAlive;
}


void Cell::setIsAlive(bool newIsAlive)
{
    m_isAlive = newIsAlive;
}


void Cell::addNeighbor()
{
    // if neighborCount is 8, it should be a new generation.
    if (m_neighborCount == 8) {
        m_neighborCount = 0;
    } else {
        m_neighborCount += 1;
    }
}


int Cell::getGeneration() const
{
    return m_generation;
}


void Cell::setGeneration(int newGeneration)
{
    m_generation = newGeneration;
}

int Cell::height() const
{
    return m_height;
}


void Cell::setHeight(int newHeight)
{
    m_height = newHeight;
}
