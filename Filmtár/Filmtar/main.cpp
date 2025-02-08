#include <iostream>
#include <string>
#include <stdexcept>
#include "Csaladi.h"
#include "Dokumentumfilm.h"
#include "Film.h"
#include "FilmTar.h"
#include "Horror.h"
#include "Mese.h"
#include "memtrace.h"
using namespace std;
///elso szamu tesztprogram, van benne minden, ami kell, hogy mûködjön a program, beolvasás, listázás, törlés, fájlba írás, keresés
///Van benne hibás adattal dolgozás, ekkor a program valamilyen hibajelzést dob vissza
///Van benne "saját kezûleg" hozzáadás, törlés, viszont nincs benne szabványos bemenetről adatok beszedése
void test_1(){
    Filmtar filmtar;
    try{
    filmtar.betolt("Filmek.txt");
    }
    catch (const std::runtime_error& e) {
    std::cout << "Hiba: " << e.what() << std::endl;
    }

    Film* mese = new Mese("alma", 17, 1996, "animalt");
    filmtar.addFilm(mese);
    try{
    filmtar.fajlbaIro();
    }
    catch (const std::runtime_error& e) {
    std::cout << "Hiba: " << e.what() << std::endl;
    }
    Film* torlendoFilm = nullptr;
    try{
    torlendoFilm = filmtar.getFilm(10);
    }catch(const std::out_of_range& e){
        std::cout << "Hiba: " << e.what() << std::endl;
    }
    filmtar.torol(torlendoFilm);
    filmtar.listaz();
    Film* talaltFilm = filmtar.keresEv(2030);
    if (talaltFilm == nullptr) {
    cout << "Nincs film a megadott evben." << endl;
    } else {
    cout<<"A keresett film adatai:";
    talaltFilm->kiiras();
    }
    Film* cimSzerintiFilm = filmtar.keresCim("Demonok kozott");
      if (cimSzerintiFilm == nullptr) {
    cout << "Nincs film a megadott cimmel." << endl;
    } else {
    cout<<"A keresett film adatai: ";
    cimSzerintiFilm->kiiras();}
    Film* hosszSzerintiFilm = filmtar.keresHossz(120);
      if (hosszSzerintiFilm == nullptr) {
    cout << "Nincs film a megadott hosszal." << endl;
    } else {
    cout<<"A keresett film adatai:";
    hosszSzerintiFilm->kiiras();}
    int meret=filmtar.getMeret();
    cout<<"A tarolo aktualis merete: "<<meret<<endl;
    Film* torlendoFilm2 = nullptr;
     try{
    torlendoFilm2 = filmtar.getFilm(150);
    }catch(const std::out_of_range& e){
        std::cout << "Hiba: " << e.what() << std::endl;
    }filmtar.torol(torlendoFilm2);
     try{
    filmtar.betolt("hibas.txt");
    }
    catch (const std::runtime_error& e) {
    std::cout << "Hiba: " << e.what() << std::endl;
    }
    Film* talaltFilm2 = filmtar.keresEv(2001);
    if (talaltFilm2 == nullptr) {
    cout << "Nincs film a megadott evben." << endl;
    } else {
    cout<<"A keresett film adatai:";
    talaltFilm2->kiiras();
    }
}

void test_2(){
        Filmtar filmtar;

    try {
        string fajlnev;
        cout << "Kerem adja meg a fajlnevet: ";
        cin >> fajlnev;
        filmtar.betolt(fajlnev);
    } catch (const runtime_error& e) {
        cout << "Hiba: " << e.what() << endl;
    }

    string cim;
    int hossz, ev;
    string tipus;
    cout << "Mese objektumot fog hozzaadni, mivel ha ezzel mukodik mindennel megy "<<endl;
    cout << "Kerem adja meg a film cimet: ";
    cin.ignore();
    getline(cin, cim);

    cout << "Kerem adja meg a film hosszat: ";
    cin >> hossz;

    cout << "Kerem adja meg a film evet: ";
    cin >> ev;

    cout << "Kerem adja meg a film tipusat: ";
    cin.ignore();
    getline(cin, tipus);

    Film* mese = new Mese(cim, hossz, ev, tipus);
    filmtar.addFilm(mese);

    try {
        filmtar.fajlbaIro();
        cout << "A filmek sikeresen ki lettek irva a Filmek.txt fajlba.\n";
    } catch (const runtime_error& e) {
        cout << "Hiba: " << e.what() << endl;
    }

    Film* torlendoFilm = nullptr;
    try {
        int index;
        cout << "Kerem adja meg a torlendo film indexet: ";
        cin >> index;

        torlendoFilm = filmtar.getFilm(index);
    } catch (const out_of_range& e) {
        cout << "Hiba: " << e.what() << endl;
    }

    if (torlendoFilm != nullptr) {
        filmtar.torol(torlendoFilm);
    }

    filmtar.listaz();

    int evKereses;
    cout << "Kerem adja meg az evet a film keresesehez: ";
    cin >> evKereses;

    Film* talaltFilm = filmtar.keresEv(evKereses);
    if (talaltFilm == nullptr) {
        cout << "Nincs film a megadott evben." << endl;
    } else {
        cout << "A keresett film adatai:";
        talaltFilm->kiiras();
    }

    string cimKereses;
    cout << "Kerem adja meg a film cimet a keresesehez: ";
    cin.ignore();
    getline(cin, cimKereses);

    Film* cimSzerintiFilm = filmtar.keresCim(cimKereses);
    if (cimSzerintiFilm == nullptr) {
        cout << "Nincs film a megadott cimmel." << endl;
    } else {
        cout << "A keresett film adatai: ";
        cimSzerintiFilm->kiiras();
    }

    int hosszKereses;
    cout << "Kerem adja meg a film hosszat a keresesehez: ";
    cin >> hosszKereses;

    Film* hosszSzerintiFilm = filmtar.keresHossz(hosszKereses);
    if (hosszSzerintiFilm == nullptr) {
        cout << "Nincs film a megadott hosszal." << endl;
    } else {
        cout << "A keresett film adatai:";
        hosszSzerintiFilm->kiiras();
    }

    int meret = filmtar.getMeret();
    cout << "A tarolo aktualis merete: " << meret << std::endl;

    Film* torlendoFilm2 = nullptr;
    try {
        int index2;
        cout << "Kerem adja meg a masodik torlendo film indexet: ";
        cin >> index2;

        torlendoFilm2 = filmtar.getFilm(index2);
    } catch (const out_of_range& e) {
        cout << "Hiba: " << e.what() << endl;
    }

    if (torlendoFilm2 != nullptr) {
        filmtar.torol(torlendoFilm2);
    }

    try {
        string hibasFajlnev;
        cout << "Kerem adja meg a hibas fajlnevet: ";
        cin >> hibasFajlnev;
        filmtar.betolt(hibasFajlnev);
    } catch (const runtime_error& e) {
        cout << "Hiba: " << e.what() << endl;
    }

    int evKereses2;
    cout << "Kerem adja meg a masodik evet a film keresesehez: ";
    cin >> evKereses2;

    Film* talaltFilm2 = filmtar.keresEv(evKereses2);
    if (talaltFilm2 == nullptr) {
        cout << "Nincs film a megadott evben." << endl;
    } else {
        cout << "A keresett film adatai:";
        talaltFilm2->kiiras();
    }

}


int main()
{
    test_1();
    test_2();

    return 0;
}
