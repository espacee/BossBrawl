#include "EditorWidget.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EditorWidget w;
    w.show();
    return a.exec();
}
