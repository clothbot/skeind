#include <QApplication>
#include <QDebug>
#include <QFileDialog>
#include <QObject>
#include <QPainter>
#include <QPainterPath>
#include <QPen>
#include <QPolygon>
#include <QPolygonF>
#include <QRegion>
#include <QString>
#include <QSvgGenerator>
#include <QTextStream>
#include <QTranslator>
#include <QWidget>
#include <QGridLayout>

int main(int argc, char *argv[]) {
  #ifdef Q_WS_X11
    bool useGUI = getenv("DISPLAY") != 0;
  #else
    bool useGUI = true;
  #endif
  QApplication app(argc, argv, useGUI);
  QTextStream stream(stdout);
  
  qDebug() << "Testing QPolygon\n";
  stream << "Testing QPolygon\n";

  QSvgGenerator generator;
  generator.setFileName("test.svg");
  generator.setSize(QSize(200,200));
  generator.setViewBox(QRect(0,0,200,200));
  // generator.setTitle(tr("Testing QPolygon"));
  generator.setTitle("Testing QPolygon");
  // generator.setDescription(tr("An SVG drawing testing QPolygon operations."));
  generator.setDescription("An SVG drawing testing QPolygon operations.");

  static const int box1[4][2] = { {5,5},{-5,5},{-5,-5},{5,-5} };
  static const int box2[4][2] = { {0,0},{10,0},{10,10},{0,10} };
  QPolygon poly1=QPolygon(4,&box1[0][0]);
  QPolygon poly2=QPolygon(4,&box2[0][0]);
  QPolygon poly3=poly1.subtracted(poly2);
  QPolygon poly4=poly1.united(poly2);
  QPolygon poly5=poly1.intersected(poly2);
  QPolygon poly6=poly4.subtracted(poly5);
  QRegion region1=QRegion(poly4);
  QRegion region2=QRegion(poly5);
  QRegion region3=region1.subtracted(region2);

  QPainterPath path1;
  path1.addPolygon(poly5);
  QPainterPath path2;
  path2.addPolygon(poly6);
  QPainterPath path3;
  path3=path2.subtracted(path1);
  QPainterPath path4=QPainterPath(path3);
  QPainterPath path5=QPainterPath(path3);

  poly3.translate(20,20);
  poly4.translate(40,20);
  poly5.translate(60,20);
  poly6.translate(20,40);
  region3.translate(40,40);
  path3.translate(60,40);
  path4.translate(20,60);
  path5.translate(40,60);
  if (useGUI) {
    // start GUI version
    qDebug() << " GUI Mode\n";
    QPainter painter;
    painter.begin(&generator);
    painter.setPen(Qt::blue);
    painter.drawPolygon(poly1);
    painter.drawPolygon(poly2);

    painter.drawPolygon(poly3);
    painter.drawPolygon(poly4);
    painter.drawPolygon(poly5);

    painter.drawPolygon(poly6);
    painter.drawPath(path3);

    foreach (QPolygonF thisPoly, path4.toFillPolygons()) {
      painter.drawPolygon(thisPoly);
    }

    path5.setFillRule(Qt::WindingFill);
    foreach (QPolygonF thisPoly, path5.toSubpathPolygons()) {
      painter.drawPolygon(thisPoly);
    }
    painter.end();
  } else {
    // start non-GUI version
    qDebug() << " Non-GUI Mode\n";
  }
  return app.exec();
}
