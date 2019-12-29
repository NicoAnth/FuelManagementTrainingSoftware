//
// Created by user on 29/12/2019.
//

#ifndef PROJETCARBURANTAVION_LOG_H
#define PROJETCARBURANTAVION_LOG_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QVector>
#include <QMap>
#include <QMainWindow>
#include "affichage.h"

class LogItem : public QListWidgetItem{
    Q_OBJECT

    private:
        QVector<qint32> stateVector;

    public:
        LogItem(){}
        ~LogItem(){}
};

class Log : public QWidget{
//    Q_OBJECT
//
//    private:
//        SystemeCarburant* systemeC;
//        QListWidget* actionList;
//
//    public:
//        Log(QMainWindow* mainWindow);
//        ~Log(){}
//
//    public slots:
//        void addItem(QString name);
};


#endif //PROJETCARBURANTAVION_LOG_H
