#include "heros.h"
#include "creature.h"

class Jeu {
public :
//    Heros getHeros();
//    Creature getCreature();
    void demarre();
    Jeu(Heros &h, Creature &c);
private :
    Heros heros;
    Creature creature;

};