#include "eval.h"
#include <iostream>

Evaluation::Evaluation(SystemeCarburant *systemeC, Log *log_): sc(systemeC), scMap(sc->getMap()),log(log_){
    
    time = new QTimer(this);
    mark = 10;
    mistake_nb = 0;
    QObject::connect(scMap["VT12"], SIGNAL(clickedEval()), this, SLOT(vt12()));
    QObject::connect(scMap["VT23"], SIGNAL(clickedEval()), this, SLOT(vt23()));
    QObject::connect(scMap["V13"], SIGNAL(clickedEval()), this, SLOT(v13()));
    QObject::connect(scMap["V12"], SIGNAL(clickedEval()), this, SLOT(v12()));
    QObject::connect(scMap["V23"], SIGNAL(clickedEval()), this, SLOT(v23()));
    QObject::connect(scMap["P12"], SIGNAL(clickedEval()), this, SLOT(p12()));
    QObject::connect(scMap["P22"], SIGNAL(clickedEval()), this, SLOT(p22()));
    QObject::connect(scMap["P32"], SIGNAL(clickedEval()), this, SLOT(p32()));
 
}

bool Evaluation::vt12(){
    if (scMap["Tank 1"]->getState() == false && scMap["Tank 2"]->getState() == true){
        if (scMap["P11"]->getState() != BROKEN || scMap["P12"]->getState() != BROKEN){
            if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() == false || scMap["Engine3"]->getState() == false){
                //scMap["Tank 1"]->setState(true);
                log->addEvalLog("Correct.");
                return true;
            }
        }
    }

    if (scMap["Tank 1"]->getState() == true && scMap["Tank 2"]->getState() == false){
        if (scMap["P21"]->getState() != BROKEN || scMap["P22"]->getState() != BROKEN){
            if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() || scMap["Engine3"]->getState() == false){ 
                scMap["Tank 2"]->setState(true);
                log->addEvalLog("Correct.");
                return true;
            }
        }
        if (scMap["Tank 3"]->getState() == false){
            if (scMap["P31"]->getState() != BROKEN || scMap["P32"]->getState() != BROKEN){
                if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() == false || scMap["Engine3"]->getState() == false ){                   
                    log->addEvalLog("Correct.");
                    return true;
                }
            }
        }

         
    }

    log->addEvalLog("Tank valve 12 shouldn't be opened.\n -1");
    mark --;
    mistake_nb++;
    return false;
}   

bool Evaluation::vt23(){
    if (scMap["Tank 3"]->getState() == false && scMap["Tank 2"]->getState() == true){
        if (scMap["P31"]->getState() != BROKEN || scMap["P32"]->getState() != BROKEN){
            if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() == false || scMap["Engine3"]->getState() == false){
                scMap["Tank 3"]->setState(true);
                log->addEvalLog("Correct.");
                return true;
            }
        }
    }

    if (scMap["Tank 3"]->getState() == true && scMap["Tank 2"]->getState() == false){
        if (scMap["P21"]->getState() != BROKEN || scMap["P22"]->getState() != BROKEN){
            if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() || scMap["Engine3"]->getState() == false){ 
                scMap["Tank 2"]->setState(true);
                log->addEvalLog("Correct.");
                return true;
            }
        }
        if (scMap["Tank 1"]->getState() == false){
            if (scMap["P11"]->getState() != BROKEN || scMap["P12"]->getState() != BROKEN){
                if (scMap["Engine1"]->getState() == false || scMap["Engine2"]->getState() == false || scMap["Engine3"]->getState() == false ){                   
                    log->addEvalLog("Correct.");
                    return true;
                }
            }
        }    
    }
    log->addEvalLog("Tank valve 23 shouldn't be opened.\n -1");
    mark --;
    mistake_nb++;
    return false;
} 
bool Evaluation::v13(){
    if(!scMap["V13"]->getState()){
//        Engine* e3 = dynamic_cast<Engine*> (scMap["Engine3"]);
//
//        if(e3->getPump()){
//            e3->setState(false);
//            e3->setPump(nullptr);
//        }

        /* ICI, VIRER ENGINE* e3
         * A la place, si pompe12 alimentait engine3, pompe12.setEngine(false),
         * engine3.setPump(nullptr)
         * engine3.setState(false) */
    }

    if (scMap["Tank 1"]->getState() == true && scMap["Engine3"]->getState() == false){
        if (scMap["P12"]->getState() != BROKEN && scMap["P12"]-> getEngine() == false){
            Pump* p12 = dynamic_cast<Pump*> (scMap["P12"]);
            p12->setEngine(true);

            Engine* e3 = dynamic_cast<Engine*> (scMap["Engine3"]);
            e3->setPump(p12);
            e3->setState(true);
            log->addEvalLog("Correct.");
            return true;
        }
    }
    if (scMap["Tank 3"]->getState() == true && scMap["Engine1"]->getState() == false){
        if (scMap["P32"]->getState() != BROKEN && scMap["P32"]-> getEngine() == false){
            Pump* p32 = dynamic_cast<Pump*> (scMap["P32"]);
            p32->setEngine(true);

            Engine* e1 = dynamic_cast<Engine*> (scMap["Engine1"]);
            e1->setPump(p32);
            e1->setState(true);
            log->addEvalLog("Correct.");
            return true;
        }
    }
    log->addEvalLog("Valve 13 shouldn't be opened.\n -1");
    mark --;
    mistake_nb++;
    return false;
} 

