#include "creature.h"
#include "heros.h"
#include "iostream"
#include <random>
using namespace std;

Creature::Creature(string nom, float pvmax, float pa){
    this-> nom = nom;
    this-> pvmax = pvmax;
    this-> pv = pvmax;
    this-> pa = pa;
    this-> max = 100;
    this-> min = 0;
    this-> nomattaque = "fracassement";
    this-> nomvoldevie = "morsure";
    this-> nomboostpa = "rage";
    this-> nbboostpa = 2;
}

Creature::Creature(){}

string Creature::getnomattaque(){
    return this->nomattaque;
}

string Creature::getnomvoldevie(){
    return this->nomvoldevie;
}

string Creature::getnomboostpa(){
    return this->nomboostpa;
}

float Creature::getpv(){
    return this->pv;
}

float Creature::getpa(){
    return this->pa;
}

void Creature::setnom(string nom){
    this->nom = nom;
}

void Creature::setpv(float pv){
    this->pv = pv;
}

void Creature::setpa(float pa){
    this->pa = pa;
}

string Creature::affiche(){
    return "Nom de la creature : " + nom + "; PV : " + to_string(getpv()) + "/" + to_string(getpvmax()) +"; PA : " + to_string(getpa()) +".";
}

void Creature::setpvmax(float pvmax){
    this->pvmax = pvmax;
}

float Creature::getpvmax(){
    return this->pvmax;
}

string Creature::getnom(){
    return this->nom;
}

void Creature::subitDegat(float degat){
    pv-= degat;
}

int Creature::getrandomcritique(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int Creature::getrandomesquive(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int Creature::getrandomplage(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void Creature::attaque(Heros &h){
    float degat = pa;
    if (11 <= getrandomesquive(min,max) && getrandomesquive(min,max)<= 100) {
        if (0 <= getrandomcritique(min, max) && getrandomcritique(min, max)<= 10) {
            cout << "Coup critique !"<< endl;
            degat *= 2;
        }
        degat = getrandomplage(degat*0.8, degat*1.2);
        cout << getnom() << " utilise " + getnomattaque() + " sur "<<h.getnom()<<" et lui inflige " + to_string(degat) + " degats." << endl;
        h.subitDegat(degat);
    }
    else {
        cout << h.getnom()<<" esquive l'attaque de "<<getnom()<<" et ne subit pas de degats !" << endl;
    }
}

void Creature::voldevie(Heros &h){
    degat = pa * (65.0 / 100.0);
    if (11 <= getrandomesquive(0, 100) && getrandomesquive(0, 100) <= 100) {
        pv = pv + degat * (90.0 / 100.0);
        degat = getrandomplage(degat*0.8, degat*1.2);
        cout << getnom() << " utilise " + getnomvoldevie() + " sur "<<h.getnom()<<" et lui inflige " + to_string(degat) + " degats." << endl;
        cout << getnom()<<" se heal " + to_string(degat * (80.0 / 100.0)) + " PV." << endl;
        h.subitDegat(degat);
    } else {
        cout << h.getnom()<<" esquive l'attaque de "<<getnom()<<" et ne subit pas de degats !" << endl;
    }
}

void Creature::boostpa(){
    pa += nbboostpa;
    cout << getnom()<<" utilise "<< getnomboostpa() <<" et gagne " << nbboostpa << " PA." << endl;
}

int Creature::getrandomactioncreature(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void Creature::fight(Heros &h) {
    if (h.getpv() <= h.getpvmax() * 0.2) {
        switch (getrandomactioncreature(1, 2)) {
            case 1:
                attaque(h);
                break;
            case 2:
                voldevie(h);
                break;
        }
    }
    else if (getpv() > getpvmax() * 0.6) {
        switch (getrandomactioncreature(1, 2)) {
            case 1:
                attaque(h);
                break;
            case 2:
                boostpa();
                break;
        }

    } else {
        switch (getrandomactioncreature(1, 3)) {
            case 1:
                attaque(h);
                break;
            case 2:
                voldevie(h);
                break;
            case 3:
                boostpa();
                break;
        }
    }
}

