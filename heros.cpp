#include "heros.h"
#include "creature.h"
#include "iostream"
#include <random>
using namespace std;
//fichier csv qui crée des créatures (pourcentage de chance d'apparition etc..)
//differents menu attaque, heal, fuite
//classe jeu
//classe interface

Heros::Heros(string nom,float pvmax, float pa, int maxmana, int energie){
    this-> nom = nom;
    this-> pvmax = pvmax;
    this-> pv = pvmax;
    this-> pa = pa;
    this-> degat = degat;
    this-> max = max;
    this-> min = min;
    this-> nbheal =5;
    this-> pourcentheal = 25.0/100.0;
    this-> nbboostpa =2;
    this-> nbhfuite =0;
    this-> mana = maxmana;
    this-> energie = energie;
    this-> maxenergie = 100;
    this-> minenergie = 0;
    this-> maxmana = maxmana;
    this-> nbgivemana = 6;
    this-> nbpotionheal = 2;
    this-> nbpotionmana = 2;
    this -> nomattaque = "coup d'epee";
    this -> nomvoldevie = "drainage";
    this -> nomboostpa = "surcharge";
    this -> nompotionheal = "potion de heal";
    this -> nompotionmana = "potion de mana";
    this -> nomultime = "attaque ultime";
    this -> nomhealpourcent = "retablissement";
    this -> nbtour = 0;
}

int Heros::getnbtour(){
    return this->nbtour;
}

void Heros::demandepseudo(){
    cout << "Quel est votre nom ?" << endl;
    getline(cin, this->nom);
}

string Heros::getnomattaque(){
    return this->nomattaque;
}

string Heros::getnomvoldevie(){
    return this->nomvoldevie;
}

string Heros::getnomboostpa(){
    return this->nomboostpa;
}

string Heros::getnompotionheal(){
    return this->nompotionheal;
}

string Heros::getnompotionmana(){
    return this->nompotionmana;
}

string Heros::getnomultime(){
    return this->nomultime;
}

string Heros::getnomhealpourcent(){
    return this->nomhealpourcent;
}

int Heros::getnbhfuite(){
    return this->nbhfuite;
}

float Heros::getpv(){
    return this->pv;
}
void Heros::setpv(float pv){
    this->pv = pv;
}

int Heros::getmana(){
    return this->mana;
}

void Heros::setmana(int mana){
    this->mana = mana;
}

int Heros::getmaxmana(){
    return this->maxmana;
}

float Heros::getpa(){
    return this->pa;
}

void Heros::setpa(float pa){
    this->pa = pa;
}

void Heros::setpvmax(float pvmax){
    this->pvmax = pvmax;
}

float Heros::getpvmax(){
    return this->pvmax;
}

int Heros::getenergie(){
    return this->energie;
}

void Heros::setenergie(int energie){
    this->energie = energie;
}
int Heros::getmaxenergie(){
    return this->maxenergie;
}

int Heros::getnbpotionmana(){
    return this->nbpotionmana;
}

int Heros::getnbpotionheal(){
    return this->nbpotionheal;
}

string Heros::affiche(){
    return "Nom du heros : " + nom + "; PV : "+ to_string(getpv()) + "/" + to_string(getpvmax()) +"; PA : " + to_string(getpa())+"; MANA : " +to_string(getmana())+"/"+to_string(getmaxmana()) +"; ENERGIE : " + to_string(getenergie())+"/" +to_string(getmaxenergie())+".";
}

string Heros::affichechoix(){
    return "Attaque de base : 1 | Sort de vol de vie : 2 | Potion de soin ("+to_string(getnbpotionheal())+") : 3 \nSort de soin : 4 | Se boost PA : 5 | Ultime : 6 \nPotion de mana ("+
                   to_string(getnbpotionmana()) +") : 7 "+" | Fuir : 8\n";
}

string Heros::tour(){
    nbtour +=1;
    return  "Tour " + to_string(getnbtour());
}

void Heros::fight(Creature &c){
    int validechoix = 0;
    while (validechoix != 1) {
        cout << affichechoix();
        scanf("%d", &enteruser);
        fseek(stdin, 0, SEEK_END);
        switch (enteruser) {
            case 1:
                attaque(c);
                validechoix = 1;
                break;
            case 2:
                voldevie(c);
                validechoix = 1;
                break;
            case 3:
                potionheal();
                validechoix = 1;
                break;
            case 4:
                healpourcentmanquant();
                validechoix = 1;
                break;
            case 5:
                boostpa();
                validechoix = 1;
                break;
            case 6:
                atkultime(c, getenergie());
                validechoix = 1;
                break;
            case 7:
                potionmana();
                validechoix = 1;
                break;
            case 8:
                hfuite();
                validechoix = 1;
                break;
            default :
                cout << "Mauvais choix !" << endl;
                validechoix = 0;
                break;
        }

    }
}

void Heros::subitDegat(float degat) {
    pv-= degat;
}

