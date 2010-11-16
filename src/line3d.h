#ifndef LINE3D_H
#define LINE3D_H

#include <QVector3D>

class Line3D {
  public:
    Line3D(QVector3D inpt1, QVector3D inpt2);
    ~Line3D();
    bool isValid();
    QVector3D& getLBL();
    QVector3D& getUFR();
    QVector3D getPt1();
    QVector3D getPt2();
    void setPt1(QVector3D inpt1);
    void setPt2(QVector3D inpt2);
  private:
    QVector3D pt1;
    QVector3D pt2;
};

#endif
