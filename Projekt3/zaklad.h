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
//f wyswietlajaca dane instytutu (nazwa, dyrektor, liczba pracownikow)
void wyswietlDane();
//f dodajaca nowego praconika do zakladu, instytutu i wydzialu (o ile nie byl wczesniej pracownikiem)
bool dodajPracownika(pracownik* pr);
//f zwlaniajaca pracownika z zakladu
bool zwolnijPracownika(pracownik* pr);
//f zwracajaca wskaznik na dyrektora zakladu
inline pracownik* pokazDyrektora(){return dyrZakladu;};
//funkcja zmieniajaca dyrektora zakladu
inline void zmienDyrektora(pracownik* pr){dyrZakladu=pr;}
};

#endif // ZAKLAD_H_INCLUDED
