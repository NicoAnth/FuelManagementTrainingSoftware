//
// Created by user on 04/01/2020.
//

#include "MainWindow.h"

// MAIN WINDOW
MainWindow::MainWindow() {
    SystemeCarburant* systemeC = new SystemeCarburant(700,700);
    log = new Log(this, systemeC);
    Evaluation* ev = new Evaluation(systemeC,log);

    systemeC->setParent(this);
    this->setCentralWidget(systemeC);

    createActions();
    createMenus();
}

void MainWindow::createActions() {

    newAccountAct = new QAction(tr("&New Account"), this);
    newAccountAct->setStatusTip(tr("Create a new account"));

    connexionAct = new QAction(tr("&Connexion"), this);
    connexionAct->setStatusTip(tr("Connexion to an account"));
    QObject::connect(connexionAct, SIGNAL(triggered()), this, SLOT(accountConnection()));

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setStatusTip(tr("Save action log into a file"));
    QObject::connect(saveAct, SIGNAL(triggered()), this, SLOT(saveLog()));

    loadAct = new QAction(tr("&Load"), this);
    loadAct->setStatusTip(tr("Load an existing action log"));
    QObject::connect(loadAct, SIGNAL(triggered()), this, SLOT(loadLog()));

    simulAct = new QAction(tr("&Exercise"), this);
    simulAct->setStatusTip(tr("Load an existing action log"));

    exerciceAct = new QAction(tr("&Simulation"), this);
    exerciceAct->setStatusTip(tr("Load an existing action log"));

    exMakerAct = new QAction(tr("&Exercise Maker"), this);
    exMakerAct->setStatusTip(tr("Load an existing action log"));
}

void MainWindow::createMenus() {
    fileMenu = menuBar()->addMenu(tr("&Connexion"));
    fileMenu->addAction(newAccountAct);
    fileMenu->addAction(connexionAct);
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(saveAct);
    fileMenu->addAction(loadAct);
    fileMenu = menuBar()->addMenu(tr("&Mode"));
    fileMenu->addAction(exerciceAct);
    fileMenu->addAction(simulAct);
    fileMenu->addAction(exMakerAct);
}

void MainWindow::saveLog() {
    QString fileName = QFileDialog::getOpenFileName
            (this, tr("Choose File"), "home/user/projetCarburantAvion");

    log->save(fileName);
}

void MainWindow::loadLog(){
    QString fileName = QFileDialog::getOpenFileName
            (this, tr("Choose File"), "home/user/projetCarburantAvion");

    log->load(fileName);
}

void MainWindow::accountConnection(){
    Connexion *c = new Connexion();
}