#include <iostream>
#include "heros.h"
#include "creature.h"
#include "jeu.h"

int main() {
    Heros h("Mathice", 100, 10, 10, 0);
    Creature c("Gorille", 150, 10);
    Jeu monjeu(h,c);
    monjeu.demarre();
}