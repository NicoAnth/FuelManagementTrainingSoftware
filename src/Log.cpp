//
// Created by user on 29/12/2019.
//

#include "Log.h"

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

    //LOG
    Log::Log(QMainWindow* mainWindow, SystemeCarburant* sc){
        systemeC = sc;
        actionList = new QListWidget();
        evaluationList = new QListWidget();
        addLine("INITIAL STATE");
        QObject::connect(actionList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(itemClicked(QListWidgetItem*)));

        dockAction = new QDockWidget(tr("Log"), mainWindow);
        dockAction->setAllowedAreas(Qt::RightDockWidgetArea);
        dockAction->setWidget(actionList);
        mainWindow->addDockWidget(Qt::RightDockWidgetArea, dockAction);

        dockEval = new QDockWidget(tr("Evaluation Log"), mainWindow);
        dockEval->setWidget(evaluationList);
        mainWindow->addDockWidget(Qt::RightDockWidgetArea, dockEval);


        // SIGNALS
        QMap<QString, GenericTpev*>& systemeCmap = systemeC->getMap();
        for(auto it=systemeCmap.cbegin(); it!=systemeCmap.cend(); it++){
            QObject::connect(it.value(), SIGNAL(clickedLog(QString)), this, SLOT(addLine(QString)));
        }
    }
    void Log::clear() {
        delete(actionList);
        delete(evaluationList);
        evaluationList = new QListWidget();
        actionList = new QListWidget();
        QObject::connect(actionList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(itemClicked(QListWidgetItem*)));
        dockAction->setWidget(actionList);
        dockEval->setWidget(evaluationList);
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

    void Log::load(QString name){
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

    void Log:: addEvalLog(QString mistakeMessage){
        LogItem *sentence = new LogItem();
        sentence->setText(mistakeMessage);
        evaluationList->addItem(sentence);
        evaluationList->addItem(sentence);
        evaluationList->setCurrentItem(sentence);
        update();
        systemeC->update();

    }

