#include <QtWidgets>
#include <FenPrincipale.h>

int main(int argc, char *argv[])

{
    QApplication app(argc,argv);
    FenPrincipale mainWindow;
    mainWindow.setWindowTitle("Hecho por Kenny");
    mainWindow.show();

    return app.exec();


}
