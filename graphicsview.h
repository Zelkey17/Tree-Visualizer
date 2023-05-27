#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>


class GraphicsView : public QGraphicsView {
Q_OBJECT
public:
    explicit GraphicsView(QWidget *parent = nullptr);

    void toDefault();

private:

    double scale_;

    void scrollContentsBy(int, int) override;

    void wheelEvent(QWheelEvent *) override;

    void mousePressEvent(QMouseEvent *event) override;

signals:

    void mousePressed(int x, int y);

};

#endif // GRAPHICSVIEW_H
