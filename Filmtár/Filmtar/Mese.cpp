#include "Film.h"
#include "Mese.h"
#include <string>
#include <sstream>
#include <iostream>

std::string Mese::getTipus() const {//lekerdezes
    return tipus;
}

void Mese::setTipus(std::string tip) {//beallitas
    tipus = tip;
}

void Mese::olvasasStreamrol(std::istream& stream) {
    Film::olvasasStreamrol(stream);  //Film osztaly fuggvenyet hivja
    std::string tipus;
    stream.ignore();
    std::getline(stream, tipus);  // beolvas egy sort
    if(!stream) return ;
    setTipus(tipus); // beallitom a tipust
}

void Mese::kiiras() const {     //kiiras
    std::cout<<"Mufaj: Mese, ";
    Film::kiiras();
   std::cout<<"Tipus: " << tipus << std::endl;
   }


void Mese::fajlbaIras(std::ostream& os) const {     //fajlba iras
    os << "Mese, ";
    Film::fajlbaIras(os);
    os<<getTipus()<<std::endl;
}

Mese::~Mese() {}
