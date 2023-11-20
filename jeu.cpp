#include "jeu.h"
#include <iostream>

//Heros Jeu::getHeros(Heros h) {
//    return h;
//}
//
//Creature Jeu::getCreature(Creature c) {
//    return c;
//}
Jeu::Jeu(Heros &h, Creature &c) {
    this->heros = h;
    this->creature = c;

};

void Jeu::demarre() {
    this->heros.demandepseudo();
    while (this->heros.getpv() > 0 && this->creature.getpv() > 0 && this->heros.getnbhfuite() == 0)
    {
        cout << this->heros.tour() << endl;
        cout << this->heros.affiche() << endl;
        cout << this->creature.affiche() << endl;
        cout << "" << endl;
        this->heros.fight(this->creature);
        cout << "" << endl;
        this->creature.fight(this->heros);
        cout << "" << endl;
    }
    if (this->heros.getnbhfuite() == 1) {
        cout << this->heros.getnom() + " s'enfuit !" << endl;
        cout << this->creature.getnom() +" a gagne !" << endl;
    }
    else if (this->heros.getpv() <= 0) {
        cout << this->heros.getnom() + " est mort !" << endl;
        cout << this->creature.getnom() +" a gagne !" << endl;
    }
    else if (this->creature.getpv() <= 0) {
        cout << this->creature.getnom() + " est mort !" << endl;
        cout << this->heros.getnom()+" a gagne !" << endl;
    }
};