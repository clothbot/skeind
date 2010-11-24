// Slice class

#include "slice.h"

Slice::Slice() {
  thickness=0.25;
  localBBox.setLine(0,0,0,0);
  position.setX(0);
  position.setY(0);
  position.setZ(0);
  orientation.setX(0);
  orientation.setY(0);
  orientation.setZ(0);
  transform.reset();
  gridScale.setX(0.01);
  gridScale.setY(0.01);
  gridScale.setY(0.05);
}

Slice::~Slice() {
}

