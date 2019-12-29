//
// Created by user on 29/12/2019.
//

#include "Log.h"
#include <iostream>

void LogItem::setMap(const QMap<QString, GenericTpev *> &systemeCmap) {
    int i = 0;

    for(auto it = systemeCmap.cbegin(); it != systemeCmap.cend(); it++){
        logMap[it.key()] = it.value()->getState();
    }
}

QMap<QString, qint32>& LogItem::getMap() {
    return logMap;
}

Log::Log(QMainWindow* mainWindow, SystemeCarburant* sc){
    systemeC = sc;
    actionList = new QListWidget();
    addLine("INITIAL STATE");
    QObject::connect(actionList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(itemClicked(QListWidgetItem*)));

    dock = new QDockWidget(tr("Log"), mainWindow);
    dock->setAllowedAreas(Qt::RightDockWidgetArea);
    dock->setWidget(actionList);
    mainWindow->addDockWidget(Qt::RightDockWidgetArea, dock);

    // SIGNALS
    QMap<QString, GenericTpev*>& systemeCmap = systemeC->getMap();
    QObject::connect(systemeCmap["Tank 1"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["Tank 2"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["Tank 3"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["P11"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["P12"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["P21"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["P22"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["P31"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["P32"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["V12"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["V13"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["V23"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["VT12"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["VT23"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
}

void Log::itemClicked(QListWidgetItem *item) {
    LogItem* logItem = dynamic_cast<LogItem*> (item);

    systemeC->setMap(logItem->getMap());
    systemeC->update();
}

void Log::addLine(QString name){
    LogItem* tmp = new LogItem;
    tmp->setMap(systemeC->getMap());

    QListWidgetItem* item = tmp;
    item->setText(name);

    actionList->addItem(item);

    update();
}
