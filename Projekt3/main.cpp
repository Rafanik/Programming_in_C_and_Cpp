#include <iostream>
#include <typeinfo>
#include "pracownicy.h"
#include "jednostkiOrganizacyjne.h"
#include "wydzial.h"
#include "zaklad.h"
#include "tytulyNaukowe.h"

using namespace std;

int main()
{

pracownik pierwszy( "Pawel","Ziomek",29);

pracownik drugi( "Arkadiusz", "Rybski", 30);

pracownik trzeci("Maroslaw","Wlodarski",55);

pracownik* pr = &pierwszy;
pracownik* dr = &drugi;
pracownik* tr = &trzeci;


pierwszy.wyswietlDane();
drugi.wyswietlDane();
trzeci.wyswietlDane();

pierwszy.promujNaProfesora();
drugi.promujNaInzyniera();
trzeci.promujNaDoktoraHab();

pierwszy.wyswietlDane();
drugi.wyswietlDane();
trzeci.wyswietlDane();

wydzial eiti("EiTI",pr);
wydzial* e = &eiti;

instytut makro("Instytut Makroelektorniki", dr, e);

instytut* mk = &makro;

zaklad cewka("Zaklad Cewek", tr, mk);

cewka.dodajPracownika(dr);





/*eiti.dodajPracownika(pr);
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
eiti.zwolnijPracownika(dr);
eiti.wyswietlDane();
cout<<endl;
makro.wyswietlDane();
cout<<endl;
makro.wyswietlPracownikow();
cout<<endl;
cewka.wyswietlDane();
cewka.wyswietlPracownikow();*/

}
