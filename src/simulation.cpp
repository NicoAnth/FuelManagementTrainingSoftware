//
// Created by user on 26/10/2019.
//

#include <QApplication>
#include <QWidget>
#include "affichage.h"

using namespace std;

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
//    app.setStyleSheet("QPushButton{border: 1px solid black; border-radius: 5px}");
    SystemeCarburantWindow* window = new SystemeCarburantWindow(600,600);
    window->show();

    return app.exec();
}