#include "pracownicy.h"
#include "wydzial.h"
#include "instytut.h"

#include <vector>
#include <string.h>
#include <ios>

using std::cout;
using std::endl;

wydzial::wydzial(const string nazw, pracownik* dziek) : jednostkaOrganizacyjna(nazw)
{
    dziekan=dziek;
    dodajPracownika(dziekan);
};

void wydzial::wyswietlDane()
{
    cout<<"wydzial:"<<nazwa<<endl<<"Dziekan: ";
    dziekan->pracownik::wyswietlDane();
    cout<<"prodziekani:"<<listaProdziekanow.size()<<endl;
    cout<<"pracownicy:"<<listaPracownikow.size()<<endl;
    cout<<"instytuty:"<<listaInstytutow.size()<<endl<<endl;
};

void wydzial::wyswietlInstytuty()
{
    cout<<"Instytuty: "<<endl<<endl;
    int i;
    for (i=0; i<listaInstytutow.size(); i++)
    {
        cout<<i+1<<". "<<listaInstytutow[i]->pokazNazwe()<<endl;
    }
    cout<<endl;
};

void wydzial::wyswietlProdziekanow()
{
    cout<<"Prodziekani: "<<endl<<endl;
    int i;
    for (i=0; i<listaProdziekanow.size(); i++)
    {
        cout<<i+1<<". ";
        listaProdziekanow[i]->wyswietlDane();
    }
    cout<<endl;
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

bool wydzial::dodajProdziekana(pracownik* pr)
{
dodajPracownika(pr);
int i;
    for(i = 0; i<listaProdziekanow.size(); i++)
    {
        if(listaProdziekanow[i]==pr)
        {
            return 0;
        }
    }
    listaProdziekanow.push_back(pr);
}

bool wydzial::zwolnijPracownika(pracownik* pr)
{
    int i;
    for(i = 0; i<listaPracownikow.size(); i++)
    {
        if(listaPracownikow[i]==pr)
        {
            listaPracownikow.erase(listaPracownikow.begin()+i);

            if(pr->pokaz_instytut()!=nullptr)
            {
            pr->pokaz_instytut()->zwolnijPracownika(pr);
            }

            pr->usunWydzial();

            return 1;
        }
    }
    return 0;
};
