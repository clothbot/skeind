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
  gridScale.setZ(0.05);
}

Slice::~Slice() {
}

QRectF Slice::boundingRect() {
  QRectF newBR;
  bool initFlag=false;
  foreach(QPolygonF thisPoly, toFillPolygons()) {
    QRectF localBR=thisPoly.boundingRect();
    if(initFlag) {
      if( localBR.bottom()<newBR.bottom() )
	newBR.moveBottom(localBR.bottom());
      if( localBR.left()<newBR.left() ) 
	newBR.moveLeft(localBR.left());
      if( localBR.top()>newBR.top() )
	newBR.moveTop(localBR.top());
      if( localBR.right()>newBR.right() )
	newBR.moveRight(localBR.right());
    } else {
      newBR=localBR;
      initFlag=true;
    }
  }
  return(newBR);
}

