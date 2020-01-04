//
// Created by user on 03/01/2020.
//

#ifndef PROJETCARBURANTAVION_SIMULATION_H
#define PROJETCARBURANTAVION_SIMULATION_H

#include "affichage.h"

class Simulation : public QWidget{
    Q_OBJECT

    private:
        QMap<QString name, GenericTpev*> systemMap;

    public:
        Simulation();
        ~Simulation(){}

    public slots:
        void tankClicked();
        void pumpClicked();
        void valveClicked();

    signals:

};


#endif //PROJETCARBURANTAVION_SIMULATION_H
