//
// Created by user on 04/01/2020.
//

#include "SystemeCarburant.h"

// SYSTEME CARBURANT WINDOW
SystemeCarburant::SystemeCarburant(int width, int height) {
    // Params mains window
    this->setMinimumWidth(width);
    this->setMinimumHeight(height);

    // Widgets to draw
    engine1 = new Engine("Engine 1", nullptr);
    engine2 = new Engine("Engine 2", nullptr);
    engine3 = new Engine("Engine 3", nullptr);
    pump11 = new Pump("P11", nullptr, engine1, true);
    pump12 = new Pump("P12", nullptr, nullptr, false);
    pump21 = new Pump( "P21", nullptr, engine2, true);
    pump22 = new Pump("P22", nullptr, nullptr, false);
    pump31 = new Pump("P31", nullptr, engine3, true);
    pump32 = new Pump("P32",nullptr, nullptr, false);
    engine1->setPump(pump11);
    engine2->setPump(pump21);
    engine3->setPump(pump31);
    tank1 = new Tank("Tank 1", pump11, pump12);
    tank2 = new Tank("Tank 2", pump21, pump22);
    tank3 = new Tank("Tank 3", pump31, pump32);
    pump11->setTank(tank1);
    pump12->setTank(tank1);
    pump21->setTank(tank2);
    pump22->setTank(tank2);
    pump31->setTank(tank3);
    pump32->setTank(tank3);

    vt12 = new ValveTank("VT12", tank1, tank2, tank3, nullptr);
    vt23 = new ValveTank("VT23", tank2, tank3, tank1, vt12);
    vt12->setVt2(vt23);
    vt23->setVt2(vt12);
    v12 = new ValveEngine("V12", tank1, engine2, tank2, engine1);
    v13 = new ValveEngine("V13", tank1, engine3, tank3, engine1);
    v23 = new ValveEngine("V23", tank2, engine3, tank3, engine2);
    tank1->setVe1(v12);
    tank1->setVe2(v13);
    tank2->setVe1(v12);
    tank2->setVe2(v23);
    tank3->setVe1(v13);
    tank3->setVe2(v23);

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
        QObject::connect(it.value(), SIGNAL(updateLastEntry()), this, SLOT(updateLastEntry()));
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

void SystemeCarburant::updateLastEntry() {
    for(auto it = tpevMap.cbegin(); it != tpevMap.cend(); it++){
        lastLogEntry[it.key()] = it.value()->getState();
    }
}
