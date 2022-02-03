#include "farmaciascuquita.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FarmaciasCuquita w;
    w.show();
    return a.exec();
}
