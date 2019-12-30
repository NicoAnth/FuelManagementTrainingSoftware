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
 
    public slots:
        bool vt12(QString a);

};
