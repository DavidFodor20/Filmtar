#ifndef CSALADI_H_INCLUDED
#define CSALADI_H_INCLUDED
#include <sstream>
#include<string>
#include "Film.h"
#include "memtrace.h"

class CsaladiFilm : public Film {  //csaladiosztaly
private:
    int korhatar;

public:
    CsaladiFilm() : Film(), korhatar(0) {}
    CsaladiFilm(std::string cim, int ev, int hossz, int korhatar) : Film(cim, ev, hossz), korhatar(korhatar) {}

    virtual int getKorhatar() const;

    void setKorhatar(int k);

    void kiiras() const override;

    void olvasasStreamrol(std::istream& stream)override;

    void fajlbaIras(std::ostream& os) const ;

    ~CsaladiFilm();
};

#endif // CSALADI_H_INCLUDED
