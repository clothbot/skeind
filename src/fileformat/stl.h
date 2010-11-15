// STL Stream Class
#ifndef STL_H
#define STL_H

#include <QList>
#include <QString>
#include <QVector3D>
#include "../mesh.h"
#include "../triangle.h"

class STLMesh extends Mesh {
public:
  STLMesh(QString fileName);
  ~STLMesh();
  boolean LoadBinaryMesh(QString FileName);
  boolean LoadTextMesh(QString FileName);
};

#endif
