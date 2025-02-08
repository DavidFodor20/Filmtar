#ifndef DOKUMENTUMFILM_H_INCLUDED
#define DOKUMENTUMFILM_H_INCLUDED
#include "Film.h"
#include <string>
#include <sstream>
#include "memtrace.h"



class Dokumentumfilm: public Film {//dokumentumfilm osztaly
private:
        std::string leiras;     //rovid leiras, hogy mirol szol
public:
    Dokumentumfilm(std::string c, int h, int e, std::string leiras):Film(c, h, e), leiras(leiras) {}
    Dokumentumfilm() : Film(), leiras("") {}

    std::string getLeiras() const;

    void setLeiras(const std::string& l);

    void kiiras() const override;

    void fajlbaIras(std::ostream& os) const;

    void olvasasStreamrol(std::istream& stream) override;

    ~Dokumentumfilm();
    };


#endif // DOKUMENTUMFILM_H_INCLUDED
