#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Film.h"
#include "FilmTar.h"


Filmtar::~Filmtar() {               //destruktor
    for (int i = 0; i < aktualisMeret; i++) {
        delete filmek[i];
    }
    delete[] filmek;
}

void Filmtar::addFilm(Film* film) {             //kollekciohoz adas
    for (int i = 0; i < aktualisMeret; i++) {   //iteralas
        if (*film == *filmek[i]) {
                delete film;                    //ha egyezes, torli az elemet és kilep
            return;
        }
    }

    if (aktualisMeret == maxMeret) {         //ha a meretek egyeznek baj van
        int ujMeret = maxMeret + 10;            // Új méret növelése 10-el
        Film** ujFilmek = new Film*[ujMeret];   //uj tomb
        for (int i = 0; i < aktualisMeret; i++) {
            ujFilmek[i] = filmek[i];                //masolas
        }
        delete[] filmek;                            //regi torles
        filmek = ujFilmek;                          //pointer allitas
        maxMeret = ujMeret;                         //meret allitas
    }

    filmek[aktualisMeret] = film;                   //ha nincs egyezes csak hozzaadas es noveles
    aktualisMeret++;
}

Film* Filmtar::getFilm(int index) const {  //megkeresem melyik film van a indexedik helyen
    if (index<0) index=0;                   //index allitas
    if (index>aktualisMeret){
        throw std::out_of_range("Hibas index");         //hiba dobas
        return nullptr;
    }
    if (index >= 0 && index < aktualisMeret) {          //ha jo, visszaadja az elemet
        return filmek[index];
    }
    return nullptr;
}

int Filmtar::getMeret() const { //a tarolo meretet kerdezem le
    return aktualisMeret;
}


void Filmtar::betolt(const std::string& fajlnev) {          //betoltes a fajlbol
    std::ifstream fajl(fajlnev);
    if (!fajl.is_open()){
        throw std::runtime_error("Hiba a fajl megnyitasa soran.");          //fajl nyitas, ha nem jo hiba dobas
        return;
    }

    std::string sor;
    while (getline(fajl, sor)) {           //amig tud olvasni
        std::istringstream ss(sor);
        std::string tipus;
        getline(ss, tipus, ',');                //beolvassa a tipus es aszerint dont
                                                //barmelyik tipus, letrehoz egy objektumot, ezt kiolvassa a streamrol es hozzaadja a kollekicohoz
        if (tipus == "Mese") {
            Mese* mese = new Mese();
            mese->olvasasStreamrol(ss);
            this->addFilm(mese);


        } else if (tipus == "Horror") {
            Horrorfilm* horror = new Horrorfilm();
            horror->olvasasStreamrol(ss);
            this->addFilm(horror);

        } else if (tipus == "Dokumentumfilm") {
            Dokumentumfilm* dokumentum = new Dokumentumfilm();
            dokumentum->olvasasStreamrol(ss);
            this->addFilm(dokumentum);

        } else if (tipus == "Csaladifilm") {
            CsaladiFilm* csaladi = new CsaladiFilm();
            csaladi->olvasasStreamrol(ss);
            this->addFilm(csaladi);

        } else {                                                            //ha nem ismer ilyet hiba van, de olvas tovabb, csak azt a sort nem
            std::cerr << "Ismeretlen tipus: " << tipus << std::endl;
        }
    }

    fajl.close();
}



void Filmtar::torol(Film* film) {                   //torles a kollekciobol
    for (int i = 0; i < aktualisMeret; i++) {          //iteralas
        if (filmek[i] == film) {                    //ha egyezes
            delete filmek[i];
            filmek[i] = nullptr;
            for (int j = i; j < aktualisMeret - 1; j++) { // Csúsztatom a tömb elemeit az eltávolított elem után, vissza egyel
                filmek[j] = filmek[j + 1];                  //csusztatas
            }
            filmek[aktualisMeret-1] = nullptr;
            aktualisMeret--;
            break;
        }
    }
}
Film* Filmtar::keresEv(int ev) const {      //ev kereses
    if (ev<0||ev>2023){                     //ha kisebb mint nulla vagy nagyobb mint 2023 baj van mert ilyen nincs
        std::cout<<"Hibas ev, ";            //hiba
        return nullptr;
    }
    for (int i = 0; i < aktualisMeret; i++) {           //iteralas
        if (filmek[i]->getEv() == ev) {                     //ha egyezes visszaadja az elemet
            return filmek[i];
        }
    }
    return nullptr; // Ha nem található film az adott évvel, akkor nullptr-t ad vissza
}

Film* Filmtar::keresCim(const std::string& cim) const {         //cim szerinti kereses
    for (int i = 0; i < aktualisMeret; i++) {                   //iteralas
        if (filmek[i]->getCim() == cim) {                       //ha egyezes, visszaadja
            return filmek[i];
        }
    }
    return nullptr; // Ha nem található film az adott címmel, akkor nullptr-t ad vissza
}

Film* Filmtar::keresHossz(int hossz) const {
      if (hossz<0||hossz>500){                      //ha a hossz kevesebb mint nulla vagy nagyobb mint 500, baj, mert ilyen nincs (500+ lehetne de most nem foglalkozunk vele)
        std::cout<<"Hibas hossz, ";                 //hiba akkor
        return nullptr;
    }
    for (int i = 0; i < aktualisMeret; i++) {           //iteralas
        if (filmek[i]->getHossz() == hossz) {           // ha egyezes adja vissza az adott elemet
            return filmek[i];
        }
    }
    return nullptr; // Ha nem található film az adott hosszúsággal, akkor nullptr-t ad vissza
}

void Filmtar::listaz() const {  //kilistázza az elemeket a kollekcióból
    for (int i = 0; i < aktualisMeret; i++) {           //tombon iteralas
        if(filmek[i]==nullptr) std::cout<<"Nem letezik ilyen elem"<<std::endl;      // ha nullptr baj van, nincs ilyen elem
        else filmek[i]->kiiras();
    }
}

void Filmtar::fajlbaIro()const {
    std::ofstream fajl("Filmek.txt", std::ios::out | std::ios::trunc); // megnyitja a fájlt és ki is törli a tartalmát
    if (!fajl.is_open()) { //ha nincs nyitva
        throw std::runtime_error("Hiba a fajl megnyitasa soran.");  //hiba
        return;
    }

    for (int i = 0; i < aktualisMeret; i++) {// Filmek kiírása a fájlba
        filmek[i]->fajlbaIras(fajl);
    }

    fajl.close();
    std::cout << "A filmek sikeresen ki lettek irva a Filmek.txt fajlba;"<<std::endl;  //siker
}
