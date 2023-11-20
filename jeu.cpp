#include "jeu.h"
#include <iostream>

//Heros Jeu::getHeros(Heros h) {
//    return h;
//}
//
//Creature Jeu::getCreature(Creature c) {
//    return c;
//}
Jeu::Jeu(Heros h, Creature c) {

}

void Jeu::demarre(Heros h, Creature c) {
    h.demandepseudo();
    while (h.getpv() > 0 && c.getpv() > 0 && h.getnbhfuite() == 0)
    {
        cout << h.tour() << endl;
        cout << h.affiche() << endl;
        cout << c.affiche() << endl;
        cout << "" << endl;
        h.fight(c);
        cout << "" << endl;
        c.fight(h);
        cout << "" << endl;
    }
    if (h.getnbhfuite() == 1) {
        cout << h.getnom() + " s'enfuit !" << endl;
        cout << c.getnom() +" a gagne !" << endl;
    }
    else if (h.getpv() <= 0) {
        cout << h.getnom() + " est mort !" << endl;
        cout << c.getnom() +" a gagne !" << endl;
    }
    else if (c.getpv() <= 0) {
        cout << c.getnom() + " est mort !" << endl;
        cout << h.getnom()+" a gagne !" << endl;
    }
};