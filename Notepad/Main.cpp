#include "Notepad.h"

#include <QApplication>
#include <variant>

int main(int argc, char *argv[])
{
    QApplication a{argc, argv};
    Notepad w{};

    w.show();
    return a.exec();
}
