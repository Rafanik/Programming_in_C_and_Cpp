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
    dziekan->wyswietlDane();
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
            //cout<<"ten instytut juz istnieje"<<endl;
            return 0;
        }
    }
    listaInstytutow.push_back(inst);
    inst->dodajWydzial(this);
    //cout<<"dodano instytut"<<endl;
    return 1;
};

bool wydzial::dodajPracownika(pracownik* pr)
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
    pr->dodajWydzial(this);
    //cout<<"dodano pracownika"<<endl;
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
            pr->inst()->zwolnijPracownika(pr);
            pr->usunWydzial();
            //cout<<"zwolniono pracownika"<<endl<<endl;
            return 1;
        }
    }
    return 0;
};
