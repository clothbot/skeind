#include <QApplication>
#include <QDebug>
#include <QPolygon>
#include <QString>
#include <QTextStream>

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
 
  if (useGUI) {
    // start GUI version
  } else {
    // start non-GUI version
  }
  return app.exec();
}
