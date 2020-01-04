//
// Created by user on 29/12/2019.
//

#ifndef PROJETCARBURANTAVION_LOG_H
#define PROJETCARBURANTAVION_LOG_H

#include <QListWidget>
#include <QDockWidget>
#include <QFile>
#include <QDebug>
#include <QMainWindow>
#include "affichage.h"
#include "SystemeCarburant.h"

class SystemeCarburant;
class GenericTpev;

class LogItem : public QListWidgetItem{
    private:
        QMap<QString, qint32> logMap;

    public:
        LogItem(){}
        LogItem(const LogItem&);
        ~LogItem(){}

        void setMap(const QMap<QString, GenericTpev*>& systemeCmap);
        void setMap(const QMap<QString, qint32>& itemMap);
        QMap<QString, qint32>& getMap();
        friend QDataStream& operator<<(QDataStream&, LogItem&);
        friend QDataStream& operator>>(QDataStream&, LogItem&);

};

class Log : public QWidget{
    Q_OBJECT

    private:
        SystemeCarburant* systemeC;
        QListWidget* actionList;
        QListWidget *evaluationList;
        QList<LogItem> itemList;
        QDockWidget* dockAction;
        QDockWidget* dockEval;

    public:
        Log(QMainWindow* mainWindow, SystemeCarburant* systemeC);
        ~Log(){}

    public slots:
        void addLine(QString name);
        void itemClicked(QListWidgetItem*);
        void save(QString name);
        void load(QString name);
        void addEvalLog(QString mistakeMessage);
        void clear();

    signals:
        void lastEntry(QMap<QString, qint32>*);
};


#endif //PROJETCARBURANTAVION_LOG_H
