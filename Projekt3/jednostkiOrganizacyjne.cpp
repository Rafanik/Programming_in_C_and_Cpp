#include "pracownicy.h"
#include "jednostkiOrganizacyjne.h"
#include "wydzial.h"
#include "instytut.h"

#include <vector>
#include <string.h>
#include <ios>

using std::cout;
using std::endl;

jednostkaOrganizacyjna::jednostkaOrganizacyjna(const char* nazw){
strncpy(nazwa,nazw,ROZMIAR);
};

bool jednostkaOrganizacyjna::dodajPracownika(pracownik* pr)
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
    //cout<<"dodano pracownika"<<endl;
    return 1;
};

void jednostkaOrganizacyjna::wyswietlPracownikow()
{
    int i;
    for (i=0; i<listaPracownikow.size(); i++)
    {
        listaPracownikow[i]->wyswietlDane();
    }
};

bool jednostkaOrganizacyjna::zwolnijPracownika(pracownik* pr)
{
    int i;
    for(i = 0; i<listaPracownikow.size(); i++)
    {
        if(listaPracownikow[i]==pr)
        {
            listaPracownikow.erase(listaPracownikow.begin()+i);
            //cout<<"zwolniono pracownika"<<endl<<endl;
            return 1;
        }
    }
    return 0;
};




