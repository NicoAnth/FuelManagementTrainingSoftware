#include "eval.h"


Evaluation::Evaluation(SystemeCarburant *systemeC): sc(systemeC), scMap(sc->getMap()){
    
    time = new QTimer(this);
    mark = 20;
    mistake_nb = 0;
    bool success = QObject::connect(scMap["VT12"], SIGNAL(stateChanged(QString)), this, SLOT(vt12(QString)));
    Q_ASSERT(success);
}

bool Evaluation::vt12(QString a){


    if (scMap["Tank 1"]->getState() == false && scMap["Tank 2"]->getState() == true){
        if (scMap["P11"]->getState() != BROKEN || scMap["P12"]->getState() != BROKEN){
            if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() == false || scMap["Engine3"]->getState() == false){
                scMap["P31"]->setState(1);
                
                qInfo("Vrai");
                return true;
            }
        }
    }

    else if (scMap["Tank 1"]->getState() == true && scMap["Tank 2"]->getState() == false){
        if (scMap["P21"]->getState() != BROKEN || scMap["P22"]->getState() != BROKEN){
            if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() || scMap["Engine3"]->getState() == false){ 
                scMap["P31"]->setState(1);
                
                qInfo("Vrai");
                return true;
            }
        }
        else if (scMap["Tank 3"]->getState() == false){
            if (scMap["P31"]->getState() != BROKEN || scMap["P32"]->getState() != BROKEN){
                if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() == false || scMap["Engine3"]->getState() == false ){
                    scMap["P31"]->setState(1);
                    
                    qInfo("Vrai");
                    return true;
                }
            }
        }

         
    }

    qInfo("Faux");
    return false;


}    


