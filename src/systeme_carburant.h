//
// Created by user on 26/10/2019.
//

#ifndef PROJET_CARBURANT_AVION_SYSTEME_CARBURANT_H
#define PROJET_CARBURANT_AVION_SYSTEME_CARBURANT_H

// TYPES


// CLASSES

class Reservoir{
    private:
        etatReservoir etat;
    public:
        Reservoir();
        ~Reservoir(){}
        etatReservoir getEtat();
        void vider();
        void remplir();
};

class Pompe{
    private:
        etatPompe etat;
        Moteur moteur_alimente;
    public:
        Pompe();
        ~Pompe(){}
        etatPompe getEtat();
        Moteur getMoteur();
        void allumer();
        void eteindre();
        void panne();
};

class Vanne{
    private:
        etatVanne etat;
    public:
        Vanne();
        ~Vanne(){}
        etatVanne getEtat();
        void ouvrir();
        void fermer();
};

#endif //PROJET_CARBURANT_AVION_SYSTEME_CARBURANT_H
