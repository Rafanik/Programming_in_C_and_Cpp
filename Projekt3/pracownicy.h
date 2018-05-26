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
    pracownik(const char* im = "brak", const char* nazw = "brak", const int w = 0,const char* stan = "brak");
//wyswietlanie danych osobowych:
    virtual void wyswietlDane();
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
};

//klasy pochodne:
class inzynier : public pracownik
{
private:
    const char* tytul = "inz.";
public:
    inzynier(const char* im = "brak", const char* nazw = "brak", const int w = 0,const char* stan = "brak");
    virtual void wyswietlDane();
};

class magister : public inzynier
{
private:
    const char* tytul = "mgr inz.";
public:
    magister(const char* im = "brak", const char* nazw = "brak", const int w = 0, const char* stan = "brak");
    virtual void wyswietlDane();
};



#endif // PRACOWNICY_H_INCLUDED
