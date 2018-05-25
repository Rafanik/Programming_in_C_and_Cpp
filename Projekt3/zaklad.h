#ifndef ZAKLAD_H_INCLUDED
#define ZAKLAD_H_INCLUDED
#include "jednostkiOrganizacyjne.h"
#include "pracownicy.h"

class instytut;

class zaklad : jednostkaOrganizacyjna{
instytut* in;
pracownik* dyrZakladu;
pracownik* zcaDyrZakladu;
public:
zaklad(const char*, pracownik*, instytut*);
void wyswietlDane();
/*bool dodajPracownika(pracownik* pr);
void wyswietlPracownikow();
bool zwolnijPracownika(pracownik* pr);*/
};

#endif // ZAKLAD_H_INCLUDED
