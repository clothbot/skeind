#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QVector3D>
#include <QList>
#include "line3d.h"

class Triangle {
 public:
  Triangle(QVector3D inpt1, QVector3D inpt2, QVector3D inpt3);
  Triangle(QVector3D inpt1, QVector3D inpt2, QVector3D inpt3, QVector3D norm);
  ~Triangle();
  QVector3D calculateNormal();
  bool isValid();
  qreal calculate2DArea();
  Line3D calculate3DBCube();
  QVector3D& getPt1();
  QVector3D& getPt2();
  QVector3D& getPt3();
 private:
  QVector3D pt1;
  QVector3D pt2;
  QVector3D pt3;

};
#endif

