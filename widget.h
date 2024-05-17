#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "view.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    double scaleFactor;

private slots:
    void on_showGrid_chbx_toggled(bool checked);

    void on_zoomOut_bttn_clicked();

    void on_zoomIn_bttn_clicked();

private:
    Ui::Widget *ui;
    View *view;
};
#endif // WIDGET_H
