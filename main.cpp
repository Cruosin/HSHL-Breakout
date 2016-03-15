
#include <QApplication>

#include "PlayingField.h"
#include "Ball.h"
#include "Block.h"
#include "Platform.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    PlayingField window1;
    window1.show();

    return app.exec();
}
