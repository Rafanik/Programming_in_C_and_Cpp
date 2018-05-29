#include <iostream>
#include "pracownicy.h"
#include "jednostkiOrganizacyjne.h"
#include "wydzial.h"
#include "zaklad.h"
#include "funkcjePracownikow.h"

using namespace std;

int main()
{
inzynierAsystent pierwszy("Pawel","Ziomek",29);

inzynierAsystent drugi("Arkadiusz", "Rybski", 30);

inzynierWykladowca trzeci("Maroslaw","Wlodarski",55);

inzynierAsystent* rr = &drugi;

inzynierWykladowca czwarty(rr);


pracownik* pr = &trzeci;
pracownik* sr = &pierwszy;
pracownik* cr = &czwarty;

pierwszy.wyswietlDane();
drugi.wyswietlDane();
trzeci.wyswietlDane();
czwarty.wyswietlDane();

degraduj(rr);

pierwszy.wyswietlDane();
drugi.wyswietlDane();
trzeci.wyswietlDane();
czwarty.wyswietlDane();

wydzial eiti("EiTI",rr);
wydzial* e = &eiti;

instytut makro("Instytut Makroelektorniki", pr, e);

instytut* mk = &makro;

zaklad cewka("Zaklad Cewek", cr, mk);

cewka.dodajPracownika(rr);





/*eiti.dodajPracownika(sr);
eiti.dodajInstytut(mk);
eiti.wyswietlDane();
cout<<endl;
makro.wyswietlDane();
cout<<endl;
makro.wyswietlPracownikow();
cout<<endl;
cewka.wyswietlDane();
cewka.wyswietlPracownikow();

cout<<endl;
eiti.zwolnijPracownika(cr);
eiti.wyswietlDane();
cout<<endl;
makro.wyswietlDane();
cout<<endl;
makro.wyswietlPracownikow();
cout<<endl;
cewka.wyswietlDane();
cewka.wyswietlPracownikow();*/

}
