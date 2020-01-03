#include "connexion.h"


Connexion::Connexion(){
    
    mainConnexionWindow = new QWidget;
    name = new QLineEdit;
    password = new QLineEdit;
    connexionBox = new QVBoxLayout;
    validate = new QPushButton("Validate");
    quit = new QPushButton("Quit");
    formLayout = new QFormLayout;
    formLayout->addRow("&Name",name);
    formLayout->addRow("&Password",password);
    connexionBox->addLayout(formLayout);
    connexionBox->addWidget(validate);
    connexionBox->addWidget(quit);
    mainConnexionWindow->setLayout(connexionBox);
    mainConnexionWindow->show();

}