#ifndef MESH_H
#define MESH_H

#include "line3d.h"
// #include "slice.h"
#include "triangle.h"
#include <QList>
#include <QVector3D>

class Mesh : public QList<Triangle> {
 public:
  Mesh();
  Mesh(QList<Triangle> triangles);
//  Mesh(QList<Slice> slices);
  ~Mesh();
  QVector3D& getLBL();
  QVector3D& getUFR();
  bool add(Triangle & tri);
	// Detect degenerate triangles
	// Update bounding cube
 private:
  Line3D boundingCube;
};

#endif
