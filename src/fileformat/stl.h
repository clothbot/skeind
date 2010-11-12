// STL Stream Class
#ifndef STL_H
#define STL_H

#include <QList>
#include <QString>
#include <QVector3D>
#include "Mesh.h"
#include "Triangles.h"

class STLMesh extends Mesh {
public:
  Mesh(QString fileName);
  ~Mesh();
  
};

#endif
