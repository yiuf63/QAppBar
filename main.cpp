#include <QApplication>
#include "appbarwidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    auto a=new AppBar;
    a->registerAppBar();
    a->show();
    return app.exec();
}
