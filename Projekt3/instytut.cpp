#include "pracownicy.h"
#include "wydzial.h"
#include "instytut.h"
#include "zaklad.h"

#include <vector>
#include <string.h>
#include <ios>

using std::cout;
using std::endl;

instytut::instytut(const string nazw, pracownik* dyr, wydzial* w) : jednostkaOrganizacyjna(nazw)
{
    instytut_wydzial=w;
    w->dodajInstytut(this);
    dyrInstytutu=dyr;
    dodajPracownika(dyrInstytutu);
};

void instytut::wyswietlDane()
{
    cout<<"instytut:"<<nazwa<<endl<<"Dyrektor: ";
    dyrInstytutu->wyswietlDane();
    cout<<"pracownicy:"<<listaPracownikow.size()<<endl;
    cout<<"zakladay:"<<listaZakladow.size()<<endl;
};

bool instytut::dodajZaklad(zaklad* zakl)
{
    int i;
    for(i = 0; i<listaZakladow.size(); i++)
    {
        if(listaZakladow[i]==zakl)
        {
            //cout<<"ten instytut juz istnieje"<<endl;
            return 0;
        }
    }
    listaZakladow.push_back(zakl);
    //zakl->dodajInstytut(this);
    //cout<<"dodano instytut"<<endl;
    return 1;
};

bool instytut::dodajPracownika(pracownik* pr)
{
int i;
    for(i = 0; i<listaPracownikow.size(); i++)
    {
        if(listaPracownikow[i]==pr)
        {
            //cout<<"ten pracownik juz tu pracuje"<<endl;
            return 0;
        }
    }
    listaPracownikow.push_back(pr);
    instytut_wydzial->dodajPracownika(pr);
    pr->dodajInstytut(this);
    pr->dodajWydzial(this->instytut_wydzial);
    //cout<<"dodano pracownika"<<endl;
    return 1;
};

bool instytut::zwolnijPracownika(pracownik* pr)
{
    int i;
    for(i = 0; i<listaPracownikow.size(); i++)
    {
        if(listaPracownikow[i]==pr)
        {
            listaPracownikow.erase(listaPracownikow.begin()+i);
            if(pr->pokaz_zaklad()!=nullptr)
            {
            pr->pokaz_zaklad()->zwolnijPracownika(pr);
            }
            pr->usunInstytut();
            //cout<<"zwolniono pracownika"<<endl<<endl;
            return 1;
        }
    }
    cout<<"nie zwolniono pracownika"<<endl;
    return 0;
};
