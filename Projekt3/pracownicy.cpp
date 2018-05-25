#include "pracownicy.h"
#include <string.h>

using namespace std;

/*************************/

pracownik::pracownik(const char* im, const char* nazw, const int w, const char* stan)
{
    strncpy(imie, im, ROZMIAR-1);
    strncpy(nazwisko, nazw, ROZMIAR-1);
    wiek=w;
    strncpy(stanowisko, stan, ROZMIAR-1);

};

void pracownik::wyswietlDane()
{
    std::cout<<imie<<" "<<nazwisko<<" "<<wiek<<" lat "<<"stanowisko: "<<stanowisko<<std::endl;
};

/***********************/

inzynier::inzynier(const char* im, const char* nazw, const int w, const char* stan):pracownik(im,nazw,w,stan)
{

};

void inzynier::wyswietlDane()
{
    std::cout<<tytul<<" ";
    pracownik::wyswietlDane();
};

/**********************/
magister::magister(const char* im, const char* nazw, const int w, const char* stan):inzynier(im,nazw,w,stan){};

void magister::wyswietlDane(){
std::cout<<tytul<<" ";
pracownik::wyswietlDane();
};
