#ifndef FILMTAR_H_INCLUDED
#define FILMTAR_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>


#include "Csaladi.h"
#include "Dokumentumfilm.h"
#include "Film.h"
#include "Horror.h"
#include "Mese.h"
#include "memtrace.h"


class Filmtar {//kollekcio ami film pointereket tarol egy tombben
private:

    int aktualisMeret;
    int maxMeret;
    Film** filmek;

public:
    Filmtar():aktualisMeret(0), maxMeret(10),filmek(new Film*[10]){}
    ~Filmtar();

    void addFilm(Film* film);
    Film* getFilm(int index) const;
    int getMeret() const;

    void betolt(const std::string& fajlnev);

    void torol(Film* film);

    Film* keresEv(int ev) const;
    Film* keresCim(const std::string& cim) const;
    Film* keresHossz(int hossz) const;
    void listaz() const;
    void fajlbaIro() const;
};

#endif // FILMTAR_H_INCLUDED
