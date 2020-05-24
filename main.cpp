#include <QApplication>
#include <QStyleFactory>
#include <QDebug>
#include <exception>
#include <widgets/mainwindow.hpp>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("Fusion"));
    Window w;
    w.show();

    return a.exec();
}
