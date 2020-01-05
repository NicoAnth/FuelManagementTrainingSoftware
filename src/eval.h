#ifndef PROJETCARBURANTAVION_EVAL_H
#define PROJETCARBURANTAVION_EVAL_H

#include "affichage.h"
#include "Log.h"
#include "MainWindow.h"
#include<QDebug>

class Evaluation: QWidget {
    Q_OBJECT

    private:
        int mark;
        int mistake_nb;
        SystemeCarburant* sc;
        QMap<QString, GenericTpev*>& scMap;
        Log *log;
    public:
        Evaluation(SystemeCarburant *systemeC, Log *log_);
        ~Evaluation(){};
        int getMark();
        int getMistakeNumber();
        
 
    /* signals:
        bool resolved(); */

    public slots:
        bool vt12();
        bool vt23();
        bool v13();
        bool v12();
        bool v23();
        bool p12();
        bool p22();
        bool p32();
        bool resolved();
};

#endif