#include <iostream>
#include <typeinfo>
#include "pracownicy.h"
#include "jednostkiOrganizacyjne.h"
#include "wydzial.h"
#include "zaklad.h"
#include "tytulyNaukowe.h"
#include "daneEiTI.h"
#include "interfejs.h"
#include <iomanip>

//funkcja testujca dodanie pracownika do wydzialu
bool testDodajPrWydzialu(wydzial* wydz, pracownik* pr)
{
    int i = wydz->liczbaPracownikow();
    wydz->dodajPracownika(pr);
    if (wydz->liczbaPracownikow()!=i+1)
    {
        return 0;
    }
    if (wydz->pokaz_pracownika(i+1)->podajImie()!=pr->podajImie())
    {
        return 0;
    }
    if (wydz->pokaz_pracownika(i+1)->podajNazwisko()!=pr->podajNazwisko())
    {
        return 0;
    }
    if (wydz->pokaz_pracownika(i+1)->podajWiek()!=pr->podajWiek())
    {
        return 0;
    }
    if (wydz->pokaz_pracownika(i+1)->podajStanowisko()!=pr->podajStanowisko())
    {
        return 0;
    }
    return 1;
};

//funkcja testujca dodanie pracownika do instytutu
bool testDodajPrInstytutu(instytut* inst, pracownik* pr)
{
    int i = inst->liczbaPracownikow();
    inst->dodajPracownika(pr);
    if (inst->liczbaPracownikow()!=i+1)
    {
        return 0;
    }
    if (inst->pokaz_pracownika(i+1)->podajImie()!=pr->podajImie())
    {
        return 0;
    }
    if (inst->pokaz_pracownika(i+1)->podajNazwisko()!=pr->podajNazwisko())
    {
        return 0;
    }
    if (inst->pokaz_pracownika(i+1)->podajWiek()!=pr->podajWiek())
    {
        return 0;
    }
    if (inst->pokaz_pracownika(i+1)->podajStanowisko()!=pr->podajStanowisko())
    {
        return 0;
    }
    return 1;
};

//funkcja testujca dodanie pracownika do zakladu
bool testDodajPrZakladu(zaklad* inst, pracownik* pr)
{
    int i = inst->liczbaPracownikow();
    inst->dodajPracownika(pr);
    if (inst->liczbaPracownikow()!=i+1)
    {
        return 0;
    }
    if (inst->pokaz_pracownika(i+1)->podajImie()!=pr->podajImie())
    {
        return 0;
    }
    if (inst->pokaz_pracownika(i+1)->podajNazwisko()!=pr->podajNazwisko())
    {
        return 0;
    }
    if (inst->pokaz_pracownika(i+1)->podajWiek()!=pr->podajWiek())
    {
        return 0;
    }
    if (inst->pokaz_pracownika(i+1)->podajStanowisko()!=pr->podajStanowisko())
    {
        return 0;
    }
    return 1;
};

//funkcja testujca zwalnianie pracownika z wydzialu
bool testZwolnijPrWydzialu(wydzial* wydz, pracownik* pr)
{
    int i = wydz->liczbaPracownikow();
    wydz->zwolnijPracownika(pr);

    if (wydz->liczbaPracownikow()!=i-1 )
    {
        return 0;
    }
    if (wydz->dodajPracownika(pr)==0 )
    {
        return 0;
    }
    return 1;
};

//funkcja testujca zwalnianie pracownika z instytutu
bool testZwolnijPrInstytutu(instytut* wydz, pracownik* pr)
{
    int i = wydz->liczbaPracownikow();
    wydz->zwolnijPracownika(pr);
    if (wydz->liczbaPracownikow()!=i-1 )
    {
        return 0;
    }
    if (wydz->dodajPracownika(pr)==0 )
    {
        return 0;
    }
    return 1;
};

//funkcja testujca zwalnianie pracownika z zakladu
bool testZwolnijPrZakladu(zaklad* wydz, pracownik* pr)
{
    int i = wydz->liczbaPracownikow();
    wydz->zwolnijPracownika(pr);
    if (wydz->liczbaPracownikow()!=i-1 )
    {
        return 0;
    }
    if (wydz->dodajPracownika(pr)==0 )
    {
        return 0;
    }
    return 1;
};

//funkcja testujca promowanie pracownika
bool testPromocji(pracownik* pr)
{
    pr->promujNaAdiunkta();
    if(pr->podajStanowisko()!="adiunkt")
    {
        return 0;
    }
    pr->promujNaMagistra();
    if(pr->podajTytul()!="mgr inz. ")
    {
        return 0;
    }
    return 1;
};

//funkcja testujca zmiane dziekana wydzialu
bool testZmianyDziekana(wydzial* wydz, pracownik* pr)
{
wydz->zmienDziekana(pr);
if(wydz->pokazDziekana()!=pr)
{
return 0;
}
return 1;
}

//scenariusz testujacy
bool test()
{
    wydzial*  wydz = wczytaj();
    pracownik* pierwszy =new pracownik( "Jan","Kowalski",55);
    pierwszy->promujNaProfesora();
    pierwszy->promujNaProfesoraZw();
    //Test dodania pracownikow do wydzialu, instytutu i zakladu
    cout<<"Test dodaj pracownika do wydzialu: "<<testDodajPrWydzialu(wydz, pierwszy)<<endl;
    cout<<"Test dodaj pracownika do instytutu: "<<testDodajPrInstytutu(wydz->pokazInstytut(1), pierwszy)<<endl;
    cout<<"Test dodaj pracownika do zakladu: "<<testDodajPrZakladu(wydz->pokazInstytut(1)->pokazZaklad(2), pierwszy)<<endl;
    //Test zwolnienia pracownika z wydzialu, instytutu i zakladu
    cout<<"Test zwolnij pracownika do zakladu: "<<testZwolnijPrZakladu(wydz->pokazInstytut(1)->pokazZaklad(2), pierwszy)<<endl;
    cout<<"Test zwolnij pracownika do instytutu: "<<testZwolnijPrInstytutu(wydz->pokazInstytut(1), pierwszy)<<endl;
    cout<<"Test zwolnij pracownika z wydzialu: "<<testZwolnijPrWydzialu(wydz, pierwszy)<<endl;
    //Test sprawdzajacy czy dodanie pracownika do zakladu dodaje go rowniez do wydzialu i instytutu
    cout<<"Test dodaj pracownika do zakladu (pracownik nie pracuje na wydziale): "<<testDodajPrZakladu(wydz->pokazInstytut(1)->pokazZaklad(2), pierwszy)<<endl;
    cout<<"Test zwolnij pracownika z wydzialu (pracownik dodany przez zaklad): "<<testZwolnijPrWydzialu(wydz, pierwszy)<<endl;
    //Test promocji pracownia
    cout<<"Test promocji pracownikow: "<<testPromocji(pierwszy)<<endl;
    //Test zmiany dziekana
    cout<<"Test zmiany dziekana: "<<testZmianyDziekana(wydz, pierwszy)<<endl;

    return 1;


};
