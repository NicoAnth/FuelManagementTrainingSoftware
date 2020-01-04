#include <QLayout>
#include <QPainter>
#include <QMouseEvent>
#include <QListWidget>
#include <QSizePolicy>
#include <QMenuBar>
#include <QDir>
#include <QFileSystemModel>
#include <QTreeView>
#include <QFileDialog>
#include "affichage.h"
#include <iostream>
#include "Log.h"
#include "eval.h"
#include "connexion.h"

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

    void Tank::clickedSlot(){
        emit clickedEval();
        emit clickedLog();

        if(!state){
            state = true;
        } else{
            state = false;
            if(primaryPump->getState() || secondaryPump->getState()){
                // afficher message "Caution : tank " + name + " emptied,
                // its pumps aren't doing nothing in this state.
                // Try to refill the tank by opening the associated valve"
            }

            primaryPump->switchState(OFF);
            secondaryPump->switchState(OFF);
        }

        emit GenericTpev::stateChanged(name);
        update();
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
    Pump::Pump(QString name, Engine* supplyingE, bool primary) {
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

    void Pump::switchState(pumpState state) {
        this->state = state;
        Engine* tmpE = getEngine();

        if(state == ON){
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
        } else{
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
        emit clickedLog();

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
                std::cerr << "unrecognized pump state" << std::endl;
                break;
        }

        emit GenericTpev::stateChanged(name);
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
        emit clickedLog();

        if(state)
            state = false;
        else{
            state = true;
            if(t1->getState() && !t2->getState()){
                t2->setState(true);
            } else if(t2->getState() && !t1->getState()){
                t1->setState(true);
            }
        }

        emit clickedEval();
        emit GenericTpev::stateChanged(name);
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
                if(tmpP->getEngine() == nullptr && tmpP->getState()){
                    pair.second->setState(true);
                    pair.second->setPump(tmpP);
                    tmpP->setEngine(pair.second);
                }
            }
        }
    }

    void ValveEngine::clickedSlot() {
        emit clickedLog();

        if (state) {
            state = false;
            switchEngineState(pair1, false);
            switchEngineState(pair2, false);
        } else{
            state = true;
            switchEngineState(pair1, true);
            switchEngineState(pair2, true);
        }

        emit clickedEval();
        emit GenericTpev::stateChanged(name);
        update();
    }


