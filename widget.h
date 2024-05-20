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

    void on_start_bttn_clicked();

    void on_next_bttn_clicked();

    void on_edit_chbx_toggled(bool checked);

    void on_reset_bttn_clicked();

    void on_simSpeed_sldr_valueChanged(int value);

    void on_help_bttn_clicked();



private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    View *view;
    bool isRunning;
    bool editEnabled;
};
#endif // WIDGET_H
