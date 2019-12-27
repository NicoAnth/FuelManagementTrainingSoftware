//
// Created by user on 27/10/2019.
//

#include <QLayout>
#include <QPainter>
#include <QPushButton>
#include <QMouseEvent>
#include <QSizePolicy>
#include "affichage.h"
#include <iostream>

// WIDGETS TO DRAW
// TANKS
    TankShape::TankShape(QString name) {
        this->name = name;
        state = FULL;
        setFixedWidth(TANK_WIDTH);
        setFixedHeight(TANK_HEIGHT);
        setEnabled(true);
    }

    void TankShape::paintEvent(QPaintEvent*) {
        QPainter p(this);

        // rect
        if(state == FULL){
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

    void TankShape::mousePressEvent(QMouseEvent*){
        if(state == FULL) state = EMPTY;
        else state = FULL;

        emit tankStateChanged(state);
        update();
    }

    void TankShape::setState(valveState state) {
        if(state == CLOSED && this->state == EMPTY){
            this->state = FULL;
            emit tankStateChanged(this->state);
            update();
        }
    }

// PUMPS
    PumpShape::PumpShape(enginePowered engine, QString name) {
        this->name = name;
        setFixedWidth(PUMP_RAY*2);
        setFixedHeight(PUMP_RAY*2);

        if(engine) state = ON;
        else state = OFF;
    }

    pumpState PumpShape::getState(){
        return state;
    }

    enginePowered PumpShape::getEngine(){
        return engine;
    }

    void PumpShape::setEngine(enginePowered engine){
        this->engine = engine;
    }

    void PumpShape::paintEvent(QPaintEvent*){
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

    void PumpShape::mousePressEvent(QMouseEvent*){
        short emitState = 0;

        switch(state){
            case ON :
                emitState--;
                state = OFF;
                break;
            case OFF :
                emitState += 2;
                state = BROKEN;
                break;
            case BROKEN :
                emitState--;
                state = ON;
                break;
            default:
                std::cerr << "unrecognized pump state" << std::endl;
                break;
        }

        emit stateChanged(emitState);
        update();
    }

// ENGINES
    EngineShape::EngineShape(QString name){
        this->name = name;
        setFixedWidth(TANK_WIDTH);
        setFixedHeight(TANK_HEIGHT);
    }

    void EngineShape::paintEvent(QPaintEvent *) {
        QPainter p(this);

        // rect
        p.setBrush(QBrush(Qt::gray));
        p.drawRect(0, 0, TANK_WIDTH-10, TANK_HEIGHT-10);

        // texte
        p.setBrush(QBrush(Qt::black));
        QFont font("Arial", 12);
        font.setWeight(QFont::Bold);
        p.setFont(font);
        p.drawText(rect(), Qt::AlignCenter, name);
    }

// VALVES
    ValveShape::ValveShape(const QString name) {
        this->name = name;
        tankStateCount = 2;
        state = OPENED;
        stateChangeable = true;
        setFixedWidth(VALVE_RAY*2);
        setFixedHeight(VALVE_RAY*2);
    }

    void ValveShape::paintEvent(QPaintEvent *) {
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
        if(state == OPENED){
            p.setBrush(QBrush(Qt::white));
            p.drawRect(rect().center().rx()-3, rect().center().ry() - VALVE_RAY/2, 6,VALVE_RAY);
        } else{
            p.setBrush(QBrush(Qt::white));
            p.drawRect(rect().center().rx()-VALVE_RAY/2, rect().center().ry() - 3, VALVE_RAY, 6);
        }
    }

    void ValveShape::mousePressEvent(QMouseEvent *) {
        if(stateChangeable){
            (state == OPENED) ? state = CLOSED : state = OPENED;
            emit valveStateChanged(state);
            update();
        }
    }


// MAIN WINDOW
    SystemeCarburantWindow::SystemeCarburantWindow(int width, int height) {
        // Params mains window
        this->setMinimumWidth(width);
        this->setMinimumHeight(height);

        // Widgets to draw
        TankShape* tank1 = new TankShape("Tank 1");
        TankShape* tank2 = new TankShape("Tank 2");
        TankShape* tank3 = new TankShape("Tank 3");
        PumpShape* pump11 = new PumpShape(ENGINE1, "P11");
        PumpShape* pump12 = new PumpShape(NONE, "P12");
        PumpShape* pump21 = new PumpShape(ENGINE2, "P21");
        PumpShape* pump22 = new PumpShape(NONE, "P22");
        PumpShape* pump31 = new PumpShape(ENGINE3, "P31");
        PumpShape* pump32 = new PumpShape(NONE, "P32");
        TankShape* engine1 = new TankShape("Engine 1");
        TankShape* engine2 = new TankShape("Engine 2");
        TankShape* engine3 = new TankShape("Engine 3");
        ValveShape* vt12 = new ValveShape("VT12");
        ValveShape* vt23 = new ValveShape("VT23");
        v12 = new ValveShape("V12");
        v13 = new ValveShape("V13");
        v23 = new ValveShape("V23");

        // Layouts
        QVBoxLayout* mainLayout = new QVBoxLayout;
        QHBoxLayout* tankLayout = new QHBoxLayout;
        QHBoxLayout* pumpLayout1 = new QHBoxLayout;
        QHBoxLayout* pumpLayout2 = new QHBoxLayout;
        QHBoxLayout* pumpLayout3 = new QHBoxLayout;
        QHBoxLayout* engineLayout = new QHBoxLayout;

        // add layouts to layouts
        tank1->setLayout(pumpLayout1);
        tank2->setLayout(pumpLayout2);
        tank3->setLayout(pumpLayout3);
        this->setLayout(mainLayout);
        mainLayout->addLayout(tankLayout);
        mainLayout->addLayout(engineLayout);

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

        // Layout params spacing and alignment
        mainLayout->setAlignment(tankLayout, Qt::AlignTop | Qt::AlignHCenter);
        mainLayout->setAlignment(engineLayout, Qt::AlignBottom | Qt::AlignHCenter);
        engineLayout->setSpacing(SPACING);

        // signals
        QObject::connect(tank1, SIGNAL(tankStateChanged(tankState)), vt12, SLOT(setChangeable(tankState)));
        QObject::connect(tank2, SIGNAL(tankStateChanged(tankState)), vt12, SLOT(setChangeable(tankState)));
        QObject::connect(tank2, SIGNAL(tankStateChanged(tankState)), vt23, SLOT(setChangeable(tankState)));
        QObject::connect(tank3, SIGNAL(tankStateChanged(tankState)), vt23, SLOT(setChangeable(tankState)));

        QObject::connect(vt12, SIGNAL(valveStateChanged(valveState)), tank1, SLOT(setState(valveState)));
        QObject::connect(vt12, SIGNAL(valveStateChanged(valveState)), tank2, SLOT(setState(valveState)));
        QObject::connect(vt23, SIGNAL(valveStateChanged(valveState)), tank2, SLOT(setState(valveState)));
        QObject::connect(vt23, SIGNAL(valveStateChanged(valveState)), tank3, SLOT(setState(valveState)));
    }

// PAINT EVENT WINDOW
    void SystemeCarburantWindow::paintEvent(QPaintEvent *) {
        QPainter p(this);

        // Lines
        int xleft, xcenter, xright;
        xcenter = width()/2;
        xleft = xcenter - TANK_WIDTH - 2*VALVE_RAY;
        xright = xcenter + TANK_WIDTH + 2*VALVE_RAY;

        // Tanks and engines
        p.drawLine(xleft, TANK_HEIGHT/2 + 10, xright, TANK_HEIGHT/2 + 10);  // between tanks
        p.drawLine(xleft, 3*TANK_HEIGHT, xleft - 20, 3*TANK_HEIGHT); // t1 e1 horizontal
        p.drawLine(xleft - 20, 3*TANK_HEIGHT, xleft - 20, height() - TANK_HEIGHT/2);   // t1 e1 vertical
        p.drawLine(xcenter, TANK_HEIGHT/2 + 10, xcenter, height() - TANK_HEIGHT/2);     // t2 e2

        // Valve lines
        v12->setGeometry(width()/2 - TANK_WIDTH, 3.5*TANK_HEIGHT, VALVE_RAY*2, VALVE_RAY*2);
        v13->setGeometry(width()/2 + TANK_WIDTH/2, 3*TANK_HEIGHT/2, VALVE_RAY*2, VALVE_RAY*2);
        v23->setGeometry(width()/2 + TANK_WIDTH/2, 4*TANK_HEIGHT, VALVE_RAY*2, VALVE_RAY*2);

        p.drawLine(xleft, TANK_HEIGHT/2 + 10, xleft, 4*TANK_HEIGHT);    // v12 vertical
        p.drawLine(xleft, 4*TANK_HEIGHT, xcenter, 4*TANK_HEIGHT);   // v12 horizontal
        p.drawLine(xright, 4.5*TANK_HEIGHT, xcenter, 4.5*TANK_HEIGHT);  // v23 horizontal
        p.drawLine(xright, TANK_HEIGHT/2 + 10, xright, 4.5*TANK_HEIGHT);   // v23 vertical
        p.drawLine(xleft, 2*TANK_HEIGHT, xright + 20, 2*TANK_HEIGHT);    // v13 horizontal
        p.drawLine(xright + 20, 2*TANK_HEIGHT, xright + 20, height() - TANK_HEIGHT/2);   // v13 vertical
    }