// SYSTEME CARBURANT WINDOW
    SystemeCarburant::SystemeCarburant(int width, int height) {
        // Params mains window
        this->setMinimumWidth(width);
        this->setMinimumHeight(height);

        // Widgets to draw
        engine1 = new Engine("Engine 1",nullptr);
        engine2 = new Engine("Engine 2",nullptr);
        engine3 = new Engine("Engine 3",nullptr);
        pump11 = new Pump("P11",engine1, true);
        pump12 = new Pump("P12",nullptr, false);
        pump21 = new Pump( "P21",engine2, true);
        pump22 = new Pump("P22",nullptr, false);
        pump31 = new Pump("P31",engine3, true);
        pump32 = new Pump("P32",nullptr, false);
        engine1->setPump(pump11);
        engine2->setPump(pump21);
        engine3->setPump(pump31);
        tank1 = new Tank("Tank 1", pump11, pump12);
        tank2 = new Tank("Tank 2", pump21, pump22);
        tank3 = new Tank("Tank 3", pump31, pump32);

        vt12 = new ValveTank("VT12", tank1, tank2);
        vt23 = new ValveTank("VT23", tank2, tank3);
        v12 = new ValveEngine("V12", tank1, engine2, tank2, engine1);
        v13 = new ValveEngine("V13", tank1, engine3, tank3, engine1);
        v23 = new ValveEngine("V23", tank2, engine3, tank3, engine2);

        tpevMap["Tank 1"] = tank1;
        tpevMap["Tank 2"] = tank2;
        tpevMap["Tank 3"] = tank3;
        tpevMap["P11"] = pump11;
        tpevMap["P12"] = pump12;
        tpevMap["P21"] = pump21;
        tpevMap["P22"] = pump22;
        tpevMap["P31"] = pump31;
        tpevMap["P32"] = pump32;
        tpevMap["Engine1"] = engine1;
        tpevMap["Engine2"] = engine2;
        tpevMap["Engine3"] = engine3;
        tpevMap["VT12"] = vt12;
        tpevMap["VT23"] = vt23;
        tpevMap["V12"] = v12;
        tpevMap["V13"] = v13;
        tpevMap["V23"] = v23;

        // DashBoard buttons
        vtdb1 = new QPushButton("VT12");
        vtdb2 = new QPushButton("VT23");
        pdb1 = new QPushButton("P12");
        pdb2 = new QPushButton("P22");
        pdb3 = new QPushButton("P32");
        vdb1 = new QPushButton("V12");
        vdb2 = new QPushButton("V13");
        vdb3 = new QPushButton("V23");

        // Layouts
        QVBoxLayout* mainLayout = new QVBoxLayout;
        QHBoxLayout* tankLayout = new QHBoxLayout;
        QHBoxLayout* pumpLayout1 = new QHBoxLayout;
        QHBoxLayout* pumpLayout2 = new QHBoxLayout;
        QHBoxLayout* pumpLayout3 = new QHBoxLayout;
        QHBoxLayout* engineLayout = new QHBoxLayout;
        QVBoxLayout* mainDashBoardLayout = new QVBoxLayout;
        QHBoxLayout* vtDashBoardLayout = new QHBoxLayout;
        QHBoxLayout* pumpDashBoardLayout = new QHBoxLayout;
        QHBoxLayout* valveDashBoardLayout = new QHBoxLayout;

        // add layouts to layouts
        tank1->setLayout(pumpLayout1);
        tank2->setLayout(pumpLayout2);
        tank3->setLayout(pumpLayout3);
        this->setLayout(mainLayout);
        mainLayout->addLayout(tankLayout);
        mainLayout->addLayout(engineLayout);
        mainLayout->addLayout(mainDashBoardLayout);
        mainDashBoardLayout -> addLayout(vtDashBoardLayout);
        mainDashBoardLayout -> addLayout(pumpDashBoardLayout);
        mainDashBoardLayout -> addLayout(valveDashBoardLayout);

        // add widgets to layouts
        v12->setParent(this);
        v13->setParent(this);
        v23->setParent(this);
        tankLayout->addWidget(tank1);
        tankLayout->addWidget(vt12);
        tankLayout->addWidget(tank2);
        tankLayout->addWidget(vt23);
        tankLayout->addWidget(tank3);
        pumpLayout1->addWidget(pump11);
        pumpLayout1->addWidget(pump12);
        pumpLayout2->addWidget(pump21);
        pumpLayout2->addWidget(pump22);
        pumpLayout3->addWidget(pump31);
        pumpLayout3->addWidget(pump32);
        engineLayout->addWidget(engine1);
        engineLayout->addWidget(engine2);
        engineLayout->addWidget(engine3);

        vtDashBoardLayout->addWidget(vtdb1);
        vtDashBoardLayout->addWidget(vtdb2);
        pumpDashBoardLayout->addWidget(pdb1);
        pumpDashBoardLayout->addWidget(pdb2);
        pumpDashBoardLayout->addWidget(pdb3);
        valveDashBoardLayout->addWidget(vdb1);
        valveDashBoardLayout->addWidget(vdb2);
        valveDashBoardLayout->addWidget(vdb3);

        // Layout params spacing and alignment
        mainLayout->setAlignment(tankLayout, Qt::AlignTop | Qt::AlignHCenter);
        mainLayout->setAlignment(engineLayout, Qt::AlignBottom | Qt::AlignHCenter);
        engineLayout->setSpacing(SPACING);

       // Signals clics on widgets
       for(auto it = tpevMap.cbegin(); it != tpevMap.cend(); it++){
           QObject::connect(it.value(), SIGNAL(clicked()), it.value(), SLOT(clickedSlot()));
       }

        //Dashboard clics on signals
        QObject::connect(vtdb1, SIGNAL(clicked()), vt12, SLOT(clickedSlot()));
        QObject::connect(vtdb2, SIGNAL(clicked()), vt23, SLOT(clickedSlot()));
        QObject::connect(pdb1, SIGNAL(clicked()), pump12, SLOT(clickedSlot()));
        QObject::connect(pdb2, SIGNAL(clicked()), pump22, SLOT(clickedSlot()));
        QObject::connect(pdb3, SIGNAL(clicked()), pump32, SLOT(clickedSlot()));
        QObject::connect(vdb1, SIGNAL(clicked()), v12, SLOT(clickedSlot()));
        QObject::connect(vdb2, SIGNAL(clicked()), v13, SLOT(clickedSlot()));
        QObject::connect(vdb3, SIGNAL(clicked()), v23, SLOT(clickedSlot()));
    }

    QMap<QString, GenericTpev*>& SystemeCarburant::getMap() {
        return tpevMap;
    }

    void SystemeCarburant::setMap(const QMap <QString, qint32> &logMap) {
        for(auto it = logMap.cbegin(); it!=logMap.cend(); it++){
            tpevMap[it.key()]->setState(it.value());
        }
    }

    QMap<QString, qint32>& SystemeCarburant::getLastEntry() {
        return lastLogEntry;
    }

    void SystemeCarburant::setLastEntry(const QMap<QString, qint32>& entry){
        lastLogEntry = entry;
    }

