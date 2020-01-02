//
// Created by user on 29/12/2019.
//

#include "Log.h"
#include <iostream>

// LOG ITEM
LogItem::LogItem(const LogItem& item) : QListWidgetItem() {
    *this = item;
}

void LogItem::setMap(const QMap<QString, GenericTpev *>& systemeCmap) {
    for(auto it = systemeCmap.cbegin(); it != systemeCmap.cend(); it++){
        logMap[it.key()] = it.value()->getState();
    }
}

void LogItem::setMap(const QMap<QString, qint32>& itemMap) {
    logMap = itemMap;
}

QDataStream& operator<<(QDataStream& out, LogItem& item){
    out << item.text();
    out << item.getMap();
    return out;
}

QDataStream& operator>>(QDataStream& in, LogItem& item) {
    QString name;
    QMap<QString, qint32> map;

    in >> name;
    in >> map;

    item.setText(name);
    item.setMap(map);

    return in;
}

QMap<QString, qint32>& LogItem::getMap() {
    return logMap;
}
//
//// LOG ACTION LIST
//void LogActionList::addLogItem(LogItem *item) {
//    addItem(dynamic_cast<QListWidgetItem*> item);
//    list.push_back(item);
//}

//LOG
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
    for(auto it=systemeCmap.cbegin(); it!=systemeCmap.cend(); it++){
//        QObject::connect(it.value(), SIGNAL(stateChanged(QString)), this, SLOT(addLine(QString)));
        QObject::connect(it.value(), SIGNAL(clicked()), this, SLOT(tpevClicked()));
    }

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

void Log::clear() {
    delete(actionList);
    actionList = new QListWidget();
    QObject::connect(actionList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(itemClicked(QListWidgetItem*)));
    dock->setWidget(actionList);
}
//
//QDataStream & Log::operator<<(QDataStream &flux, const Log &log) {
//
//}
//
//QDataStream & Log::operator>>(QDataStream &flux, Log &log) {
//    for(auto it = log.itemList.cbegin(); it != log.itemList.cend(); it++){
//        flux >>
//    }
//}

void Log::tpevClicked() {
    systemeC->setMap(systemeC->getLastEntry());
}

void Log::itemClicked(QListWidgetItem *item) {
    LogItem* logItem = dynamic_cast<LogItem*> (item);

    systemeC->setMap(logItem->getMap());
    systemeC->update();
}

void Log::addLine(QString name){
    LogItem* item = new LogItem;
    item->setMap(systemeC->getMap());
    systemeC->setLastEntry(item->getMap());
    item->setText(name);

    actionList->addItem(item);
    itemList.push_back(*item);
    actionList->setCurrentItem(item);

    update();
    systemeC->update();
}

void Log::save(QString name) {
    QFile file(name);

    if(!file.open(QIODevice::WriteOnly)){
        qInfo() << "cannot open file write " << name;
    }

    QDataStream out(&file);
    out << itemList.size();

    for(auto it = itemList.begin(); it != itemList.end(); it++){
        out << (*it);
    }
}

void Log::load(QString name){;
    QFile file(name);

    if(!file.open(QIODevice::ReadOnly)){
        qInfo() << "cannot open file open " << name;
    }

    // reset ItemList
    QDataStream in(&file);

    // reset log
    itemList.clear();
    clear();

    int size;
    in >> size;

    while(size){
        LogItem* item = new LogItem();
        in >> *item;
        itemList.push_back(*item);
        actionList->addItem(item);
        size--;
    }

    if(!itemList.isEmpty()){
        systemeC->setMap(itemList.back().getMap());
        systemeC->setLastEntry(itemList.back().getMap());
    }

    update();
    systemeC->update();
}

//void Log::save(QString name) {
//    QFile file(LOG_DIR + name + ".txt");
//
//    if(!file.open(QIODevice::WriteOnly)){
//        qInfo() << "cannot open file " << name;
//    }
//
//    QDataStream out(&file);
//    out << itemList;
//}
//
//void Log::load(QString name){
//    QFile file(LOG_DIR + name + ".txt");
//
//    if(!file.open(QIODevice::ReadOnly)){
//        qInfo() << "cannot open file " << name << ".txt";
//    }
//
//    // reset ItemList
//    QDataStream in(&file);
//
//    // reset log
//    itemList.clear();
//    clear();
//
//    in >> itemList;
//
//    for(auto it = itemList.cbegin(); it != itemList.cend(); it++){
//        actionList->addItem(new LogItem(*it));
//    }
//
//    if(!itemList.isEmpty()){
//        systemeC->setMap(itemList.back().getMap());
//        systemeC->setLastEntry(itemList.back().getMap());
//    }
//
//    update();
//    systemeC->update();
//}
