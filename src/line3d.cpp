// Line3D class

#include "line3d.h"

Line3D::Line3D() {
  pt1=QVector3D(0,0,0);
  pt2=QVector3D(0,0,0);
}

Line3D::Line3D(QVector3D inpt1, QVector3D inpt2) {
  pt1=inpt1;
  pt2=inpt2;
}

Line3D::~Line3D() {
}

QVector3D & Line3D::getPt1() {
  return(pt1);
}
QVector3D & Line3D::getPt2() {
  return(pt2);
}
void Line3D::setPt1(const QVector3D aV3D) {
  pt1=aV3D;
}
void Line3D::setPt2(const QVector3D aV3D) {
  pt2=aV3D;
}