int Heros::getrandomcritique(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int Heros::getrandomesquive(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void Heros::atkultime(Creature &c, int energie) {
    if (energie >= maxenergie) {
        setenergie(minenergie);
        degat = pa * 3;
        c.subitDegat(degat);
        cout << getnom() << " utilise " << getnomultime() << " sur " << c.getnom() << " et lui inflige " << degat << " degats." << endl;
    }
    else {
        cout << (char) toupper(getnomultime()[0]) << getnomultime().erase(0,1) <<" echoue. Vous n'avez pas assez d'energie !" << endl;
    }
}

void Heros::attaque(Creature &c){
    float degat = pa;
    if (11 <= getrandomesquive(0,100) && getrandomesquive(0,100)<= 100) {
        if (0 <= getrandomcritique(0, 100) && getrandomcritique(0, 100)<= 10) {
            cout << "Coup critique !"<< endl;
            degat *= 2;
        }
        if (getenergie()+20 <= maxenergie) {
            energie = energie +20;
        }
        else {
            energie = maxenergie;
        }
        c.subitDegat(degat);
        cout << getnom() << " utilise " << getnomattaque() << " sur " << c.getnom() << " et lui inflige " << degat << " degats." << endl;
    }
    else {
        cout << c.getnom()<<" esquive l'attaque de "<<getnom()<<" et ne subit pas de degats !" << endl;
    }
}

void Heros::voldevie(Creature &c){
    if (getmana() >= 4) {
        degat = pa * (80.0 / 100.0);
        if (11 <= getrandomesquive(0, 100) && getrandomesquive(0, 100) <= 100) {
            energie = energie + 20;
            pv = pv + degat * (85.0 / 100.0);
            c.subitDegat(degat);
            cout << getnom() << " utilise " << getnomvoldevie() << " sur " << c.getnom() << " et lui inflige " << degat << " degats." << endl;
            cout << getnom()<<" se heal " + to_string(degat * (80.0 / 100.0)) + " PV." << endl;
        } else {
            cout << c.getnom()<<" esquive l'attaque de "<<getnom()<<"et ne subit pas de degats !" << endl;
        }
        setmana(getmana() - 4);
    }
    else {
        cout << (char) toupper(getnomvoldevie()[0]) << getnomvoldevie().erase(0,1) <<" echoue. Vous n'avez pas assez de mana !" << endl;
    }
}

string Heros::getnom(){
    return this->nom;
}

void Heros::potionmana(){
    if (getnbpotionmana() > 0) {
        if (this->mana + nbgivemana < this->maxmana) {
            this->mana = this->mana + nbgivemana;
            cout << getnom()<<" utilise "<<getnompotionmana()<<" et gagne " + to_string(nbgivemana) + " MANA." << endl;
        } else if (this->mana + nbgivemana > this->maxmana) {
            cout << getnom()<<" utilise " <<getnompotionmana()<< " et gagne " << maxmana - mana << " MANA." << endl;
            this->mana = this->maxmana;
        }
        nbpotionmana-=1;
    }
    else {
        cout << "Vous n'avez plus de "<<getnompotionmana()<<" !" << endl;
    }
}

void Heros::potionheal(){
    if (getnbpotionheal() > 0) {
        if (this->pv + nbheal < this->pvmax) {
            this->pv = this->pv + nbheal;
            cout << getnom()<<" utilise " + getnompotionheal() << " et se heal " + to_string(nbheal) + " PV." << endl;
        } else if (this->pv + nbheal > this->pvmax) {
            cout << getnom()<<" utilise " + getnompotionheal() << " et se heal " << pvmax - pv << " PV." << endl;
            this->pv = this->pvmax;
        }
        nbpotionheal-=1;
    }
    else {
        cout << "Vous n'avez plus de "<<getnompotionheal()<<" !" << endl;
    }
}

void Heros::healpourcentmanquant(){
    if (getmana() >= 4) {
        int nbpourcenthealed = (getpvmax() - getpv()) * (pourcentheal);
        pv += ((getpvmax() - getpv()) * (pourcentheal));
        cout << getnom()<<"utilise" << getnomhealpourcent() << " et heal 25% de ses PV manquants et regagne " << nbpourcenthealed << " PV." << endl;
        setmana(getmana() - 4);
    }
    else {
        cout << "Echec de "<<getnomhealpourcent()<<". Vous n'avez pas assez de mana !" << endl;
    }
}

void Heros::boostpa(){
    if (getmana() >= 2) {
        pa += nbboostpa;
        cout << getnom()<<" utilise " << getnomboostpa() << " et gagne " << nbboostpa << " PA." << endl;
        setmana(getmana() - 2);
    }
    else {
        cout << "Echec de " << getnomboostpa() << ". Vous n'avez pas assez de mana !" << endl;
    }
}

int Heros::getrandomfuite(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int Heros::hfuite(){
    if (getpv() >= getpvmax()/2){
        if (getrandomfuite(0,100) <= 85){
            nbhfuite = 1;
            cout << getnom()<<" prend la fuite !" << endl;
        }
        else {
            cout << getnom()<<" n'arrive pas a fuir !" << endl;
        }
    }
    else {
        if (getrandomfuite(0,100) <= 50){
            nbhfuite =1;
            cout << getnom()<<" prend la fuite !" << endl;
        }
        else {
            cout << getnom()<<" n'arrive pas a fuir !" << endl;
        }
    }
    return nbhfuite;
}