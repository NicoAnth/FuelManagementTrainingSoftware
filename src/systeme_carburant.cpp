//
// Created by user on 26/10/2019.
//

#include "systeme_carburant.h"

// RESERVOIR
    Reservoir::Reservoir(){
        etat = PLEIN;
    }

    etatReservoir Reservoir::getEtat() {
        return etat;
    }

    void Reservoir::vider(){
        etat = VIDE;
    }

    void Reservoir::remplir(){
        etat = PLEIN;
    }

// POMPE
    Pompe::Pompe(){
        etat = ETEINT;
        moteur_alimente = AUCUN;
    }

    etatPompe Pompe::getEtat() {
        return etat;
    }

    Moteur Pompe::getMoteur() {
        return moteur_alimente;
    }

    void Pompe::allumer(){
        etat = ALLUME;
    }

    void Pompe::eteindre(){
        etat = ETEINT;
    }

    void Pompe::panne(){
        etat = PANNE;
    }

// VANNE
    Vanne::Vanne(){
        etat = OUVERT;
    }

    etatVanne Vanne::getEtat() {
        return etat;
    }

    void Vanne::ouvrir(){
        etat = OUVERT;
    }

    void Vanne::fermer(){
        etat = FERME;
    }