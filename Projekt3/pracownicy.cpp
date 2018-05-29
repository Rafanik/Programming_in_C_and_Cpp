#include "pracownicy.h"
#include <string.h>

using namespace std;

/*************************/

pracownik::pracownik(const char* im, const char* nazw, const int w)
{

    cout<<"pracownik"<<endl;
    strncpy(imie, im, ROZMIAR-1);
    strncpy(nazwisko, nazw, ROZMIAR-1);
    wiek=w;

};

void pracownik::wyswietlDane()
{
    std::cout<<imie<<" "<<nazwisko<<" "<<wiek<<" lat ";
};

/***********************/

inzynier::inzynier(const char* im, const char* nazw, const int w):pracownik(im,nazw,w)
{

};

void inzynier::wyswietlDane()
{
    pracownik::wyswietlDane();
};

/**********************/
magister::magister(const char* im, const char* nazw, const int w):inzynier(im,nazw,w){};

void magister::wyswietlDane(){
std::cout<<tytul<<" ";
pracownik::wyswietlDane();
};

/***********************/

doktor::doktor(const char* im, const char* nazw, const int w):magister(im,nazw,w){};

void doktor::wyswietlDane(){
cout<<tytul<<" ";
pracownik::wyswietlDane();
};
/***********************/

doktorHab::doktorHab(const char* im, const char* nazw, const int w):doktor(im,nazw,w){};

void doktorHab::wyswietlDane(){
cout<<tytul<<" ";
pracownik::wyswietlDane();
};

/*********************/

profesor::profesor(const char* im, const char* nazw, const int w):doktorHab(im,nazw,w){};

void profesor::wyswietlDane(){
cout<<tytul<<" ";
pracownik::wyswietlDane();
};

/********************/

asystent::asystent(const char* im, const char* nazw, const int w):pracownik(im,nazw,w){};

/*********************/

adiunkt::adiunkt(const char* im, const char* nazw, const int w):asystent(im,nazw,w){};

/*********************/

profesorNadzw::profesorNadzw(const char* im, const char* nazw, const int w):adiunkt(im,nazw,w){};

/**********************/

profesorZw::profesorZw(const char* im, const char* nazw, const int w):profesorNadzw(im,nazw,w){};

/************************/

wykladowca::wykladowca(const char* im, const char* nazw, const int w):pracownik(im,nazw,w){};

/************************/

starszyWykladowca::starszyWykladowca(const char* im, const char* nazw, const int w):wykladowca(im,nazw,w){};

/***********************/

docent::docent(const char* im, const char* nazw, const int w):starszyWykladowca(im,nazw,w){};

/*************************/

inzynierWykladowca::inzynierWykladowca(const char* im, const char* nazw, const int w){

    strncpy(imie, im, ROZMIAR-1);
    strncpy(nazwisko, nazw, ROZMIAR-1);
    wiek=w;

};

inzynierWykladowca::inzynierWykladowca(inzynierAsystent* inz){
  strncpy(imie, inz->podajImie() , ROZMIAR-1);
    strncpy(nazwisko, inz->podajNazwisko(), ROZMIAR-1);
    wiek=inz->podajWiek();
}

void inzynierWykladowca::wyswietlDane(){

cout<<inzynier::tytul;
pracownik::wyswietlDane();
cout<<"stanowisko: "<<wykladowca::stanowisko<<endl;

}

/************************/

inzynierAsystent::inzynierAsystent(const char* im, const char* nazw, const int w){

    strncpy(imie, im, ROZMIAR-1);
    strncpy(nazwisko, nazw, ROZMIAR-1);
    wiek=w;

};

void inzynierAsystent::wyswietlDane(){

cout<<inzynier::tytul;
pracownik::wyswietlDane();
cout<<"stanowisko: "<<asystent::stanowisko<<endl;

}
