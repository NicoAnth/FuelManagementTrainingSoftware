//
// Created by user on 04/01/2020.
//

#ifndef PROJETCARBURANTAVION_MAINWINDOW_H
#define PROJETCARBURANTAVION_MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include "connexion.h"
#include "Log.h"
#include "eval.h"

#define SIMULATION 0
#define EVALUATION 1

class Evaluation;

class MainWindow : public QMainWindow{
    Q_OBJECT

    private:
        SystemeCarburant* systemeC;
        Evaluation * eval;
        Log* log;
        Connection * connection;
        QMenu* fileMenu;
        QMenu* subMenu;
        QAction *newAccountAct;
        QAction *connexionAct;
        QAction* disconnectionAct;
        QAction *saveAct;
        QAction *loadAct;
        QAction *simulAct;
        QAction *exerciceAct;
        QAction* tank1Act;
        QAction* tank2Act;
        QAction* tank3Act;
        QAction* p11Act;
        QAction* p12Act;
        QAction* p21Act;
        QAction* p22Act;
        QAction* p31Act;
        QAction* p32Act;

    public:
        static bool mode;
        MainWindow();
        ~MainWindow(){}

        void createDockWindow(Log* log);
        void createMenus();
        void createActions();

    public slots:
        void saveLog();
        void loadLog();
        void accountConnection();
        void accountCreation();
        void setModeSimulation();
        void setModeEvaluation();

    signals:
        void saveSignal(QString);
        void loadSignal(QString);
};


#endif //PROJETCARBURANTAVION_MAINWINDOW_H
