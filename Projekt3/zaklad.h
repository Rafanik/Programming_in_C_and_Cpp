#ifndef ZAKLAD_H_INCLUDED
#define ZAKLAD_H_INCLUDED
#include "jednostkiOrganizacyjne.h"
#include "pracownicy.h"

class instytut;

class zaklad : public jednostkaOrganizacyjna{
instytut* zaklad_instytut;
pracownik* dyrZakladu;
pracownik* zcaDyrZakladu;
public:
zaklad(const string, pracownik*, instytut*);
void wyswietlDane();
bool dodajPracownika(pracownik* pr);
bool zwolnijPracownika(pracownik* pr);
};

#endif // ZAKLAD_H_INCLUDED
