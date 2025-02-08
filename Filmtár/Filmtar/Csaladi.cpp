#include "Film.h"
#include "Csaladi.h"
#include <string>
#include <sstream>
#include <iostream>

int CsaladiFilm::getKorhatar() const {      //lekerdezes
    return korhatar;
}

void CsaladiFilm::setKorhatar(int k)  {     //beallitas
    korhatar = k;
}


void CsaladiFilm::kiiras() const {          //elobb a mufaj, majd kozos attributum, majd a sajat
    std::cout<<"Mufaj: Csaladifilm, ";
    Film::kiiras();
   std::cout<<"Korhatar: " << korhatar << std::endl;
}

void CsaladiFilm::olvasasStreamrol(std::istream& stream) {
    Film::olvasasStreamrol(stream);  //Film osztaly fuggvenyet hivja
    if(!stream) return ;            //ha nem jo kilep
    int korhatar;
    stream >> korhatar;
    setKorhatar(korhatar);  //beallitja a korhatart
}


void CsaladiFilm::fajlbaIras(std::ostream& os) const {//mint a kiiras
    os << "Csaladifilm, ";
    Film::fajlbaIras(os);
    os<< getKorhatar()<<std::endl;
}

CsaladiFilm::~CsaladiFilm() {}
