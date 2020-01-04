#include "affichage.h"

// WIDGETS TO DRAW

// GENERIC CLASS

// TANKS
    Tank::Tank(QString name,Pump* primaryP,Pump* secondaryP)
        : primaryPump(primaryP), secondaryPump(secondaryP){
        this->name = name;
        state = true;
        setFixedWidth(TANK_WIDTH);
        setFixedHeight(TANK_HEIGHT);
        setEnabled(true);
    }

    void Tank::paintEvent(QPaintEvent*) {
        QPainter p(this);

        // rect
        if(state){
            p.setBrush(QBrush(Qt::green));
        } else{
            p.setBrush(QBrush(Qt::red));
        }
        p.drawRect(0, 0, TANK_WIDTH-10, TANK_HEIGHT-10);

        // texte
        p.setBrush(QBrush(Qt::black));
        QFont font("Arial", 12);
        font.setWeight(QFont::Bold);
        p.setFont(font);
        p.drawText(rect(), Qt::AlignHCenter, name);
    }

    void Tank::switchState(bool state) {
        if(state)
            this->state = true;
        else{
            this->state = false;

            if(primaryPump->getState() || secondaryPump->getState()){
                // afficher message "Caution : tank " + name + " emptied,
                // its pumps aren't doing nothing in this state.
                // Try to refill the tank by opening the associated valve"
            }

            primaryPump->switchState(OFF);
            secondaryPump->switchState(OFF);
        }

        emit updateLastEntry();
        update();
    }

    void Tank::clickedSlot(){
        emit clickedEval();
        emit GenericTpev::updateLastEntry();

        if(state)
            switchState(false);
        else
            switchState(true);

        emit GenericTpev::clickedLog(name);
    }

    void Tank::empty() {
        switchState(false);
    }

    short Tank::getState() {
        return state;
    }

    void Tank::setState(short state) {
        if(state && !this->state){
            this->state = true;
            update();
        }
    }

    Pump* Tank::getPrimaryPump() {
        return primaryPump;
    }

    Pump* Tank::getSecondaryPump() {
        return secondaryPump;
    }

// PUMPS
    Pump::Pump(QString name, Tank* _tank, Engine* supplyingE, bool primary)
        : tank(_tank){
        this->name = name;
        this->supplyingEngine = supplyingE;
        this->primary = primary;
        setFixedWidth(PUMP_RAY*2);
        setFixedHeight(PUMP_RAY*2);

        if(supplyingEngine != nullptr) state = ON;
        else state = OFF;
    }

    short Pump::getState(){
        return state;
    }

    void Pump::setState(short state) {
        switch(state){
            case 0 :
                this->state = OFF;
                break;
            case 1 :
                this->state = ON;
                break;
            default:
                this->state = BROKEN;
                break;
        }
    }

    Engine* Pump::getEngine(){
        return supplyingEngine;
    }

    void Pump::setEngine(Engine* engine){
        supplyingEngine = engine;
    }

    void Pump::setTank(Tank *tank) {
        this->tank = tank;
    }

    const Tank& Pump::getTank() {
        return *tank;
    }

    void Pump::switchState(pumpState state) {
        Engine* tmpE = getEngine();

        if(state == ON){
            if(tank->getState()){
                this->state = state;
                if(primary){
                    assert(tmpE);
                    Pump* tmpP = tmpE->getPump();

                    if(tmpP != nullptr){
                        tmpP->setEngine(nullptr);
                        // afficher message
                        // "CAUTION : pump " + tmpp.name + " doesn't supply " + tmpe.name + " anymore !"
                    }

                    tmpE->setPump(this);
                    tmpE->setState(true);
                }
            }
        } else{
            this->state = state;

            if(tmpE != nullptr){
                // engine no longer supplied
                // afficher message
                // "CAUTION : pump " + name + " doesn't supply " + tmpe.name + " anymore !"
                // if pump secondary, set engineSupplied to null
                if(!primary){
                    tmpE->setPump(nullptr);
                    tmpE->setState(false);
                    setEngine(nullptr);
                } else if (tmpE->getPump() == this){
                    tmpE->setPump(nullptr);
                    tmpE->setState(false);
                }
            }
        }

        emit updateLastEntry();
        update();
    }

    void Pump::setBroken(){
        switchState(BROKEN);
    }

    void Pump::paintEvent(QPaintEvent*){
        QPainter p(this);
        if(state == OFF)
            p.setBrush(QBrush(Qt::red));
        else if(state == ON)
            p.setBrush(QBrush(Qt::green));
        else
            p.setBrush(QBrush(Qt::gray));

        // contour
        p.drawEllipse(rect().topLeft().rx(), rect().topLeft().ry(), PUMP_RAY*2 - 2, PUMP_RAY*2 -2);

        // texte
        p.drawText(rect(), Qt::AlignCenter, name);
    }

    void Pump::clickedSlot(){
        emit clickedEval();
        emit updateLastEntry();

        switch(state){
            case ON :
                switchState(OFF);
                break;
            case OFF :
                switchState(BROKEN);
                break;
            case BROKEN :
                switchState(ON);
                break;
            default:
                break;
        }

        emit GenericTpev::clickedLog(name);
        update();
    }

