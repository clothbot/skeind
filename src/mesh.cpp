// Mesh class

#include "mesh.h"

Mesh::Mesh() {
  boundingCube.setPt1(QVector3D(0,0,0));
  boundingCube.setPt2(QVector3D(0,0,0));
}

Mesh::Mesh(QList<Triangle> triangles) {
  boundingCube.setPt1(QVector3D(0,0,0));
  boundingCube.setPt2(QVector3D(0,0,0));
  foreach(const Triangle &tri, triangles) {
    append(tri);
  }
}

// Mesh::Mesh(QList<Slice> slices) {
//   boundingCube.setPt1(QVector3D(0,0,0));
//   boundingCube.setPt2(QVector3D(0,0,0));
// }

QVector3D& Mesh::getLBL() {
  return(boundingCube.getPt1());
}

QVector3D& Mesh::getUFR() {
  return(boundingCube.getPt2());
}

bool Mesh::add(Triangle & tri) {
  append(tri);
  return(true);
}

Mesh::~Mesh() {
}


