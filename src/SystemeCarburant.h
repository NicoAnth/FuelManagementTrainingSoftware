//
// Created by user on 04/01/2020.
//

#ifndef PROJETCARBURANTAVION_SYSTEMECARBURANT_H
#define PROJETCARBURANTAVION_SYSTEMECARBURANT_H

#include <QLayout>
#include <QMap>
#include "affichage.h"


 class SystemeCarburant: public QWidget{
    Q_OBJECT

    private:
        QMap<QString, GenericTpev*> tpevMap;
        QMap<QString, qint32> lastLogEntry;
        Tank* tank1;
        Tank* tank2;
        Tank* tank3;
        Pump* pump11;
        Pump* pump12;
        Pump* pump21;
        Pump* pump22;
        Pump* pump31;
        Pump* pump32;
        Engine* engine1;
        Engine* engine2;
        Engine* engine3;
        ValveTank* vt12;
        ValveTank* vt23;
        ValveEngine* v12;
        ValveEngine* v13;
        ValveEngine* v23;
        QPushButton *vtdb1;
        QPushButton *vtdb2;
        QPushButton *pdb1;
        QPushButton *pdb2;
        QPushButton *pdb3;
        QPushButton *vdb1;
        QPushButton *vdb2;
        QPushButton *vdb3;

    public:
        SystemeCarburant(){}
        SystemeCarburant(const SystemeCarburant& sc);
        SystemeCarburant(int width, int height);
        ~SystemeCarburant(){}

        void paintEvent(QPaintEvent*);
        void setMap(const QMap<QString, qint32>& logMap);
        QMap<QString, GenericTpev*>& getMap();
        void setLastEntry(const QMap<QString, qint32>& entry);
        QMap<QString, qint32>& getLastEntry();

    public slots:
        void updateLastEntry();
};

#endif //PROJETCARBURANTAVION_SYSTEMECARBURANT_H
