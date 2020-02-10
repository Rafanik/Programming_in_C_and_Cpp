#include <iostream>
#include <typeinfo>
#include "pracownicy.h"
#include "jednostkiOrganizacyjne.h"
#include "wydzial.h"
#include "zaklad.h"
#include "tytulyNaukowe.h"
#include "daneEiTI.h"
#include "interfejs.h"

wydzial* wczytaj(){
pracownik* pierwszy =new pracownik( "Krzysztof","Zareba",55);
pierwszy->promujNaProfesora();
pierwszy->promujNaProfesoraZw();

pracownik* drugi =new pracownik( "Piotr", "Tatjewski", 60);
drugi->promujNaProfesora();
drugi->promujNaProfesoraZw();

pracownik* trzeci= new pracownik("Daniel","Paczesny",30);
trzeci->promujNaDoktora();
trzeci->promujNaAdiunkta();

pracownik* czwarty= new pracownik("Zbigniew","Gajo",40);
czwarty->promujNaDoktora();
czwarty->promujNaAdiunkta();

pracownik* piaty =new pracownik( "Cezary", "Zielinski", 60);
piaty->promujNaProfesora();
piaty->promujNaProfesoraZw();

pracownik* szosty =new pracownik( "Wlodzimierz", "Ogryczak", 55);
szosty->promujNaProfesora();
szosty->promujNaProfesoraZw();

pracownik* siodmy= new pracownik("Maciej","Lawrynczuk",40);
siodmy->promujNaDoktoraHab();
siodmy->promujNaProfesoraNadzw();

pracownik* osmy= new pracownik("Tomasz","Traczyk",40);
osmy->promujNaDoktoraHab();
osmy->promujNaDocenta();

pracownik* dziewiaty =new pracownik("Pawel", "Domanski", 30);
dziewiaty->promujNaDoktora();
dziewiaty->promujNaAdiunkta();

pracownik* dziesiaty = new pracownik("Eugeniusz", "Toczymowski", 53);
dziesiaty->promujNaProfesora();
dziesiaty->promujNaProfesoraZw();

pracownik* jedenasty = new pracownik("Tomasz", "Traczyk", 30);
jedenasty->promujNaDoktora();
jedenasty->promujNaDocenta();

pracownik* dwunasty = new pracownik("Jerzy", "Sobczyk", 27);
dwunasty->promujNaMagistra();
dwunasty->promujNaSatrszegoWykladowce();

pracownik* trzynasty = new pracownik("Bartosz", "Kozlowski", 33);
trzynasty->promujNaDoktora();
trzynasty->promujNaAdiunkta();

pracownik* czternasty = new pracownik("Krzysztof", "Malinowski", 62);
czternasty->promujNaProfesora();
czternasty->promujNaProfesoraZw();

pracownik* pietnasty = new pracownik("Wlodzimierz", "Kasprzyk", 54);
pietnasty->promujNaProfesora();
pietnasty->promujNaProfesoraNadzw();

pracownik* szesnasty = new pracownik("Andrzej", "Karbowski", 45);
szesnasty->promujNaDoktoraHab();
szesnasty->promujNaAdiunkta();

wydzial* eiti=new wydzial("EiTI",pierwszy);

eiti->dodajProdziekana(drugi);
eiti->dodajProdziekana(trzeci);
eiti->dodajProdziekana(czwarty);
eiti->dodajProdziekana(piaty);

instytut* automatyki= new instytut("Instytut Automatyki i Informatyki Stosowanej", szosty, eiti);
automatyki->dodajPracownika(siodmy);
automatyki->dodajPracownika(osmy);

zaklad* inzynieriiOprog= new zaklad("Zaklad Automatyki i Inzynierii Oprogramowania", drugi, automatyki);
inzynieriiOprog->dodajPracownika(siodmy);
inzynieriiOprog->dodajPracownika(dziewiaty);

zaklad* badanOperacyjnych= new zaklad("Zaklad Badan Operacyjnych i Systemowych", dziesiaty, automatyki );
badanOperacyjnych->dodajPracownika(jedenasty);
badanOperacyjnych->dodajPracownika(dwunasty);
badanOperacyjnych->dodajPracownika(trzynasty);

zaklad* sterowania = new zaklad("Zaklad Sterowania Systemow",czternasty,automatyki);
sterowania->dodajPracownika(pietnasty);
sterowania->dodajPracownika(szesnasty);

return eiti;

}
