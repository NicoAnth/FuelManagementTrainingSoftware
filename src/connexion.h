#include "affichage.h"
#include <QLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QFile>

class Connection: public QWidget{
    
    Q_OBJECT

    private:
        QFile *usersFile;
        bool isconnected;
        QString userName;

    public: 
        Connection();
        ~Connection(){};
        void ConnectionInterface();
        void newAccountInterface();
        bool alreadyExists(QString name, QString password);
        bool getConnected();
    
    public slots:
        void createUser(QString name, QString password);
        bool connectUser(QString name, QString password);
        void isDisconnectedSlot();
    signals:
        void isConnected();
        void isDisconnectedSignal();
    
};
