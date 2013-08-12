#include "editorWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.showMaximized();
    
    return a.exec();
}
