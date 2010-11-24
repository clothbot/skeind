#ifndef CUBE3D_H
#define CUBE3D_H

#include <QList>
#include <QTransform>
#include <QVector3D>

class Cube3D {
  public:
    Cube3D();
    Cube3D(qreal dx, qreal dy, qreal dz);
    ~Cube3D();
    void setPos(QVector3D pos);
    void setOrient(QVector3D orient);
    void setTransform(QTransform orient);
    const QVector3D getPos();
    const QVector3D getOrient();
    const QTransform getTransform();
  private:
    qreal length; // dx
    qreal width; // dy
    qreal height; // dz
    QVector3D position;
    QVector3D orientation;
    QTransform transform;
};

#endif
