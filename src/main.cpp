#include <QApplication>
#include <QWidget>
#include "MainWindow.h"
#include "affichage.h"

using namespace std;

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
//    app.setStyleSheet("QPushButton{border: 1px solid black; border-radius: 5px}");
    MainWindow* window = new MainWindow();
    window->show();

    return app.exec();
}