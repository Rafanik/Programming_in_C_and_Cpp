#include "pracownicy.h"
#include <string>

using namespace std;

/*************************/

pracownik::pracownik(const string im, const string nazw, const int w)
{
    tytul = new tytulNaukowy;
    stanowisko = new stanowiskoDydaktyczne;
    imie = im;
    nazwisko = nazw;
    wiek=w;

};

void pracownik::wyswietlDane()
{

    std::cout<<tytul->podajTytul()<<imie<<" "<<nazwisko<<" "<<wiek<<" lat "<<"stanowisko: "<<stanowisko->podajStanowisko()<<endl;
};


void pracownik::promujNaInzyniera()
{
    delete tytul;
    tytul = new inzynier;
};

void pracownik::promujNaMagistra()
{
    delete tytul;
    tytul = new magister;
};

void pracownik::promujNaDoktora()
{
    delete tytul;
    tytul = new doktor;
};

void pracownik::promujNaDoktoraHab()
{
    delete tytul;
    tytul = new doktorHab;
};

void pracownik::promujNaProfesora()
{
    delete tytul;
    tytul = new profesor;
};

    void pracownik::promujNaAsystenta(){
    delete stanowisko;
    stanowisko = new asystent;
    };
    void pracownik::promujNaAdiunkta(){
    delete stanowisko;
    stanowisko = new adiunkt;
    };
    void pracownik::promujNaProfesoraNadzw(){
    delete stanowisko;
    stanowisko = new profesorNadzw;
    };
    void pracownik::promujNaProfesoraZw(){
    delete stanowisko;
    stanowisko = new profesorZw;
    };

    void pracownik::promujNaWykladowce(){
    delete stanowisko;
    stanowisko = new wykladowca;
    };
    void pracownik::promujNaSatrszegoWykladowce(){
    delete stanowisko;
    stanowisko = new starszyWykladowca;
    };
    void pracownik::promujNaDocenta(){
    delete stanowisko;
    stanowisko = new docent;
    };

