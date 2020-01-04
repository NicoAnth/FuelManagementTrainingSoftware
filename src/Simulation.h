//
// Created by user on 03/01/2020.
//

#ifndef PROJETCARBURANTAVION_SIMULATION_H
#define PROJETCARBURANTAVION_SIMULATION_H

#include "affichage.h"

class Simulation : public QWidget{
    Q_OBJECT

    private:
        QMap<QString name, GenericTpev*> simulationMap;

    public:
        Simulation(QMap<QString name, GenericTpev*> systemeCmap);
        ~Simulation(){}

    public slots:
        void tankClicked(QString name);
        void pumpClicked(QString name);
        void valveTankClicked(QString name);
        void valveEngineClicked(QString name);
};


#endif //PROJETCARBURANTAVION_SIMULATION_H
