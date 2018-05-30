#ifndef JEDNOSTKIORGANIZACYJNE_H_INCLUDED
#define JEDNOSTKIORGANIZACYJNE_H_INCLUDED

#include "pracownicy.h"
#include <string>
#include <vector>

//abstrakcyjna klasa bazowa dla klas: wydzial, instytut, zaklad

class jednostkaOrganizacyjna
{
//posiadane pola - nazwa jednostki, wektor wskazan na pracownikow
protected:
    string nazwa;
    std::vector<pracownik *> listaPracownikow;
public:
    jednostkaOrganizacyjna(const string);
//metoda wyswietlajaca nazwe i liczbe pracownikow
    virtual void wyswietlDane()=0;
//metoda wyswietlajaca dane osobowe wszystkich pracownikow danej jednostki
    virtual void wyswietlPracownikow();
//metoda dodajaca lub zwalniajaca pracownika (dodanie do wektora)
    virtual bool dodajPracownika(pracownik*);
    virtual bool zwolnijPracownika(pracownik*);
//metoda zwracajaca wskaznik na pracownika o podanym indeksie -1
    inline pracownik* pokaz_pracownika(int i)
    {
        return listaPracownikow[i-1];
    }

};



#endif // JEDNOSTKIORGANIZACYJNE_H_INCLUDED
