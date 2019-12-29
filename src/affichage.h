//
// Created by user on 27/10/2019.
//

#ifndef PROJET_CARBURANT_AVION_AFFICHAGE_H
#define PROJET_CARBURANT_AVION_AFFICHAGE_H

#include <QWidget>
#include <QPainter>
#include <QMainWindow>
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

// MAIN WINDOW
    class MainWindow : public QMainWindow{
        Q_OBJECT

        public:
            MainWindow();
            ~MainWindow(){}

           void createDockWindow();

//        public slots:
//            void test();
    };

// TANK PUMP VALVE ENGINE
    // TANK
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
            bool getState();

        public slots:
            void setState(bool state);

        signals:
            void tankStateChanged(bool state);
    };

    // PUMP
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

    // ENGINE
    class Engine : public QWidget{
        private:
            QString name;
            bool state;

        public:
            Engine(QString name);
            ~Engine(){}
            void getState();
            void paintEvent(QPaintEvent*);
        };

    // VALVE
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
            void getState();
            void paintEvent(QPaintEvent*);
            void mousePressEvent(QMouseEvent*);

        public slots:
            void stateChanged();

        signals:
            void valveStateChanged(bool state);
    };

// SYSTEME CARBURANT
    class SystemeCarburant: public QWidget{
        private:
            Tank* tank1;
            Tank* tank2;
            Tank* tank3;
            Pump* pump11;
            Pump* pump12;
            Pump* pump21;
            Pump* pump22;
            Pump* pump31;
            Pump* pump32;
            Engine* engine1;
            Engine* engine2;
            Engine* engine3;
            Valve* vt12;
            Valve* vt23;
            Valve* v12;
            Valve* v13;
            Valve* v23;

        public:
            SystemeCarburant(int width, int height);
            ~SystemeCarburant(){}

            void paintEvent(QPaintEvent*);
    };


#endif //PROJET_CARBURANT_AVION_AFFICHAGE_H
