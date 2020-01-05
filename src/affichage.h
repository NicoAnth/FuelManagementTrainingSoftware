#ifndef PROJET_CARBURANT_AVION_AFFICHAGE_H
#define PROJET_CARBURANT_AVION_AFFICHAGE_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>


// CONSTANTES
    #define TANK_WIDTH 150
    #define TANK_HEIGHT 100
    #define PUMP_RAY 25
    #define VALVE_RAY 50
    #define ENGINE_WIDTH 200
    #define ENGINE_HEIGHT 100
    #define SPACING 110

    #define LOG_DIR "../Data/Log/"

// TYPES ETATS DU SYSTEME CARBURANT

    typedef enum{
        OFF = 0,
        ON,
        BROKEN
    } pumpState;

    class GenericTpev : public QAbstractButton{
        Q_OBJECT

        protected:
            QString name;

        public:
            GenericTpev(){}
            ~GenericTpev(){}

            virtual short getState()=0;
            virtual void setState(short state)=0;
            QString getName(){ return name; }

        public slots:
            virtual void clickedSlot()=0;

        signals:
            void updateLastEntry();
            void clickedEval();
            void clickedLog(QString name);
    };

// TANK PUMP VALVE ENGINE
    class Pump;
    class Engine;
    class ValveEngine;
    // TANK
    class Tank : public GenericTpev{
        Q_OBJECT

        private:
            bool state;
            Pump* const primaryPump;
            Pump* const secondaryPump;
            ValveEngine* ve1;
            ValveEngine* ve2;
            void paintEvent(QPaintEvent*);

        public:
            Tank(QString name,Pump* primaryP,Pump* secondaryP);
            ~Tank(){}
            virtual short getState();
            Pump* getPrimaryPump();
            Pump* getSecondaryPump();
            ValveEngine* getVe1();
            ValveEngine* getVe2();
            void setVe1(ValveEngine* ve1);
            void setVe2(ValveEngine* ve2);
            void switchState(bool state);

        public slots:
            virtual void clickedSlot();
            virtual void setState(short state);
            void empty();
    };

    // PUMP
    class Pump : public GenericTpev{
        Q_OBJECT

        private:
            pumpState state;
            bool primary;
            Engine* supplyingEngine;
            Tank* tank;

        public:
            Pump(QString name,Tank* tank, Engine* supplyingE, bool primary);
            ~Pump(){}
            virtual short getState();
            Engine* getEngine();
            void setEngine(Engine*);
            void setTank(Tank*);
            const Tank& getTank();
            void paintEvent(QPaintEvent*);
            void switchState(pumpState state);

        public slots:
            virtual void clickedSlot();
            virtual void setState(short state);
            void setBroken();
    };

    // ENGINE
    class Engine : public GenericTpev{
        Q_OBJECT

        private:
            bool state;
            Pump* supplyingPump;
        public:
            Engine(QString name,Pump* supplyingP);
            ~Engine(){}
            virtual short getState();
            virtual void setState(short state);
            Pump* getPump();
            void setPump(Pump* supplyingP);
            virtual void clickedSlot(){}
            void paintEvent(QPaintEvent*);
        signals:
            void engineSupplied();

    };

    // VALVE
    class Valve : public GenericTpev{
        Q_OBJECT

        protected:
            bool state;

        public:
            Valve(const QString name);
            ~Valve(){}

            virtual short getState();
            virtual void setState(short state);
            void paintEvent(QPaintEvent*);

        public slots:
            virtual void clickedSlot()=0;
    };

    class ValveTank : public Valve{
        Q_OBJECT

        private:
            Tank* const t1;
            Tank* const t2;
            Tank* const t3;
            ValveTank* vt2;

        public:
            ValveTank(QString name, Tank* t1, Tank* t2, Tank* t3, ValveTank* vt2);
            ~ValveTank(){}
            void setVt2(ValveTank* vt2);

        public slots:
            virtual void clickedSlot();
    };

    class ValveEngine : public Valve{
        Q_OBJECT

        private:
            QPair<Tank*, Engine*> pair1;
            QPair<Tank*, Engine*> pair2;

        public:
            ValveEngine(QString name, Tank* t1, Engine* e1, Tank* t2, Engine* e2);
            ~ValveEngine(){}

            void switchEngineState(QPair<Tank*, Engine*>& pair, bool state);
            Engine* findAssociatedEngine(Tank* tank);
            Tank* findAssociatedTank(Engine* engine);

        public slots:
            virtual void clickedSlot();
    };


#endif //PROJET_CARBURANT_AVION_AFFICHAGE_H