// PAINT EVENT WINDOW
    void SystemeCarburant::paintEvent(QPaintEvent *) {
        QPainter p(this);

        // Lines
        int xleft, xcenter, xright;
        xcenter = width()/2;
        xleft = xcenter - TANK_WIDTH - 2*VALVE_RAY;
        xright = xcenter + TANK_WIDTH + 2*VALVE_RAY;

        // Tanks and engines
        p.drawLine(xleft, TANK_HEIGHT/2 + 10, xright, TANK_HEIGHT/2 + 10);  // between tanks
        p.drawLine(xleft, 3*TANK_HEIGHT, xleft - 20, 3*TANK_HEIGHT); // t1 e1 horizontal
        p.drawLine(xleft - 20, 3*TANK_HEIGHT, xleft - 20, height() - 2*TANK_HEIGHT);   // t1 e1 vertical
        p.drawLine(xcenter, TANK_HEIGHT/2 + 10, xcenter, height() - 2*TANK_HEIGHT);     // t2 e2

        // Valve lines
        v12->setGeometry(width()/2 - TANK_WIDTH, 3.5*TANK_HEIGHT, VALVE_RAY*2, VALVE_RAY*2);
        v13->setGeometry(width()/2 + TANK_WIDTH/2, 3*TANK_HEIGHT/2, VALVE_RAY*2, VALVE_RAY*2);
        v23->setGeometry(width()/2 + TANK_WIDTH/2, 4*TANK_HEIGHT, VALVE_RAY*2, VALVE_RAY*2);

        p.drawLine(xleft, TANK_HEIGHT/2 + 10, xleft, 4*TANK_HEIGHT);    // v12 vertical
        p.drawLine(xleft, 4*TANK_HEIGHT, xcenter, 4*TANK_HEIGHT);   // v12 horizontal
        p.drawLine(xright, 4.5*TANK_HEIGHT, xcenter, 4.5*TANK_HEIGHT);  // v23 horizontal
        p.drawLine(xright, TANK_HEIGHT/2 + 10, xright, 4.5*TANK_HEIGHT);   // v23 vertical
        p.drawLine(xleft, 2*TANK_HEIGHT, xright + 20, 2*TANK_HEIGHT);    // v13 horizontal
        p.drawLine(xright + 20, 2*TANK_HEIGHT, xright + 20, height() - 2*TANK_HEIGHT);   // v13 vertical
    }
