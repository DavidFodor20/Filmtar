#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

#include <string>

class Film {            //film osztaly, ez az ososztaly, ezeket a pointereket tarolja a kollekcio
private:
    std::string cim;
    int hossz;
    int ev;

public:
    Film(std::string cim="", int hossz=0, int ev=0) : cim(cim), hossz(hossz), ev(ev) {}

    std::string getCim() const;
    int getHossz() const;
    int getEv() const;
    virtual void setCim(const std::string& c);
    virtual void setEv(int e);
    virtual void setHossz(int h);
    virtual void kiiras() const;

    bool operator==(const Film& other) const;
    virtual void olvasasStreamrol(std::istream& stream);
    virtual void fajlbaIras(std::ostream& os) const ;
    virtual ~Film();
};

#endif // FILM_H_INCLUDED
