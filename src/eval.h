#include "affichage.h"
#include <QTimer>

class Evaluation: QTimer {
    Q_OBJECT

    private:
        int mark;
        int mistake_nb;
        SystemeCarburant *sc;
        QTimer *time;
    public:
        Evaluation(SystemeCarburant *systemeC);
        ~Evaluation(){};
        void vt12();

};
