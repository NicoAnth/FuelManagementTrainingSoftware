#include "affichage.h"
#include <QTimer>

class Evaluation: QTimer {
    Q_OBJECT

    private:
        int mark;
        int mistake_nb;
        QTimer *time;
    public:
        Evaluation();
        ~Evaluation(){};
        void vt12();

};
