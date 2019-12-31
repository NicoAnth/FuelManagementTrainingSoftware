#include "eval.h"
#include <iostream>

Evaluation::Evaluation(SystemeCarburant *systemeC): sc(systemeC), scMap(sc->getMap()){
    
    time = new QTimer(this);
    mark = 10;
    mistake_nb = 0;
    QObject::connect(scMap["VT12"], SIGNAL(clicked()), this, SLOT(vt12()));
    QObject::connect(scMap["VT23"], SIGNAL(clicked()), this, SLOT(vt23()));
    QObject::connect(scMap["V13"], SIGNAL(clicked()), this, SLOT(v13()));
    QObject::connect(scMap["V12"], SIGNAL(clicked()), this, SLOT(v12()));
    QObject::connect(scMap["V23"], SIGNAL(clicked()), this, SLOT(v23()));
    QObject::connect(scMap["P12"], SIGNAL(clicked()), this, SLOT(p12()));
    QObject::connect(scMap["P22"], SIGNAL(clicked()), this, SLOT(p22()));
    QObject::connect(scMap["P32"], SIGNAL(clicked()), this, SLOT(p32()));
 
}

bool Evaluation::vt12(){

    if (scMap["Tank 1"]->getState() == false && scMap["Tank 2"]->getState() == true){
        if (scMap["P11"]->getState() != BROKEN || scMap["P12"]->getState() != BROKEN){
            if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() == false || scMap["Engine3"]->getState() == false){
                qInfo("Vrai");
                return true;
            }
        }
    }

    if (scMap["Tank 1"]->getState() == true && scMap["Tank 2"]->getState() == false){
        if (scMap["P21"]->getState() != BROKEN || scMap["P22"]->getState() != BROKEN){
            if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() || scMap["Engine3"]->getState() == false){ 
                qInfo("Vrai");
                return true;
            }
        }
        if (scMap["Tank 3"]->getState() == false){
            if (scMap["P31"]->getState() != BROKEN || scMap["P32"]->getState() != BROKEN){
                if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() == false || scMap["Engine3"]->getState() == false ){                   
                    qInfo("Vrai");
                    return true;
                }
            }
        }

         
    }

    qInfo("Faux");
    mark --;
    mistake_nb++;
    return false;
}   

bool Evaluation::vt23(){

    if (scMap["Tank 3"]->getState() == false && scMap["Tank 2"]->getState() == true){
        if (scMap["P31"]->getState() != BROKEN || scMap["P32"]->getState() != BROKEN){
            if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() == false || scMap["Engine3"]->getState() == false){
                qInfo("Vrai");
                return true;
            }
        }
    }

    if (scMap["Tank 3"]->getState() == true && scMap["Tank 2"]->getState() == false){
        if (scMap["P21"]->getState() != BROKEN || scMap["P22"]->getState() != BROKEN){
            if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() || scMap["Engine3"]->getState() == false){ 
                qInfo("Vrai");
                return true;
            }
        }
        if (scMap["Tank 1"]->getState() == false){
            if (scMap["P11"]->getState() != BROKEN || scMap["P12"]->getState() != BROKEN){
                if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() == false || scMap["Engine3"]->getState() == false ){                   
                    qInfo("Vrai");
                    return true;
                }
            }
        }    
    }
    qInfo("Faux");
    mark --;
    mistake_nb++;
    return false;
} 
bool Evaluation::v13(){

    if (scMap["Tank 1"]->getState() == true && scMap["Engine3"]->getState() == false){
        if (scMap["P12"]->getState() != BROKEN && scMap["P12"]-> getEngine() == false){
            qInfo("True");
            return true;
        }
    }
    if (scMap["Tank 3"]->getState() == true && scMap["Engine1"]->getState() == false){
        if (scMap["P32"]->getState() != BROKEN && scMap["P32"]-> getEngine() == false){
            qInfo("True");
            return true;
        }
    }
    qInfo("Faux");
    mark --;
    mistake_nb++;
    return false;
} 

bool Evaluation::v12(){

    if (scMap["Tank 1"]->getState() == true && scMap["Engine2"]->getState() == false){
        if (scMap["P12"]->getState() != BROKEN && scMap["P12"]-> getEngine() == false){
            qInfo("True");
            return true;
        }
    }
    if (scMap["Tank 2"]->getState() == true && scMap["Engine1"]->getState() == false){
        if (scMap["P22"]->getState() != BROKEN && scMap["P22"]-> getEngine() == false){
            qInfo("True");
            return true;
        }
    }

    qInfo("Faux");
    mark --;
    mistake_nb++;
    return false;
} 

bool Evaluation::v23(){

    if (scMap["Tank 2"]->getState() == true && scMap["Engine3"]->getState() == false){
        if (scMap["P22"]->getState() != BROKEN && scMap["P22"]-> getEngine() == false){
            qInfo("True");
            return true;
        }
    }

    if (scMap["Tank 3"]->getState() == true && scMap["Engine2"]->getState() == false){
        if (scMap["P32"]->getState() != BROKEN && scMap["P32"]-> getEngine() == false){
            qInfo("True");
            return true;
        }
    }
    qInfo("Faux");
    mark --;
    mistake_nb++;
    return false;
} 

bool Evaluation::p12(){

    if (scMap["Tank 1"]->getState() == true){
        
        if(scMap["Engine1"]->getState() == false){
            qInfo("True");
            return true;
        }
        else if (scMap["Engine2"]-> getState() == false && scMap["V12"]->getState() == true){
            qInfo("True");
            return true;
        }
        else if (scMap["Engine3"]-> getState() == false && scMap["V13"]->getState() == true){
            qInfo("True");
            return true;
        }
    }

    qInfo("Faux");
    mark --;
    mistake_nb++;
    return false;
} 

bool Evaluation::p22(){

    if (scMap["Tank 2"]->getState() == true){
        
        if(scMap["Engine2"]->getState() == false){
            qInfo("True");
            return true;
        }
        else if (scMap["Engine1"]-> getState() == false && scMap["V12"]->getState() == true){
            qInfo("True");
            return true;
        }
        else if (scMap["Engine3"]-> getState() == false && scMap["V23"]->getState() == true){
            qInfo("True");
            return true;
        }
    }

    qInfo("Faux");
    mark --;
    mistake_nb++;
    return false;
} 

bool Evaluation::p32(){

    if (scMap["Tank 3"]->getState() == true){
        
        if(scMap["Engine3"]->getState() == false){
            qInfo("True");
            return true;
        }
        else if (scMap["Engine2"]-> getState() == false && scMap["V23"]->getState() == true){
            qInfo("True");
            return true;
        }
        else if (scMap["Engine1"]-> getState() == false && scMap["V13"]->getState() == true){
            qInfo("True");
            return true;
        }
    }

    qInfo("Faux");
    mark --;
    mistake_nb++;
    return false;
} 

int Evaluation::getMark(){
    return mark;
}

int Evaluation::getMistakeNumber(){
    return mistake_nb;
}