bool Evaluation::v12(){
    if (scMap["Tank 1"]->getState() == true && scMap["Engine2"]->getState() == false){
        if (scMap["P12"]->getState() != BROKEN && scMap["P12"]-> getEngine() == false){
            log->addEvalLog("Correct.");
            return true;
        }
    }
    if (scMap["Tank 2"]->getState() == true && scMap["Engine1"]->getState() == false){
        if (scMap["P22"]->getState() != BROKEN && scMap["P22"]-> getEngine() == false){
            log->addEvalLog("Correct.");
            return true;
        }
    }

    log->addEvalLog("Valve 12 shouldn't be opened.\n -1");
    mark --;
    mistake_nb++;
    return false;
} 

bool Evaluation::v23(){

    if (scMap["Tank 2"]->getState() == true && scMap["Engine3"]->getState() == false){
        if (scMap["P22"]->getState() != BROKEN && scMap["P22"]-> getEngine() == false){
            log->addEvalLog("Correct.");
            return true;
        }
    }

    if (scMap["Tank 3"]->getState() == true && scMap["Engine2"]->getState() == false){
        if (scMap["P32"]->getState() != BROKEN && scMap["P32"]-> getEngine() == false){
            log->addEvalLog("Correct.");
            return true;

        }
    }
    log->addEvalLog("Valve 23 shouldn't be opened.\n -1");
    mark --;
    mistake_nb++;
    return false;
} 

bool Evaluation::p12(){

    if(scMap["P12"] -> getState() == OFF){
        if (scMap["Tank 1"]->getState() == true){
            
            if(scMap["Engine1"]->getState() == false){
                log->addEvalLog("Correct.");
                return true;
            }
            else if (scMap["Engine2"]-> getState() == false && scMap["V12"]->getState() == true){
                log->addEvalLog("Correct.");
                return true;
            }
            else if (scMap["Engine3"]-> getState() == false && scMap["V13"]->getState() == true){
                log->addEvalLog("Correct.");
                return true;
            }
        }

        log->addEvalLog("Pump 12 shouldn't be activated.\n -1");
        mark --;
        mistake_nb++;
        return false;
    }
    else return true;
} 

bool Evaluation::p22(){

    if(scMap["P12"] -> getState() == OFF){
        if (scMap["Tank 2"]->getState() == true){
            
            if(scMap["Engine2"]->getState() == false){
                qInfo("True");
                log->addEvalLog("Correct.");
                return true;
            }
            else if (scMap["Engine1"]-> getState() == false && scMap["V12"]->getState() == true){
                qInfo("True");
                log->addEvalLog("Correct.");
                return true;
            }
            else if (scMap["Engine3"]-> getState() == false && scMap["V23"]->getState() == true){
                qInfo("True");
                log->addEvalLog("Correct.");
                return true;
            }
        }
    
        log->addEvalLog("Pump 22 shouldn't be activated.\n -1");
        mark --;
        mistake_nb++;
        return false;
    }
    else return true;
} 

bool Evaluation::p32(){
    
    if(scMap["P12"] -> getState() == OFF){
        if (scMap["Tank 3"]->getState() == true){
            
            if(scMap["Engine3"]->getState() == false){
                log->addEvalLog("Correct.");
                return true;
            }
            else if (scMap["Engine2"]-> getState() == false && scMap["V23"]->getState() == true){
                log->addEvalLog("Correct.");
                return true;
            }
            else if (scMap["Engine1"]-> getState() == false && scMap["V13"]->getState() == true){
                log->addEvalLog("Correct.");
                return true;
            }
        }
    
        log->addEvalLog("Pump 32 shouldn't be activated.\n -1");
        mark --;
        mistake_nb++;
        return false;
    }
    else return true;
} 

bool Evaluation::resolved(){

    if (scMap["Engine1"]->getState() == true && scMap["Engine2"]->getState() == true && scMap["Engine3"]->getState() == true){
         
        return true;
    }
    return false;
} 

int Evaluation::getMark(){
    return mark;
}

int Evaluation::getMistakeNumber(){
    return mistake_nb;
}
