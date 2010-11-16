// Triangle class

#include "triangle.h"

Triangle::Triangle(QVector3D inpt1, QVector3D inpt2, QVector3D inpt3) {
  pt1=inpt1;
  pt2=inpt2;
  pt3=inpt3;
  // find point with minz, then miny, then minx
  // make that points[0]
  // calculate normal using remaining points
}

Triangle::Triangle(QVector3D inpt1, QVector3D inpt2, QVector3D inpt3, QVector3D norm) {
  pt1=inpt1;
  pt2=inpt2;
  pt3=inpt3;
  QVector3D calcNorm = QVector3D::normal(pt1,pt2,pt3);
  qreal normDot= QVector3D::dotProduct(calcNorm,norm);
  if(normDot<0) {
    QVector3D tmp=pt2;
    pt2=pt3;
    pt3=tmp;
  }
  // find point with minz, then miny, then minx
  // make that points[0]
  // calculate normal using remaining points
  // if QVector3D::dotProduct(calcNormal, norm) < 0 swap(pt2, pt3)
}

Triangle::~Triangle() {
}

QVector3D Triangle::calculateNormal() {
  QVector3D norm=QVector3D::normal(pt1,pt2,pt3);
  return(norm);
}

qreal Triangle::calculate2DArea() {
  QVector3D v1=pt2-pt1;
  QVector3D v2=pt3-pt1;
  QVector3D crossv=QVector3D::crossProduct(v1,v2);
  qreal crossvl = crossv.length();
  return(crossvl);
}
  
Line3D Triangle::calculate3DBCube() {
  QVector3D minPt=pt1;
  QVector3D maxPt=pt1;
  QList<QVector3D> point;
  point.append(pt1);
  point.append(pt2);
  point.append(pt3);
  for(int i=0;i<3;i++) {
    if(minPt.x()>point[i].x()) minPt.setX(point[i].x());
    if(minPt.y()>point[i].y()) minPt.setY(point[i].y());
    // pt1 is min Z point by definition
    if(maxPt.x()<point[i].x()) maxPt.setX(point[i].x());
    if(maxPt.y()<point[i].y()) maxPt.setY(point[i].y());
    if(maxPt.z()<point[i].z()) maxPt.setZ(point[i].z());
  }
  Line3D returnPts(minPt,maxPt);
  return(returnPts);
}

