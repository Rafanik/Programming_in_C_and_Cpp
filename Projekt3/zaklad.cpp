#include "pracownicy.h"
#include "wydzial.h"
#include "instytut.h"
#include "zaklad.h"

#include <vector>
#include <string.h>
#include <ios>

using std::cout;
using std::endl;

zaklad::zaklad(const char* nazw, pracownik* dyr, instytut* i) : jednostkaOrganizacyjna(nazw)
{
    zaklad_instytut=i;
    zaklad_instytut->dodajZaklad(this);
    dyrZakladu=dyr;
    dodajPracownika(dyrZakladu);
};

void zaklad::wyswietlDane()
{
    cout<<"instytut:"<<nazwa<<endl<<"Dyrektor: ";
    dyrZakladu->wyswietlDane();
    cout<<"pracownicy:"<<listaPracownikow.size()<<endl;
};



bool zaklad::dodajPracownika(pracownik* pr)
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
    zaklad_instytut->dodajPracownika(pr);
    pr->dodajZaklad(this);
    //cout<<"dodano pracownika"<<endl;
    return 1;
};

bool zaklad::zwolnijPracownika(pracownik* pr)
{
    int i;
    for(i = 0; i<listaPracownikow.size(); i++)
    {
        if(listaPracownikow[i]==pr)
        {
            listaPracownikow.erase(listaPracownikow.begin()+i);
            pr->usunZaklad();
            cout<<"zwolniono pracownika"<<endl<<endl;
            return 1;
        }
    }
    cout<<"nie zwolniono pracownika"<<endl;
    return 0;
};
