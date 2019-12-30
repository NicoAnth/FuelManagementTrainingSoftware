#include "eval.h"
#include <iostream>

Evaluation::Evaluation(SystemeCarburant *systemeC): sc(systemeC), scMap(sc->getMap()){
    
    time = new QTimer(this);
    mark = 20;
    mistake_nb = 0;
    QObject::connect(scMap["VT12"], SIGNAL(clicked()), this, SLOT(vt12o()));
    QObject::connect(scMap["VT23"], SIGNAL(clicked()), this, SLOT(vt23o()));

 
}

bool Evaluation::vt12o(){

    if (scMap["Tank 1"]->getState() == false && scMap["Tank 2"]->getState() == true){
        if (scMap["P11"]->getState() != BROKEN || scMap["P12"]->getState() != BROKEN){
            if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() == false || scMap["Engine3"]->getState() == false){
                qInfo("Vrai");
                return true;
            }
        }
    }

    else if (scMap["Tank 1"]->getState() == true && scMap["Tank 2"]->getState() == false){
        if (scMap["P21"]->getState() != BROKEN || scMap["P22"]->getState() != BROKEN){
            if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() || scMap["Engine3"]->getState() == false){ 
                qInfo("Vrai");
                return true;
            }
        }
        else if (scMap["Tank 3"]->getState() == false){
            if (scMap["P31"]->getState() != BROKEN || scMap["P32"]->getState() != BROKEN){
                if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() == false || scMap["Engine3"]->getState() == false ){                   
                    qInfo("Vrai");
                    return true;
                }
            }
        }

         
    }

    qInfo("Faux");
    return false;
}   

bool Evaluation::vt23o(){

    if (scMap["Tank 3"]->getState() == false && scMap["Tank 2"]->getState() == true){
        if (scMap["P31"]->getState() != BROKEN || scMap["P32"]->getState() != BROKEN){
            if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() == false || scMap["Engine3"]->getState() == false){
                qInfo("Vrai");
                return true;
            }
        }
    }

    else if (scMap["Tank 3"]->getState() == true && scMap["Tank 2"]->getState() == false){
        if (scMap["P21"]->getState() != BROKEN || scMap["P22"]->getState() != BROKEN){
            if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() || scMap["Engine3"]->getState() == false){ 
                qInfo("Vrai");
                return true;
            }
        }
        else if (scMap["Tank 1"]->getState() == false){
            if (scMap["P11"]->getState() != BROKEN || scMap["P12"]->getState() != BROKEN){
                if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() == false || scMap["Engine3"]->getState() == false ){                   
                    qInfo("Vrai");
                    return true;
                }
            }
        }

         
    }
    
    qInfo("Faux");
    return false;
} 

bool Evaluation::vt12f(){

    if (scMap["Tank 1"]->getState() == false && scMap["Tank 2"]->getState() == true){
        if (scMap["P11"]->getState() != BROKEN || scMap["P12"]->getState() != BROKEN){
            if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() == false || scMap["Engine3"]->getState() == false){
                qInfo("Vrai");
                return true;
            }
        }
    }

    else if (scMap["Tank 1"]->getState() == true && scMap["Tank 2"]->getState() == false){
        if (scMap["P21"]->getState() != BROKEN || scMap["P22"]->getState() != BROKEN){
            if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() || scMap["Engine3"]->getState() == false){ 
                qInfo("Vrai");
                return true;
            }
        }
        else if (scMap["Tank 3"]->getState() == false){
            if (scMap["P31"]->getState() != BROKEN || scMap["P32"]->getState() != BROKEN){
                if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() == false || scMap["Engine3"]->getState() == false ){                   
                    qInfo("Vrai");
                    return true;
                }
            }
        }

         
    }

    qInfo("Faux");
    return false;
}


