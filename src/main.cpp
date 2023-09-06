#include <QApplication>
#include <QFile>
#include "mainwindow.h"

static void setStyle(const QString& styleName) {
    QFile file(QString("%1").arg(styleName));
    file.open(QFile::ReadOnly);
    QString css = QLatin1String(file.readAll());
    qApp->setStyleSheet(css);
}

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    setStyle(":/stylesheet/qss/lightblue.css");
    w.show();
    return a.exec();
}
