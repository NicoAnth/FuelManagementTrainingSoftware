#include "connexion.h"
#include <QString>
#include <QSignalMapper>

Connection::Connection(){
    
    usersFile = new QFile("../Data/Connection/login.txt");
}

void Connection::ConnectionInterface(){
    
    QWidget *mainConnectionWindow = new QWidget;
    QLineEdit *name = new QLineEdit;
    QLineEdit *password = new QLineEdit;
    password->setEchoMode(QLineEdit::Password);
    QVBoxLayout *connectionBox = new QVBoxLayout;
    QPushButton *validate = new QPushButton("Login");
    QPushButton* quit = new QPushButton("Cancel");
    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("&Name",name);
    formLayout->addRow("&Password",password);
    connectionBox->addLayout(formLayout);
    connectionBox->addWidget(validate);
    connectionBox->addWidget(quit);
    mainConnectionWindow->setLayout(connectionBox);
    mainConnectionWindow->setWindowTitle("Log in");
    mainConnectionWindow->show();

    QWidget::connect(quit,SIGNAL(clicked()),mainConnectionWindow,SLOT(close()));

}

void Connection::newAccountInterface(){
    
    QWidget *mainConnectionWindow = new QWidget;
    QLineEdit *name = new QLineEdit;
    QLineEdit *password = new QLineEdit;
    password->setEchoMode(QLineEdit::Password);
    QVBoxLayout *connectionBox = new QVBoxLayout;
    QPushButton *validate = new QPushButton("Register");
    QPushButton* quit = new QPushButton("Cancel");
    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("&Name",name);
    formLayout->addRow("&Password",password);
    connectionBox->addLayout(formLayout);
    connectionBox->addWidget(validate);
    connectionBox->addWidget(quit);
    mainConnectionWindow->setLayout(connectionBox);
    mainConnectionWindow->setWindowTitle("Register");
    mainConnectionWindow->show();

    //SIGNALS
    QSignalMapper* signalMapper = new QSignalMapper (this) ;
    signalMapper-> setMapping(validate,name->text());
    signalMapper-> setMapping(validate,password->text());

    QWidget::connect(quit,SIGNAL(clicked()),mainConnectionWindow,SLOT(close()));
    QWidget::connect(validate,SIGNAL(clicked()),signalMapper,SLOT(map()));
    QWidget::connect(validate,SIGNAL(clicked()),mainConnectionWindow,SLOT(close()));
}

void Connection::createUser(QString name, QString password){
    usersFile->open(QIODevice::ReadWrite);
    usersFile->write(name.toUtf8());
    usersFile->write(" ");
    usersFile->write(password.toUtf8());
    usersFile->write("\n");
    usersFile->close();

}