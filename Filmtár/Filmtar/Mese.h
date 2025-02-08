#ifndef MESE_H_INCLUDED
#define MESE_H_INCLUDED
#include "Film.h"
#include "memtrace.h"
#include <string>
#include <sstream>

class Mese : public Film {      //mese alosztaly
private:
    std::string tipus; //pl animalt vagy eloszereplos

public:
    Mese(std::string cim="", int hossz=0, int ev=0, std::string tip="") : Film(cim, hossz, ev), tipus(tip) {}

    std::string getTipus() const;

    void setTipus(std::string tip);

    void olvasasStreamrol(std::istream& stream) override;

    void kiiras() const override;


    void fajlbaIras(std::ostream& os)const ;

    ~Mese();

};



#endif // MESE_H_INCLUDED
