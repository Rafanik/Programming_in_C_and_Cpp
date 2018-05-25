#ifndef JEDNOSTKIORGANIZACYJNE_H_INCLUDED
#define JEDNOSTKIORGANIZACYJNE_H_INCLUDED

#include "pracownicy.h"

#include <vector>

//abstrakcyjna klasa bazowa dla klas: wydzial, instytut, zaklad

class jednostkaOrganizacyjna
{
//posiadane pola - nazwa jednostki, wektor wskazan na pracownikow
protected:
    enum {ROZMIAR = 40};
    char nazwa[ROZMIAR];
    std::vector<pracownik *> listaPracownikow;
public:
    jednostkaOrganizacyjna(const char*);
//metoda wyswietlajaca nazwe i liczbe pracownikow
    virtual void wyswietlDane()=0;
//metoda wyswietlajaca dane osobowe wszystkich pracownikow danej jednostki
    virtual void wyswietlPracownikow();
//metoda dodajaca lub zwalniajaca pracownika (dodanie do wektora)
    virtual bool dodajPracownika(pracownik*);
    virtual bool zwolnijPracownika(pracownik*);

};



#endif // JEDNOSTKIORGANIZACYJNE_H_INCLUDED
