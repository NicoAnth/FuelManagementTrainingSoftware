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
        OFF = 0,
        ON,
        BROKEN
    } pumpState;

// CLASSES WIDGET

    class Valve;

    class SystemeCarburantWindow : public QWidget{
        private:
            Valve* v12;
            Valve* v13;
            Valve* v23;

        public:
            SystemeCarburantWindow(int width, int height);
            ~SystemeCarburantWindow(){}

            void paintEvent(QPaintEvent*);
    };

    class Tank : public QWidget{
        Q_OBJECT

        private:
            QString name;
            bool state;
            void paintEvent(QPaintEvent*);
            void mousePressEvent(QMouseEvent*);

        public:
            Tank(QString name);
            ~Tank(){}

        public slots:
            void setState(bool state);

        signals:
            void tankStateChanged(bool state);
    };

    class Pump : public QWidget{
        Q_OBJECT

        private:
            QString name;
            pumpState state;
            bool engine;
            bool stateChangeable;

        public:
            Pump(QString name);
            ~Pump(){}
            pumpState getState();
            bool getEngine();
            void setEngine(bool engine);
            void paintEvent(QPaintEvent*);
            void mousePressEvent(QMouseEvent*);
        public slots:
            void stateChangedSlot(); 
        signals:
            void stateChanged(short state);
        
    };

    class Engine : public QWidget{
        private:
            QString name;

        public:
            Engine(QString name);
            ~Engine(){}
            void paintEvent(QPaintEvent*);
    };

    class Valve : public QWidget{
        Q_OBJECT

        private:
            QString name;
            bool state;
            bool stateChangeable;
            unsigned short tankStateCount;

        public:
            Valve(const QString name);
            ~Valve(){}
            void paintEvent(QPaintEvent*);
            void mousePressEvent(QMouseEvent*);
        public slots:
            void stateChanged();
        signals:
            void valveStateChanged(bool state);
        
        
    };



#endif //PROJET_CARBURANT_AVION_AFFICHAGE_H
