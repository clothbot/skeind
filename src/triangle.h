#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QVector3D>
#include <QList>

class Triangle {
 public:
  Triangle(QVector3D pt1, QVector3D pt2, QVector3D pt3);
  Triangle(QVector3D pt1, QVector3D pt2, QVector3D pt3, QVector3D norm);
  ~Triangle();
  QVector3D getNormal();
  qreal getArea();
  QList<QVector3D> getBBox();

 private:
  QVector3D point[3];
//  QVector3D normal;

};
#endif

