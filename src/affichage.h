//
// Created by user on 27/10/2019.
//

#ifndef PROJET_CARBURANT_AVION_AFFICHAGE_H
#define PROJET_CARBURANT_AVION_AFFICHAGE_H

#include <QWidget>
#include <QPainter>
#include <map>

// CONSTANTES
    #define TANK_WIDTH 150
    #define TANK_HEIGHT 100
    #define PUMP_RAY 25
    #define VALVE_RAY 50
    #define ENGINE_WIDTH 200
    #define ENGINE_HEIGHT 100
    #define SPACING 110

// TYPES ETATS DU SYSTEME CARBURANT
    typedef enum{
        EMPTY = 0,
        FULL
    } tankState;

    typedef enum{
        OFF = 0,
        ON,
        BROKEN
    } pumpState;

    typedef enum{
        CLOSED = 0,
        OPENED
    } valveState;

    typedef enum{
        NONE = 0,
        ENGINE1,
        ENGINE2,
        ENGINE3
    } enginePowered;

// CLASSES WIDGET
class ValveShape;

    class SystemeCarburantWindow : public QWidget{
        private:
            ValveShape* v12;
            ValveShape* v13;
            ValveShape* v23;

        public:
            SystemeCarburantWindow(int width, int height);
            ~SystemeCarburantWindow(){}

            void paintEvent(QPaintEvent*);
    };

    class TankShape : public QWidget{
        Q_OBJECT

        private:
            QString name;
            tankState state;
            void paintEvent(QPaintEvent*);
            void mousePressEvent(QMouseEvent*);

        public:
            TankShape(QString name);
            ~TankShape(){}

        public slots:
            void setState(valveState state);

        signals:
            void tankStateChanged(tankState state);
    };

    class PumpShape : public QWidget{
        Q_OBJECT

        private:
            QString name;
            pumpState state;
            enginePowered engine;
            bool stateChangeable;

        public:
            PumpShape(enginePowered engine, QString name);
            ~PumpShape(){}
            pumpState getState();
            enginePowered getEngine();
            void setEngine(enginePowered engine);
            void paintEvent(QPaintEvent*);
            void mousePressEvent(QMouseEvent*);

        signals:
            void stateChanged(short state);
    };

    class EngineShape : public QWidget{
        private:
            QString name;

        public:
            EngineShape(QString name);
            ~EngineShape(){}
            void paintEvent(QPaintEvent*);
    };

    class ValveShape : public QWidget{
        Q_OBJECT

        private:
            QString name;
            valveState state;
            bool stateChangeable;
            unsigned short tankStateCount;
//            PumpShape* p1, PumpShape* p2, PumpShape* p3, PumpShape* p4;

        public:
            ValveShape(const QString name);
            ~ValveShape(){}
            void paintEvent(QPaintEvent*);
            void mousePressEvent(QMouseEvent*);

        public slots:
            void setChangeable(tankState state);

        signals:
            void valveStateChanged(valveState state);
    };


#endif //PROJET_CARBURANT_AVION_AFFICHAGE_H
