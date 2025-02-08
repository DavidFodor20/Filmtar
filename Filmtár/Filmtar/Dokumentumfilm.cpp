#include <iostream>
#include <string>
#include <sstream>
#include "Dokumentumfilm.h"
#include "Film.h"



std::string Dokumentumfilm::getLeiras() const {     //lekerdezes
    return leiras;
}

void Dokumentumfilm::setLeiras(const std::string& l) {      //beallitas
    leiras=l;
}

void Dokumentumfilm::kiiras() const {         //kiiras
    std::cout<<"Mufaj: Dokumentumfilm, ";
    Film::kiiras();                     //film osztaly fuggvenye
   std::cout<<"Leiras: " << leiras << std::endl;}

void Dokumentumfilm::olvasasStreamrol(std::istream& stream) {       //olvasas streamrol
    Film::olvasasStreamrol(stream);         //film osztaly fuggvenye
    std::string leiras;
    stream.ignore();                        //space eldobasa
    getline(stream, leiras);
    if (!stream ) return;                   //ha baj kilep
    setLeiras(leiras);
}

void Dokumentumfilm::fajlbaIras(std::ostream& os) const {       //fajlbairas
    os << "Dokumentumfilm, ";
    Film::fajlbaIras(os);
    os<<getLeiras()<<std::endl;
}

Dokumentumfilm::~Dokumentumfilm() {}
