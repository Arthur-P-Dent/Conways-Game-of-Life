#ifndef CELL_H
#define CELL_H

#include <QObject>
#include <QRect>

class Cell : public QObject
{
    Q_OBJECT
public:
    explicit Cell(QObject *parent = nullptr);
    ~Cell();

    bool getIsAlive() const;
    void setIsAlive(bool newIsAlive);

private:
    int width;
    int height;
    QPoint startPoint;
    bool isAlive;

signals:
};

#endif // CELL_H
