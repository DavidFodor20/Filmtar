#ifndef HORROR_H_INCLUDED
#define HORROR_H_INCLUDED
#include <string>
#include <sstream>
#include <iostream>
#include "Film.h"
#include "memtrace.h"




class Horrorfilm : public Film {        //horror alosztaly
private:
    std::string fajta; //pl thriller vagy verengzos, vagy misztikus
public:
    Horrorfilm(std::string cim="", int hossz=0, int kiadasiEv=0,const std::string& fajta="") : Film(cim, hossz, kiadasiEv), fajta(fajta){}

    std::string getFajta() const ;

    void setFajta(const std::string& f);

    ~Horrorfilm();

    void kiiras() const override ;

    void fajlbaIras(std::ostream& os) const;

    void olvasasStreamrol(std::istream& stream) override;
};


#endif // HORROR_H_INCLUDED
