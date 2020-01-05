//
// Created by user on 04/01/2020.
//

#include "MainWindow.h"

bool MainWindow::mode = SIMULATION;

// MAIN WINDOW
MainWindow::MainWindow() {
    systemeC = new SystemeCarburant(700,700);
    connection = new Connection();
    log = new Log(this, systemeC);
    Evaluation* eval = new Evaluation(systemeC, log);

    systemeC->setParent(this);
    this->setCentralWidget(systemeC);

    createActions();
    createMenus();
}

void MainWindow::createActions() {
    // acc
    newAccountAct = new QAction(tr("&Register"), this);
    newAccountAct->setStatusTip(tr("Create a new account"));
    QObject::connect(newAccountAct, SIGNAL(triggered()), this, SLOT(accountCreation()));

    connexionAct = new QAction(tr("&Log in"), this);
    connexionAct->setStatusTip(tr("Connection to an account"));
    QObject::connect(connexionAct, SIGNAL(triggered()), this, SLOT(accountConnection()));

    disconnectionAct = new QAction(tr("&Disconnect"), this);
    connexionAct->setStatusTip(tr("Disconnection to an account"));
    QObject::connect(disconnectionAct,SIGNAL(triggered()),connection,SLOT(isDisconnectedSlot()));

    // save/load
    saveAct = new QAction(tr("&Save"), this);
    saveAct->setStatusTip(tr("Save action log into a file"));
    QObject::connect(saveAct, SIGNAL(triggered()), this, SLOT(saveLog()));
    loadAct = new QAction(tr("&Load"), this);
    loadAct->setStatusTip(tr("Load an existing action log"));
    QObject::connect(loadAct, SIGNAL(triggered()), this, SLOT(loadLog()));

    // sim/exercice
    simulAct = new QAction(tr("&Simulation"), this);
    simulAct->setStatusTip(tr("Switch to simulation mode"));
    QObject::connect(simulAct, SIGNAL(triggered()), this, SLOT(setModeSimulation()));
    QObject::connect(simulAct, SIGNAL(triggered()), log, SLOT(clear()));

    exerciceAct = new QAction(tr("&Exercice"), this);
    exerciceAct->setStatusTip(tr("Switch to exercice mode"));
    QObject::connect(exerciceAct, SIGNAL(triggered()), this, SLOT(setModeEvaluation()));
    QObject::connect(exerciceAct, SIGNAL(triggered()), log, SLOT(clear()));

    // systemFailures
    tank1Act = new QAction(tr("&Tank1"), this);
    tank2Act = new QAction(tr("&Tank2"), this);
    tank3Act = new QAction(tr("&Tank3"), this);
    p11Act = new QAction(tr("&Pump11"), this);
    p12Act = new QAction(tr("&Pump12"), this);
    p21Act = new QAction(tr("&Pump21"), this);
    p22Act = new QAction(tr("&Pump22"), this);
    p31Act = new QAction(tr("&Pump31"), this);
    p32Act = new QAction(tr("&Pump32"), this);

    const QMap<QString, GenericTpev*>& map = systemeC->getMap();
    QObject::connect(tank1Act, SIGNAL(triggered()), map["Tank 1"], SLOT(empty()));
    QObject::connect(tank2Act, SIGNAL(triggered()), map["Tank 2"], SLOT(empty()));
    QObject::connect(tank3Act, SIGNAL(triggered()), map["Tank 3"], SLOT(empty()));
    QObject::connect(p11Act, SIGNAL(triggered()), map["P11"], SLOT(setBroken()));
    QObject::connect(p12Act, SIGNAL(triggered()), map["P12"], SLOT(setBroken()));
    QObject::connect(p21Act, SIGNAL(triggered()), map["P21"], SLOT(setBroken()));
    QObject::connect(p22Act, SIGNAL(triggered()), map["P22"], SLOT(setBroken()));
    QObject::connect(p31Act, SIGNAL(triggered()), map["P31"], SLOT(setBroken()));
    QObject::connect(p32Act, SIGNAL(triggered()), map["P32"], SLOT(setBroken()));
}

void MainWindow::createMenus() {
    fileMenu = menuBar()->addMenu(tr("&Connexion"));
    fileMenu->addAction(newAccountAct);
    fileMenu->addAction(connexionAct);
    fileMenu->addAction(disconnectionAct);
    
    QMenu *file = new QMenu("&File");
    QAction *test = new QAction();
    test = menuBar()->addMenu(file);
    file->addAction(saveAct);
    file->addAction(loadAct);
    test->setVisible(false);

    //fileMenu = menuBar()->addMenu(tr("&File"));

    fileMenu = menuBar()->addMenu(tr("&Mode"));
    fileMenu->addAction(exerciceAct);
    fileMenu->addAction(simulAct);

    fileMenu = menuBar()->addMenu(tr("&Manage System Failure"));
    subMenu = fileMenu->addMenu("Empty/Refill Tank");
    subMenu->addAction(tank1Act);
    subMenu->addAction(tank2Act);
    subMenu->addAction(tank3Act);
    subMenu = fileMenu->addMenu("Break/Repair Pump");
    subMenu->addAction(p11Act);
    subMenu->addAction(p12Act);
    subMenu->addAction(p21Act);
    subMenu->addAction(p22Act);
    subMenu->addAction(p31Act);
    subMenu->addAction(p32Act);

    connect(connection,&Connection::isConnected,[=](){test->setVisible(true);});
    connect(connection,&Connection::isDisconnectedSignal,[=](){test->setVisible(false); update();});
}

void MainWindow::saveLog() {
    QString fileName = QFileDialog::getSaveFileName
            (this, tr("Choose File"), "home/user/projetCarburantAvion/Data/Log");

    log->save(fileName);
}

void MainWindow::loadLog(){
    QString fileName = QFileDialog::getOpenFileName
            (this, tr("Choose File"), "home/user/projetCarburantAvion/Data/Log");

    log->load(fileName);
}

void MainWindow::accountConnection(){
        connection->ConnectionInterface();
    }

void MainWindow::accountCreation(){
    connection->newAccountInterface();
}

void MainWindow::setModeEvaluation() {
    mode = EVALUATION;
}

void MainWindow::setModeSimulation() {
    mode = SIMULATION;
}