// ENGINES
    Engine::Engine(QString name,Pump* supplyingP){
        this->name = name;
        this->supplyingPump = supplyingP;
        state = true;
        setFixedWidth(TANK_WIDTH);
        setFixedHeight(TANK_HEIGHT);
    }

    short Engine::getState() {
        return state;
    }

    void Engine::setState(short state) {
        this->state = state;
        update();
    }

    Pump* Engine::getPump() {
        return supplyingPump;
    }

    void Engine::setPump(Pump* supplyingP) {
        supplyingPump = supplyingP;
    }

    void Engine::paintEvent(QPaintEvent *) {
        QPainter p(this);

        // rect
        if(state)
            p.setBrush(QBrush(Qt::green));
        else
            p.setBrush(QBrush(Qt::red));

        p.drawRect(0, 0, TANK_WIDTH-10, TANK_HEIGHT-10);

        // texte
        p.setBrush(QBrush(Qt::black));
        QFont font("Arial", 12);
        font.setWeight(QFont::Bold);
        p.setFont(font);
        p.drawText(rect(), Qt::AlignCenter, name);
    }

// VALVES
    Valve::Valve(const QString name) {
        this->name = name;
        state = false;
        setFixedWidth(VALVE_RAY*2);
        setFixedHeight(VALVE_RAY*2);
    }

    short Valve::getState() {
        return state;
    }

    void Valve::setState(short state) {
        this->state = state;
    }

    void Valve::paintEvent(QPaintEvent *) {
        QPainter p(this);

        // texte
        QFont font("Arial", 12);
        font.setWeight(QFont::Bold);
        p.setFont(font);
        p.drawText(rect(), Qt::AlignTop | Qt::AlignHCenter, name);

        // circle
        p.setBrush(QBrush(Qt::black));
        QPoint center(rect().center().rx(), rect().center().ry());
        p.drawEllipse(center, VALVE_RAY/2, VALVE_RAY/2);

        // line
        if(!state){
            p.setBrush(QBrush(Qt::white));
            p.drawRect(rect().center().rx()-3, rect().center().ry() - VALVE_RAY/2, 6,VALVE_RAY);
        } else{
            p.setBrush(QBrush(Qt::white));
            p.drawRect(rect().center().rx()-VALVE_RAY/2, rect().center().ry() - 3, VALVE_RAY, 6);
        }
    }

    // VALVE TANK
    ValveTank::ValveTank(QString name, Tank* const _t1, Tank* const _t2)
        : Valve(name), t1(_t1), t2(_t2){
    }

    void ValveTank::clickedSlot(){

        emit updateLastEntry();
        if(state)
            state = false;
        else{
            emit clickedEval();
            state = true;
            if(t1->getState() && !t2->getState()){
                t2->setState(true);
            } else if(t2->getState() && !t1->getState()){
                t1->setState(true);
            }
        }

        emit GenericTpev::clickedLog(name);
        update();
    }

    // VALVE ENGINE
    ValveEngine::ValveEngine(QString name, Tank* t1, Engine* e1,Tank* t2, Engine* e2)
        : Valve(name){
        pair1.first = t1;
        pair1.second = e1;
        pair2.first = t2;
        pair2.second = e2;
    }

    void ValveEngine::switchEngineState(QPair<Tank*, Engine*>& pair, bool state){
        if(!state){
            Pump* const tmpP = pair.second->getPump();

            if(tmpP != nullptr) {
                if (tmpP == pair.first->getSecondaryPump()) {
                    pair.second->setPump(nullptr);
                    pair.second->setState(false);
                    tmpP->setEngine(nullptr);
                    // afficher message
                    // "CAUTION :
                    // pump " + tmpP.name + " doesn't supply " + pair1.second.getName + " anymore !"                }
                }
            }
        } else{
            if(pair.second->getPump() == nullptr){
                Pump* tmpP = pair.first->getSecondaryPump();
                if(tmpP->getEngine() == nullptr && tmpP->getState() == ON){
                    pair.second->setState(true);
                    pair.second->setPump(tmpP);
                    tmpP->setEngine(pair.second);
                }
            }
        }
    }

    void ValveEngine::clickedSlot() {
        emit updateLastEntry();

        if (state) {
            state = false;
            switchEngineState(pair1, false);
            switchEngineState(pair2, false);
        } else{
            state = true;
            switchEngineState(pair1, true);
            switchEngineState(pair2, true);
        }


        emit GenericTpev::clickedLog(name);
        update();
    }