#include "affichage.h"
#include <QLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QFile>

class Connection: QWidget{
    
    Q_OBJECT

    private:
        QFile *usersFile;
    public: 
        Connection();
        ~Connection(){};
        void ConnectionInterface();
        void newAccountInterface();

    public slots:
        void createUser(QString name, QString password);
};
