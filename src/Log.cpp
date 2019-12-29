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

Log::Log(QMainWindow* mainWindow, SystemeCarburant* systemeC){
    actionList = new QListWidget();
    addLine("INITIAL STATE");
    QObject::connect(actionList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(itemClicked(QListWidgetItem*)));

    dock = new QDockWidget(tr("Log"), mainWindow);
    dock->setAllowedAreas(Qt::RightDockWidgetArea);
    dock->setWidget(actionList);
    mainWindow->addDockWidget(Qt::RightDockWidgetArea, dock);

    this->systemeC = systemeC;


    // SIGNALS
    QMap<QString, GenericTpev*>& systemeCmap = systemeC->getMap();
    QObject::connect(systemeCmap["tank 1"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["tank 2"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["tank 3"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["p11"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["p12"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["p21"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["p22"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["p31"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["p32"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["v12"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["v13"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["v23"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["vt12"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
    QObject::connect(systemeCmap["vt23"], SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
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
