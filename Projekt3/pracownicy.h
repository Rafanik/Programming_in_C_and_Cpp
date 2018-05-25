#ifndef PRACOWNICY_H_INCLUDED
#define PRACOWNICY_H_INCLUDED
#include <string.h>
#include <iostream>
#include <iomanip>

class wydzial;
class instytut;

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
    wydzial* wyd;
    instytut* ins;
    zaklad* zak;


public:
//konstruktor:
    pracownik(const char* im = "brak", const char* nazw = "brak", const int w = 0,const char* stan = "brak");
//wyswietlanie danych osobowych:
    virtual void wyswietlDane();
//funkcje pozwalajace ustawiac wydzial, instytut, zaklad, do ktorego dany pracownik nalezy:
    inline void dodajWydzial(wydzial* w) {wyd = w;}
    inline void dodajInstytut(instytut* i) {ins = i;}
    inline void usunInstytut(){ins = nullptr;}
    inline void usunWydzial(){wyd = nullptr;}
//funkcje zwracajace wskazanie na wydzial/zaklad/instytut, do ktorego dany pracownik nalezy
    inline wydzial* wydz(){return wyd;}
    inline instytut* inst() {return ins;}
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
