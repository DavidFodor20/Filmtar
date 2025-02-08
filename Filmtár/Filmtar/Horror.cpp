#include "Horror.h"
#include "Film.h"
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>

std::string Horrorfilm::getFajta() const {// lekerdezes
    return fajta;
}

void Horrorfilm::setFajta(const std::string& f) {       //beallitas
    fajta=f;
}

void Horrorfilm::kiiras() const {       //kiiras
    std::cout<<"Mufaj: Horrorfilm, ";
     Film::kiiras();                    //film osztaly fuggvenye
   std::cout<<"Fajta: " << fajta << std::endl;
}

void Horrorfilm::olvasasStreamrol(std::istream& stream) {//olvasas streamrol
    Film::olvasasStreamrol(stream);//film osztaly fuggvenye
    std::string fajta;
    stream.ignore();        //space eldobas
    getline(stream, fajta);
    if(!stream) return;     //ha baj kilep
    setFajta(fajta);
}

void Horrorfilm::fajlbaIras(std::ostream& os) const {// fajlbairas
    os << "Horror, ";
    Film::fajlbaIras(os);
    os<< getFajta()<<std::endl;
}

Horrorfilm::~Horrorfilm() {}
