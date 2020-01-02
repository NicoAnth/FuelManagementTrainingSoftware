#include "affichage.h"
#include<QDebug>
#include <QTimer>

class Evaluation: QTimer {
    Q_OBJECT

    private:
        int mark;
        int mistake_nb;
        SystemeCarburant* sc;
        QMap<QString, GenericTpev*>& scMap;
        QTimer *time;
    public:
        Evaluation(SystemeCarburant *systemeC);
        ~Evaluation(){};
        int getMark();
        int getMistakeNumber();
 
    public slots:
        bool vt12();
        bool vt23();
        bool v13();
        bool v12();
        bool v23();
        bool p12();
        bool p22();
        bool p32();
        bool resolved();
    
    public signals:
        bool resolved();

};
