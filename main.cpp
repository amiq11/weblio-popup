#include "popupwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PopupWidget w;
    w.show();
    return a.exec();
}
