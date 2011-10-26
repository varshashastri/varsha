#include <qapplication.h>
#include "awari.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    awari *dialog = new awari;
    app.setMainWidget(dialog);
    dialog->show();
    return app.exec();
}
