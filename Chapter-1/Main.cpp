// Qt headers
#include "MainWindow.h"
#include <QApplication>

// C++  headers

int main(int argc, char *argv[])
{
    QApplication a{argc, argv};
    MainWindow w{};
    w.show();
    return a.exec();
}
