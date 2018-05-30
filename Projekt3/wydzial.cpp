#include "pracownicy.h"
#include "wydzial.h"
#include "instytut.h"

#include <vector>
#include <string.h>
#include <ios>

using std::cout;
using std::endl;

wydzial::wydzial(const char* nazw, pracownik* dziek) : jednostkaOrganizacyjna(nazw)
{
    dziekan=dziek;
    dodajPracownika(dziekan);
};

void wydzial::wyswietlDane()
{
    cout<<"wydzial:"<<nazwa<<endl<<"Dziekan: ";
    dziekan->pracownik::wyswietlDane();
    cout<<"pracownicy:"<<listaPracownikow.size()<<endl;
    cout<<"instytuty:"<<listaInstytutow.size()<<endl;
};

bool wydzial::dodajInstytut(instytut* inst)
{
    int i;
    for(i = 0; i<listaInstytutow.size(); i++)
    {
        if(listaInstytutow[i]==inst)
        {
            return 0;
        }
    }
    listaInstytutow.push_back(inst);
    inst->dodajWydzial(this);
    return 1;
};

bool wydzial::dodajPracownika(pracownik* pr)
{
    int i;
    for(i = 0; i<listaPracownikow.size(); i++)
    {
        if(listaPracownikow[i]==pr)
        {
            return 0;
        }
    }
    listaPracownikow.push_back(pr);
    pr->dodajWydzial(this);
    return 1;
};

bool wydzial::zwolnijPracownika(pracownik* pr)
{
    int i;
    for(i = 0; i<listaPracownikow.size(); i++)
    {
        if(listaPracownikow[i]==pr)
        {
            listaPracownikow.erase(listaPracownikow.begin()+i);

            pr->pokaz_instytut()->zwolnijPracownika(pr);

            pr->usunWydzial();

            return 1;
        }
    }
    return 0;
};