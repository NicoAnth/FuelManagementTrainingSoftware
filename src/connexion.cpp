#include "connexion.h"
#include <QString>
#include <QSignalMapper>
#include <QMessageBox>
#include <QTextStream>
#include<QDebug>
#include <iostream>

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
    QWidget::connect(validate, &QPushButton::clicked,[=]() {connectUser(name->text(),password->text());});
    QWidget::connect(validate,SIGNAL(clicked()),mainConnectionWindow,SLOT(close()));
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
    QWidget::connect(quit,&QPushButton::clicked,mainConnectionWindow,&QWidget::close);
    QWidget::connect(validate, &QPushButton::clicked,[=]() {createUser(name->text(),password->text());});
    QWidget::connect(validate,SIGNAL(clicked()),mainConnectionWindow,SLOT(close()));
}

void Connection::createUser(QString name, QString password){
    
    if(alreadyExists(name,password)){
        QMessageBox::information(this, "Error", "User already exists.");
        return;
    }
    usersFile->open(QIODevice::Append);
    usersFile->write(name.toUtf8());
    usersFile->write(" ");
    usersFile->write(password.toUtf8());
    usersFile->write("\n");
    usersFile->close();
    QMessageBox::information(this, "Confirm", "Thanks " + name + ", your account has been successfully created ");

}
bool Connection::connectUser(QString name, QString password){
    
    if(alreadyExists(name,password)){
        QMessageBox::information(this, "Welcome", "Welcome " + name + ".");
        emit isConnected();
        isconnected = true;
        userName = name;
        return true;
    }
    QMessageBox::information(this, "Unknown user", "Sorry, we couldn't recognize your name or password, please try again.");
    usersFile->close();
    return false;

}
bool Connection::alreadyExists(QString name, QString password){

    usersFile->open(QIODevice::ReadOnly);
    QString user = name +" "+ password + "\n";
    QTextStream in(usersFile);
    while(!in.atEnd()){
        QString line = usersFile->readLine();
        if(line == user){
            usersFile->close();
            return true;
        }
    }
    usersFile->close();
    return false;
}
bool Connection::getConnected(){
    return isconnected;
}
/* void Connection::disconnection(){
        emit isDisconnectedSignal();
        isconnected = false;
        userName = "";
} */

void Connection::isDisconnectedSlot(){
        emit isDisconnectedSignal();
        isconnected = false;
        userName = "";
        update();
}
