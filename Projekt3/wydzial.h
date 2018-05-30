#ifndef WYDZIAL_H_INCLUDED
#define WYDZIAL_H_INCLUDED
#include "jednostkiOrganizacyjne.h"
#include "instytut.h"
//klasa pochodna klasy abstrakcyjnej - jednostka organizacyjna
class wydzial : public jednostkaOrganizacyjna
{
//dizekan
pracownik* dziekan;
//wektory wskazan na pracownikow, ktorzy sa prodziekanami
std::vector<pracownik *> listaProdziekanow;
//wketor wskazan na instytuty, ktore naleza do wydzialu
std::vector<instytut *> listaInstytutow;
public:
//konstruktor jako parametr przyjmuje nazwe wydzialu i wskazanie na pracownika, ktory bdz rektorem
wydzial(const string, pracownik*);
//funkcja wyswietlajaca nazwe, dane rektora i liczbe pracownikow wydzialu
void wyswietlDane();
//funkcja dodajaca nowy instytut do wydzialu
bool dodajInstytut(instytut*);
//f wyswietlajaca dane instytutow nalezacych do wydzialu
void wyswietlInstytuty();
//f dodajaca pracownika do wydzialu (nie do konkretnego zakladu czy instytutu)
bool dodajPracownika(pracownik*);
//f dodajaca prodziekana (jesli nie jest pracownikiem wydzialu to rowniez do wydzialu)
bool dodajProdziekana(pracownik*);
//f zwlaniajaca pracownika z wydzialu (a co za tym idzie z instytutow i zakladow, w ktorych pracuje)
bool zwolnijPracownika(pracownik*);
};



#endif // WYDZIAL_H_INCLUDED
