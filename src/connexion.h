#include "affichage.h"
#include <QLayout>
#include <QFormLayout>
#include <QLineEdit>

class Connexion: QWidget{
    
    Q_OBJECT

    private:
        QWidget *mainConnexionWindow;
        QLineEdit *name;
        QLineEdit *password;
        QVBoxLayout *connexionBox;
        QPushButton *validate;
        QPushButton *quit;
        QFormLayout *formLayout;
    public: 
        Connexion();
        ~Connexion(){};
};