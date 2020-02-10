#ifndef INSTYTUT_H_INCLUDED
#define INSTYTUT_H_INCLUDED
#include "jednostkiOrganizacyjne.h"
class wydzial;
class zaklad;
//klasa pochodna klasy abstrakcyjnej - jednostka organizacyjna
class instytut : public jednostkaOrganizacyjna{
protected:
//wskazanie na wydzial, do ktorego nalezy instytut
wydzial* instytut_wydzial;
//pracownicy na stanowiskach zarzadzajacych
pracownik* dyrInstytutu;
pracownik* zcaDyrInstytutu;
//wektor zakladow podlegajacyh temu instytutowi
std::vector<zaklad *> listaZakladow;

public:
//f tworzaca nowy instytut na konkretnym wydziale
instytut(const string,pracownik*,wydzial*);
//f wyswietlajaca nazwe instytutu, dyrektora i liczbe pracownikow
void wyswietlDane();
//f dodaje pracownika do instytutu i jesli nie jest pracownikkiem wydzialu to rowniez do wydzialu
bool dodajPracownika(pracownik*);
//f zwalnia pracownika z pracy w instytucie (a co za tym idzie rowniez z pracy w zakladach, ale nie z wydzialu)
bool zwolnijPracownika(pracownik*);
//f dodajaca nowy zaklad
bool dodajZaklad(zaklad*);
//f wyswietlajaca zaklady
void wyswietlZaklady();
//f pozwalajaca ustawic wskazanie na wydzial do jakiego nalezy instytut
inline void dodajWydzial(wydzial* w) {instytut_wydzial=w;}
//f zwracajaca nazwe instytutu
inline string pokazNazwe(){return nazwa;};
//f zwracajaca wskaznik na zaklad z listy (numerowanej od 1.)
inline zaklad* pokazZaklad(int i){return listaZakladow[i-1];};
//f zwracajac liczbe zakladow
inline int liczbaZakladow(){return listaZakladow.size();};
//f zwracajaca wskaznik na dyrektora instytutu
inline pracownik* pokazDyrektora(){return dyrInstytutu;};
//funkcja zmieniajaca dyrektora instytutu
inline void zmienDyrektora(pracownik* pr){dyrInstytutu=pr;}
};

#endif // INSTYTUT_H_INCLUDED
