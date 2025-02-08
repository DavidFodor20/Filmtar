#include <iostream>

#include "Film.h"

std::string Film::getCim() const {//lekerdezes
    return cim;
}

int Film::getHossz() const {//lekerdezes
    return hossz;
}

int Film::getEv() const {//lekerdezes
    return ev;
}

void Film::kiiras() const {//kiiras
   std::cout<< "Cim: " << cim << ", Ev: " << ev << ", Hossz: " << hossz<<", ";
}

void Film::setCim(const std::string& c) {//beallitasok
    cim = c;
}

void Film::setEv(int e) {
    ev = e;
}

void Film::setHossz(int h) {
    hossz = h;
}

void Film::olvasasStreamrol(std::istream& is) {//olvasasstreamrol, eldobja a string elotti space-t a std::ws mainpulatorral
    std::string cim;
    int ev, hossz;

    std::getline(is >> std::ws, cim, ','); //eldonja a space-t és , ig olvas
    is >>  hossz;
    is.ignore();
    is >>ev;
    is.ignore();

    setCim(cim);
    setEv(ev);
    setHossz(hossz);
}

bool Film::operator==(const Film& other) const {//osszhasonlito operator
    return this->cim == other.cim &&
           this->hossz == other.hossz &&
           this->ev == other.ev;
}

void Film::fajlbaIras(std::ostream& os) const {//fajlbairas, mint a kiiras
    os <<cim <<", " << hossz << ", " << ev << ", " ;
}

Film::~Film() {}
