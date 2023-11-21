#include <iostream>
#include "heros.h"
#include "creature.h"
#include "jeu.h"

int main() {
    Heros h("nom", 500, 50, 10, 0);
    Creature c("Gorille",c.getrandomplage(120,150),c.getrandomplage(8,12));
    Jeu monjeu(h,c);
    monjeu.demarre();
}