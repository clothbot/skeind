// Triangle class

#include "triangle.h"

Triangle::Triangle(QVector3D pt1, QVector3D pt2, QVector3D pt3) {
  point[0]=pt1;
  point[1]=pt2;
  point[2]=pt3;
  // find point with minz, then miny, then minx
  // make that points[0]
  // calculate normal using remaining points
}

Triangle::Triangle(QVector3D pt1, QVector3D pt2, QVector3D pt3, QVector3D norm) {
  point[0]=pt1;
  point[1]=pt2;
  point[2]=pt3;
  QVector3D calcNorm = QVector3D::normal(point[0],point[1],point[2]);
  qreal normDot= QVector3D::dotProduct(calcNorm,norm);
  if(normDot<0) {
    QVector3D tmp=point[1];
    point[1]=point[2];
    point[2]=tmp;
  }
  // find point with minz, then miny, then minx
  // make that points[0]
  // calculate normal using remaining points
  // if QVector3D::dotProduct(calcNormal, norm) < 0 swap(pt2, pt3)
}

Triangle::~Triangle() {
  delete(point);
}

QVector3D Triangle::getNormal() {
  QVector3D norm=QVector3D::normal(point[0],point[1],point[2]);
  return(norm);
}

qreal Triangle::getArea() {
  QVector3D v1=point[1]-point[0];
  QVector3D v2=point[2]-point[0];
  QVector3D crossv=QVector3D::crossProduct(v1,v2);
  qreal crossvl = crossv.length();
  return(crossvl);
}
  
QList<QVector3D> Triangle::getBBox() {
  QVector3D minPt=point[0];
  QVector3D maxPt=point[0];
  for(int i=0;i<3;i++) {
    if(minPt.x()>point[i].x()) minPt.setX(point[i].x());
    if(minPt.y()>point[i].y()) minPt.setY(point[i].y());
    // point[0] is min Z point by definition
    if(maxPt.x()<point[i].x()) maxPt.setX(point[i].x());
    if(maxPt.y()<point[i].y()) maxPt.setY(point[i].y());
    if(maxPt.z()<point[i].z()) maxPt.setZ(point[i].z());
  }
  QList<QVector3D> returnPts;
  returnPts[0]=minPt;
  returnPts[1]=maxPt;
  return(returnPts);
}

