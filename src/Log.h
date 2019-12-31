//
// Created by user on 29/12/2019.
//

#ifndef PROJETCARBURANTAVION_LOG_H
#define PROJETCARBURANTAVION_LOG_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVector>
#include <QMap>
#include <QMainWindow>
#include <QDockWidget>
#include <QFile>
#include <QDebug>
#include "affichage.h"

class SystemeCarburant;
class GenericTpev;

class LogItem : public QListWidgetItem{
    private:
        QMap<QString, qint32> logMap;

    public:
        LogItem(){}
        ~LogItem(){}

        void setMap(const QMap<QString, GenericTpev*>& systemeCmap);
        QMap<QString, qint32>& getMap();
};

//class LogActionList : public QListWidget{
//    private:
//        QList<LogItem*> list;
//
//    public:
//        LogActionList(){}
//        ~LogActionList(){}
//
//        void addLogItem(LogItem* item);
//        void clear();
//};

class Log : public QWidget{
    Q_OBJECT

    private:
        SystemeCarburant* systemeC;
        QListWidget* actionList;
        QList<LogItem*> itemList;
        QDockWidget* dock;

    public:
        Log(QMainWindow* mainWindow, SystemeCarburant* systemeC);
        ~Log(){}
        void clear();
//        friend QDataStream& operator >> (QDataStream&, Log& log);
//        friend QDataStream& operator << (QDataStream&, const Log& log);


    public slots:
        void addLine(QString name);
        void itemClicked(QListWidgetItem*);
        void tpevClicked();
        void save(QString name);
        void load(QString name);

    signals:
        void lastEntry(QMap<QString, qint32>*);
};


#endif //PROJETCARBURANTAVION_LOG_H
