#ifndef MESH_H
#define MESH_H

class Mesh extends QList<Triangle> {
 public:
  Mesh();
  ~Mesh();
  void setScale(qreal rnum);
  qreal getScale();
  QVector3D& getLLB();
  QVector3D& getURF();
 private:
  qreal scale;
  QVector3D lowerLeftBack;
  QVector3D upperRightFront;
};

#endif
