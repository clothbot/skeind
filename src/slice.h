#ifndef SLICE_H
#define SLICE_H

#include <QPainterPath>

class Slice extends QPainterPath {
  public:
    Slice();
    ~Slice();
    QLine calculate2DBBox();
    Line3D calculate3DBCube();
    bool setPosition(QVector3D newPos);
    bool setOrientation(QVector3D newOrient);
    bool setTransform(QTransform newXF);
    bool setThickness(qreal newThick);
    // 2D Operators
    //  geomOr: equiv to OpenSCAD union or QPainterPath united()
    Slice geomOr(Slice first, QList<Slice> rest);
    Slice geomOr(Slice first, Slice second);
    //  geomAnd: equiv to OpenSCAD intersection() or QPainterPath intersected()
    Slice geomAnd(Slice first, QList<Slice> rest);
    Slice geomAnd(Slice first, Slice second);
    //  geomAndNot: equiv to OpenSCAD difference() or QPainterPath subtracted()
    Slice geomAndNot(Slice first, QList<Slice> rest);
    Slice geomAndNot(Slice first, Slice second);
    // geomXor: no direct equiv in OpenSCAD or QPainterPath
    Slice geomXor(Slice first, QList<Slice> rest);
    Slice geomXor(Slice first, Slice second);
    // shell generation
    Slice shell(qreal wallThick);
  private:
    qreal thickness;
    QLine localBBox;
    QVector3D position;
    QVector3D orientation;
    QTransform transform;
    QVector2D gridScale;
};

#endif

