#ifndef PRACOWNICY_H_INCLUDED
#define PRACOWNICY_H_INCLUDED
#include <string>
#include <iostream>
#include <iomanip>
#include "tytulyNaukowe.h"
#include "stanowiskaDydaktyczne.h"

class wydzial;
class instytut;
class zaklad;



using namespace std;

/*plik naglowkowy dla klasy pracownik oraz klas pochodnych
klasy pochodne roznia sie od bazowej jedynie tytulami, wiec jest
inne atrybuty moga zostac dodane */

class pracownik
{
protected:
//dane osobowe:
    string imie;
    string nazwisko;
    int wiek;
    tytulNaukowy* tytul;
    stanowiskoDydaktyczne* stanowisko;
//wydzial, instytut, zaklad, do ktorego dany pracownik nalezy:
    wydzial* pracownik_wydzial=nullptr;
    instytut* pracownik_instytut=nullptr;
    zaklad* pracownik_zaklad=nullptr;
    inzynier nowyInzynier();
    void promujNaukowo(tytulNaukowy);

public:
//konstruktor:
    pracownik( string im = "brak", string nazw = "brak", const int w = 0);
//wyswietlanie danych osobowych:
    virtual void wyswietlDane();
//dostep do danych
    inline string podajImie()
    {
        return imie;
    }
    inline string podajNazwisko()
    {
        return nazwisko;
    }
    inline int podajWiek()
    {
        return wiek;
    }
//funkcje pozwalajace ustawiac wydzial, instytut, zaklad, do ktorego dany pracownik nalezy:
    inline void dodajWydzial(wydzial* w)
    {
        pracownik_wydzial = w;
    }
    inline void dodajInstytut(instytut* i)
    {
        pracownik_instytut = i;
    }
    inline void dodajZaklad(zaklad* z)
    {
        pracownik_zaklad = z;
    }
    inline void usunZaklad()
    {
        pracownik_zaklad = nullptr;
    }
    inline void usunInstytut()
    {
        pracownik_instytut = nullptr;
    }
    inline void usunWydzial()
    {
        pracownik_wydzial = nullptr;
    }
//funkcje zwracajace wskazanie na wydzial/zaklad/instytut, do ktorego dany pracownik nalezy
    inline wydzial* pokaz_wydzial()
    {
        return pracownik_wydzial;
    }
    inline instytut* pokaz_instytut()
    {
        return pracownik_instytut;
    }
    inline zaklad* pokaz_zaklad()
    {
        return pracownik_zaklad;
    }

//funkcje promujace
    void promujNaInzyniera();
    void promujNaMagistra();
    void promujNaDoktora();
    void promujNaDoktoraHab();
    void promujNaProfesora();

    void promujNaAsystenta();
    void promujNaAdiunkta();
    void promujNaProfesoraNadzw();
    void promujNaProfesoraZw();

    void promujNaWykladowce();
    void promujNaSatrszegoWykladowce();
    void promujNaDocenta();

};









#endif // PRACOWNICY_H_INCLUDED
