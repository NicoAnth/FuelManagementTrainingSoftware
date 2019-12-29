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

Log::Log(QMainWindow* mainWindow){
    systemeC = new SystemeCarburant(700,600,this);
    systemeC->setParent(mainWindow);
    mainWindow->setCentralWidget(systemeC);

    actionList = new QListWidget();

    dock = new QDockWidget(tr("Log"), mainWindow);
    dock->setAllowedAreas(Qt::RightDockWidgetArea);
    dock->setWidget(actionList);
    mainWindow->addDockWidget(Qt::RightDockWidgetArea, dock);
}

//void Log::itemClicked(QListWidgetItem *item) {
//    LogItem* logItem = dynamic_cast<LogItem*> (item);
//    systemeC->setMap(logItem->getMap());
//
//    std::cout << "item clicked !" << std::endl;
//    systemeC->update();
//}

void Log::addLine(QString name){
    LogItem* tmp = new LogItem;
    tmp->setMap(systemeC->getMap());

    QListWidgetItem* item = tmp;
    item->setText(name);

    actionList->addItem(item);

    update();
}
