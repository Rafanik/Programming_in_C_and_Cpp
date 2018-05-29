#ifndef PRACOWNICY_H_INCLUDED
#define PRACOWNICY_H_INCLUDED
#include <string.h>
#include <iostream>
#include <iomanip>

class wydzial;
class instytut;
class zaklad;

/*plik naglowkowy dla klasy pracownik oraz klas pochodnych
klasy pochodne roznia sie od bazowej jedynie tytulami, wiec jest
inne atrybuty moga zostac dodane */

class pracownik
{
protected:
//dane osobowe:
    enum {ROZMIAR = 20};
    char imie[ROZMIAR];
    char nazwisko[ROZMIAR];
    int wiek;
    char stanowisko[ROZMIAR];
//wydzial, instytut, zaklad, do ktorego dany pracownik nalezy:
    wydzial* pracownik_wydzial;
    instytut* pracownik_instytut;
    zaklad* pracownik_zaklad;


public:
//konstruktor:
    pracownik(const char* im = "brak", const char* nazw = "brak", const int w = 0);
//wyswietlanie danych osobowych:
    virtual void wyswietlDane();
//dostep do danych
    inline char* podajImie(){return imie;}
    inline char* podajNazwisko(){return nazwisko;}
    inline int podajWiek(){return wiek;}
//funkcje pozwalajace ustawiac wydzial, instytut, zaklad, do ktorego dany pracownik nalezy:
    inline void dodajWydzial(wydzial* w) {pracownik_wydzial = w;}
    inline void dodajInstytut(instytut* i) {pracownik_instytut = i;}
    inline void dodajZaklad(zaklad* z) {pracownik_zaklad = z;}
    inline void usunZaklad(){pracownik_zaklad = nullptr;}
    inline void usunInstytut(){pracownik_instytut = nullptr;}
    inline void usunWydzial(){pracownik_wydzial = nullptr;}
//funkcje zwracajace wskazanie na wydzial/zaklad/instytut, do ktorego dany pracownik nalezy
    inline wydzial* pokaz_wydzial(){return pracownik_wydzial;}
    inline instytut* pokaz_instytut() {return pracownik_instytut;}
    inline zaklad* pokaz_zaklad() {return pracownik_zaklad;}
//funkcja promujaca na inzyniera:
    void promujNaInzyniera();
};

//klasy pochodne:
//sciezka naukowa
class inzynier : public virtual pracownik
{
protected:
    const char* tytul = "inz.";
public:
    inzynier(const char* im = "brak", const char* nazw = "brak", const int w = 0);
    virtual void wyswietlDane();
};

class magister : public inzynier
{
protected:
    const char* tytul = "mgr inz.";
public:
    magister(const char* im = "brak", const char* nazw = "brak", const int w = 0);
    virtual void wyswietlDane();
};

class doktor : public magister
{
protected :
    const char* tytul ="dr";
public :
    doktor(const char* im = "brak", const char* nazw = "brak", const int w = 0);
    virtual void wyswietlDane();
};

class doktorHab : public doktor
{
protected :
    const char* tytul ="dr hab.";
public :
    doktorHab (const char* im = "brak", const char* nazw = "brak", const int w = 0);
    virtual void wyswietlDane();
};

class profesor : public doktorHab
{
protected :
    const char* tytul = "prof.";
public :
    profesor (const char* im = "brak", const char* nazw = "brak", const int w = 0);
    virtual void wyswietlDane();

};

//sciezka naukowo dydaktyczna:
class asystent : public virtual pracownik{
protected:
    const char * stanowisko = "asystent";
public:
    asystent (const char* im = "brak", const char* nazw = "brak", const int w = 0);
};

class adiunkt : public asystent{
protected:
    const char * stanowisko = "adiunkt";
public:
    adiunkt (const char* im = "brak", const char* nazw = "brak", const int w = 0);
};

class profesorNadzw : public adiunkt {
protected:
    const char * stanowisko = "profesor nadzwyczajny";
public:
    profesorNadzw (const char* im = "brak", const char* nazw = "brak", const int w = 0);
};

class profesorZw : public profesorNadzw {
protected:
    const char * stanowisko = "profesor zwyczajny";
public:
    profesorZw (const char* im = "brak", const char* nazw = "brak", const int w = 0);
};

//sciezka dydaktyczna
class wykladowca : public virtual pracownik{
protected:
    const char * stanowisko = "wykladowca";
public:
    wykladowca (const char* im = "brak", const char* nazw = "brak", const int w = 0);
};

class starszyWykladowca : public wykladowca{
protected:
    const char * stanowisko = "starszy wykladowca";
public:
    starszyWykladowca (const char* im = "brak", const char* nazw = "brak", const int w = 0);
};

class docent : public starszyWykladowca{
protected:
    const char * stanowisko = "docent";
public:
    docent (const char* im = "brak", const char* nazw = "brak", const int w = 0);
};

class inzynierAsystent;

//pracownicy powstali z polaczenia klas:
class inzynierWykladowca : public inzynier, public wykladowca {
public:
inzynierWykladowca(const char* im = "brak", const char* nazw = "brak", const int w = 0);
inzynierWykladowca(inzynierAsystent*);
virtual void wyswietlDane();

};

class inzynierAsystent : public inzynier, public asystent {
public:
inzynierAsystent(const char* im = "brak", const char* nazw = "brak", const int w = 0);
virtual void wyswietlDane();
};


#endif // PRACOWNICY_H_INCLUDED
