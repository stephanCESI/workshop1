#include <string>
#pragma once
#include "heros.h"
using namespace std;

class Creature {

public :
    string affiche();
    string getnom();
    void attaque(Heros &h);
    float getpv();
    void setpv(float pv);
    float getpa();
    void setpvmax(float pvmax);
    float getpvmax();
    void setpa(float pa);
    void subitDegat(float degat);
    int getrandomcritique(int min, int max);
    int getrandomesquive(int min, int max);
    int getrandomactioncreature(int min, int max);
    void fight(Heros &h);
    void voldevie(Heros &h);
    void boostpa();
    string getnomattaque();
    string getnomvoldevie();
    string getnomboostpa();
    Creature(string nom, float pvmax, float pa);
private :
    string nom;
    float pvmax;
    float pv;
    int pa;
    float degat;
    int max;
    int min;
    string nomattaque;
    string nomvoldevie;
    string nomboostpa;
    int nbboostpa;
};