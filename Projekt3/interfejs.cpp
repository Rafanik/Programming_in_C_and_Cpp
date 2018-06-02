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

using namespace std;

void interfejs();
//interfejs wyswietlajacy komunikaty o bledach
void interfejsBezpieczny()
{
    string d;
    string dowolny;
    wydzial* wydz = wczytaj();
//jesli zostanie rzucony blad "end" petla sie zakonczy - koniec programu
    while(d!="end")
    {
        try
        {
            interfejs(wydz);
        }
        catch (string e)
        {
            d=e;
            system ( "clear" );
            cout<<e<<endl;
            cout<<"Nacisnij dowolny przycisk";
            cin>>dowolny;
        }
    }
};

void interfejs(wydzial* wydz)
{


    bledy blad;

    string wpisane;
    //warunek dzialania programu
    while(wpisane!="q")
    {
        //wyczyszczenie ekranu i wyswietlenie opcji menu glownego
        system( "clear" );
        wydz->wyswietlDane();
        cout<<endl<<"Wyswietl liste pracownikow - 1"<<endl;
        cout<<"Wyswietl liste instytutow - 2"<<endl;
        cout<<"Wyswietl liste prodziekanow - 3"<<endl;
        cout<<"Zamknij system - \"q\""<<endl;
        cin>>wpisane;
        //opcje dzialania na wydziale
        if(wpisane == "1")
        {
            system( "clear" );
            wydz->wyswietlDane();
            wydz->wyswietlPracownikow();
            cout<<endl<<"Zwolnij pracownika - 1"<<endl;
            cout<<"Dodaj pracownika- 2"<<endl;
            cout<<"Promuj pracownika - 3"<<endl;
            cout<<"Zmien dziekana - 4"<<endl;
            cout<<"Wpisz dowolny znak, aby powrocic do ekranu glownego"<<endl;
            cout<<"Zamknij system - \"q\""<<endl;
            cin>>wpisane;
            //zwolnienie pracownika
            if (wpisane == "1")
            {
                int i;
                system( "clear");
                wydz->wyswietlDane();
                wydz->wyswietlPracownikow();
                cout<<endl<<"Podaj numer pracownika, ktorego chcesz zwolnic!!: ";
                cin>>i;
                //podanie innego typu niz int
                if(cin.fail())
                {
                    throw blad.liczba;
                }
                //podanie liczny spoza zakresu - blad
                if(i<0||i>wydz->liczbaPracownikow())
                {
                    throw blad.zakres;
                }
                if(wydz->pokaz_pracownika(i)==wydz->pokazDziekana())
                {
                    throw blad.zwolnienieDziekana;
                }
                system ( "clear" );
                cout<<"Zwolniono: ";
                wydz->pokaz_pracownika(i)->wyswietlDane();
                cout<<endl;
                wydz->zwolnijPracownika(wydz->pokaz_pracownika(i));
                wydz->wyswietlPracownikow();
                cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                cin>>wpisane;
            }
            //dodanie pracownika
            if (wpisane =="2")
            {
                string imie;
                string nazwisko;
                int wiek;
                cout<<"Podaj imie: ";
                cin>>imie;
                cout<<"Podaj nazwisko: ";
                cin>>nazwisko;
                cout<<"Podaj wiek: ";
                cin>>wiek;
                pracownik* prac = new pracownik(imie, nazwisko, wiek);
                cout<<endl<<"Wybierz tytul naukowy:"<<endl;
                cout<<"1 - inzynier, 2 - magister, 3 - doktor, 4 - doktor habilitowany, 5 - profesor :";
                cin>>wpisane;
                if (wpisane == "1")
                {
                    prac->promujNaInzyniera();
                }
                if (wpisane == "2")
                {
                    prac->promujNaMagistra();
                }
                if (wpisane == "3")
                {
                    prac->promujNaDoktora();
                }
                if (wpisane == "4")
                {
                    prac->promujNaDoktoraHab();
                }
                if (wpisane == "5")
                {
                    prac->promujNaProfesora();
                }
                cout<<endl<<"Stanowisko dydaktyczne:"<<endl;
                cout<<"1 - asystent, 2 - adiunkt, 3 - profesor zwyczajny, 4 - profesor nadzwyczajny, 5 - wykladowca, 6 - starszy wykladowca, 7 - docent :";
                cin>>wpisane;
                if (wpisane == "1")
                {
                    prac->promujNaAsystenta();
                }
                if (wpisane == "2")
                {
                    prac->promujNaAdiunkta();
                }
                if (wpisane == "3")
                {
                    prac->promujNaProfesoraZw();
                }
                if (wpisane == "4")
                {
                    prac->promujNaProfesoraNadzw();
                }
                if (wpisane == "5")
                {
                    prac->promujNaWykladowce();
                }
                if (wpisane == "6")
                {
                    prac->promujNaSatrszegoWykladowce();
                }
                if (wpisane == "7")
                {
                    prac->promujNaDocenta();
                }
                wydz->dodajPracownika(prac);
                cout<<"Dodano pracownika: ";
                prac->wyswietlDane();
                cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                cin>>wpisane;
            }
            //promocja - tytul naukowy pracownika
            if (wpisane =="3")
            {
                int i;
                system( "clear");
                wydz->wyswietlDane();
                wydz->wyswietlPracownikow();
                cout<<endl<<"Podaj numer pracownika, ktorego chcesz promowac: ";
                cin>>i;
                if(!cin.good())
                {
                    throw blad.liczba;
                }
                if(i<0||i>wydz->liczbaPracownikow())
                {
                    throw blad.zakres;
                }
                pracownik* prac = wydz->pokaz_pracownika(i);
                cout<<endl<<"Wybierz tytul naukowy:"<<endl;
                cout<<"1 - inzynier, 2 - magister, 3 - doktor, 4 - doktor habilitowany, 5 - profesor :";
                cin>>wpisane;
                if (wpisane == "1")
                {
                    prac->promujNaInzyniera();
                }
                if (wpisane == "2")
                {
                    prac->promujNaMagistra();
                }
                if (wpisane == "3")
                {
                    prac->promujNaDoktora();
                }
                if (wpisane == "4")
                {
                    prac->promujNaDoktoraHab();
                }
                if (wpisane == "5")
                {
                    prac->promujNaProfesora();
                }
                cout<<"Wypromowano pracownika: ";
                prac->wyswietlDane();
                cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                cin>>wpisane;

            }
            //zmiana dziekana wydzialu
            if (wpisane == "4")
            {
                int i;
                system( "clear");
                wydz->wyswietlDane();
                wydz->wyswietlPracownikow();
                cout<<endl<<"Podaj numer pracownika, ktorego ma zostac dziekanem: ";
                cin>>i;
                if(!cin.good())
                {
                    throw blad.liczba;
                }
                if(i<0||i>wydz->liczbaPracownikow())
                {
                    throw blad.zakres;
                }
                system ( "clear" );
                cout<<"Nowy dziekan: ";
                wydz->pokaz_pracownika(i)->wyswietlDane();
                cout<<endl;
                wydz->zmienDziekana(wydz->pokaz_pracownika(i));
                wydz->wyswietlDane();
                cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                cin>>wpisane;
            }
        }
        //opcje dzialania na poziomie instytutu
        if(wpisane == "2")
        {
            system( "clear");
            wydz->wyswietlDane();
            wydz->wyswietlInstytuty();
            cout<<"Wyswietl pracownikow danego instytutu - 1"<<endl;
            cout<<"Wyswietl zaklady danego instytutu - 2"<<endl;
            cout<<"Wpisz dowolny znak, aby powrocic do ekranu glownego"<<endl;
            cout<<"Zamknij system - \"q\""<<endl;
            cin>>wpisane;
            if(wpisane == "1")
            {
                int i;
                system( "clear");
                wydz->wyswietlDane();
                wydz->wyswietlInstytuty();
                cout<<endl<<"Podaj numer instytutu, ktorego pracownikow chcesz wyswietlic: ";
                cin>>i;
                if(!cin.good())
                {
                    throw blad.liczba;
                }
                if(i<0||i>wydz->liczbaInstytutow())
                {
                    throw blad.zakres;
                }
                system( "clear");

                instytut* inst = wydz->pokazInstytut(i);
                inst->wyswietlDane();
                inst->wyswietlPracownikow();
                cout<<endl<<"Zwolnij pracownika - 1"<<endl;
                cout<<"Dodaj pracownika- 2"<<endl;
                cout<<"Promuj pracownika - 3"<<endl;
                cout<<"Zmien stanowisko naukowe pracownika - 4"<<endl;
                cout<<"Zmien dyrektora instytutu - 5"<<endl;
                cout<<"Wpisz dowolny znak, aby powrocic do ekranu glownego"<<endl;
                cout<<"Zamknij system - \"q\""<<endl;
                cin>>wpisane;
                //zwolnienie pracownika
                if (wpisane == "1")
                {
                    int i;
                    system( "clear");
                    inst->wyswietlDane();
                    inst->wyswietlPracownikow();
                    cout<<endl<<"Podaj numer pracownika, ktorego chcesz zwolnic: ";
                    cin>>i;
                    if(!cin.good())
                    {
                        throw blad.liczba;
                    }
                    //blad - podanie wartosci spoza listy pracownikow
                    if(i<0||i>inst->liczbaPracownikow())
                    {
                        throw blad.zakres;
                    }
                    //blad - proba zwolnienia dyrektora instytutu
                    if(inst->pokaz_pracownika(i)==inst->pokazDyrektora())
                    {
                        throw blad.zwolnienieDyrektora;
                    }
                    system ( "clear" );
                    cout<<"Zwolniono: ";
                    inst->pokaz_pracownika(i)->wyswietlDane();
                    cout<<endl;
                    inst->zwolnijPracownika(inst->pokaz_pracownika(i));
                    inst->wyswietlPracownikow();
                    cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                    cin>>wpisane;
                }
                //dodanie pracownika
                if (wpisane =="2")
                {
                    string imie;
                    string nazwisko;
                    int wiek;
                    cout<<"Podaj imie: ";
                    cin>>imie;
                    cout<<"Podaj nazwisko: ";
                    cin>>nazwisko;
                    cout<<"Podaj wiek: ";
                    cin>>wiek;
                    pracownik* prac = new pracownik(imie, nazwisko, wiek);
                    cout<<endl<<"Wybierz tytul naukowy:"<<endl;
                    cout<<"1 - inzynier, 2 - magister, 3 - doktor, 4 - doktor habilitowany, 5 - profesor :";
                    cin>>wpisane;
                    if (wpisane == "1")
                    {
                        prac->promujNaInzyniera();
                    }
                    if (wpisane == "2")
                    {
                        prac->promujNaMagistra();
                    }
                    if (wpisane == "3")
                    {
                        prac->promujNaDoktora();
                    }
                    if (wpisane == "4")
                    {
                        prac->promujNaDoktoraHab();
                    }
                    if (wpisane == "5")
                    {
                        prac->promujNaProfesora();
                    }
                    cout<<endl<<"Stanowisko dydaktyczne:"<<endl;
                    cout<<"1 - asystent, 2 - adiunkt, 3 - profesor zwyczajny, 4 - profesor nadzwyczajny, 5 - wykladowca, 6 - starszy wykladowca, 7 - docent :";
                    cin>>wpisane;
                    if (wpisane == "1")
                    {
                        prac->promujNaAsystenta();
                    }
                    if (wpisane == "2")
                    {
                        prac->promujNaAdiunkta();
                    }
                    if (wpisane == "3")
                    {
                        prac->promujNaProfesoraZw();
                    }
                    if (wpisane == "4")
                    {
                        prac->promujNaProfesoraNadzw();
                    }
                    if (wpisane == "5")
                    {
                        prac->promujNaWykladowce();
                    }
                    if (wpisane == "6")
                    {
                        prac->promujNaSatrszegoWykladowce();
                    }
                    if (wpisane == "7")
                    {
                        prac->promujNaDocenta();
                    }
                    inst->dodajPracownika(prac);
                    cout<<"Dodano pracownika: ";
                    prac->wyswietlDane();
                    cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                    cin>>wpisane;
                }
                //promocja pracownika (tytul naukowy)
                if (wpisane =="3")
                {
                    int i;
                    system( "clear");
                    inst->wyswietlDane();
                    inst->wyswietlPracownikow();
                    cout<<endl<<"Podaj numer pracownika, ktorego chcesz promowac: ";
                    cin>>i;
                    if(!cin.good())
                    {
                        throw blad.liczba;
                    }
                    if(i<0||i>inst->liczbaPracownikow())
                    {
                        throw blad.zakres;
                    }
                    pracownik* prac = inst->pokaz_pracownika(i);
                    cout<<endl<<"Wybierz tytul naukowy:"<<endl;
                    cout<<"1 - inzynier, 2 - magister, 3 - doktor, 4 - doktor habilitowany, 5 - profesor :";
                    cin>>wpisane;
                    if (wpisane == "1")
                    {
                        prac->promujNaInzyniera();
                    }
                    if (wpisane == "2")
                    {
                        prac->promujNaMagistra();
                    }
                    if (wpisane == "3")
                    {
                        prac->promujNaDoktora();
                    }
                    if (wpisane == "4")
                    {
                        prac->promujNaDoktoraHab();
                    }
                    if (wpisane == "5")
                    {
                        prac->promujNaProfesora();
                    }
                    cout<<"Wypromowano pracownika: ";
                    prac->wyswietlDane();
                    cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                    cin>>wpisane;

                }
                //zmiana stanowiska dydaktycznego pracownika
                if (wpisane =="4")
                {
                    int i;
                    system( "clear");
                    inst->wyswietlDane();
                    inst->wyswietlPracownikow();
                    cout<<endl<<"Podaj numer pracownika, ktorego stanowisko chcesz zmienic: ";
                    cin>>i;
                    if(!cin.good())
                    {
                        throw blad.liczba;
                    }
                    if(i<0||i>inst->liczbaPracownikow())
                    {
                        throw blad.zakres;
                    }
                    pracownik* prac = inst->pokaz_pracownika(i);
                    cout<<endl<<"Wybierz stanowisko, ktore ma zostac przypisane:"<<endl;
                    cout<<"1 - asystent, 2 - adiunkt, 3 - profesor zwyczajny, 4 - profesor nadzwyczajny, 5 - wykladowca, 6 - starszy wykladowca, 7 - docent :";
                    cin>>wpisane;
                    if (wpisane == "1")
                    {
                        prac->promujNaAsystenta();
                    }
                    if (wpisane == "2")
                    {
                        prac->promujNaAdiunkta();
                    }
                    if (wpisane == "3")
                    {
                        prac->promujNaProfesoraZw();
                    }
                    if (wpisane == "4")
                    {
                        prac->promujNaProfesoraNadzw();
                    }
                    if (wpisane == "5")
                    {
                        prac->promujNaWykladowce();
                    }
                    if (wpisane == "6")
                    {
                        prac->promujNaSatrszegoWykladowce();
                    }
                    if (wpisane == "7")
                    {
                        prac->promujNaDocenta();
                    }
                    cout<<"Wypromowano pracownika: ";
                    prac->wyswietlDane();
                    cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                    cin>>wpisane;

                }
                //zmiana dyrektora instytutu
                if (wpisane == "5")
                {
                    int i;
                    system( "clear");
                    inst->wyswietlDane();
                    inst->wyswietlPracownikow();
                    cout<<endl<<"Podaj numer pracownika, ktorego ma zostac dyrektorem: ";
                    cin>>i;
                    if(!cin.good())
                    {
                        throw blad.liczba;
                    }
                    if(i<0||i>inst->liczbaPracownikow())
                    {
                        throw blad.zakres;
                    }
                    system ( "clear" );
                    cout<<"Nowy dyrektor: ";
                    inst->pokaz_pracownika(i)->wyswietlDane();
                    cout<<endl;
                    inst->zmienDyrektora(inst->pokaz_pracownika(i));
                    inst->wyswietlDane();
                    cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                    cin>>wpisane;
                }
            }
            //dzialania na poziomie zakladu
            if(wpisane == "2")
            {
                int i;
                system( "clear");
                wydz->wyswietlDane();
                wydz->wyswietlInstytuty();
                cout<<endl<<"Podaj numer instytutu, ktorego zaklady chcesz wyswietlic: ";
                cin>>i;
                if(!cin.good())
                {
                    throw blad.liczba;
                }
                if(i<0||i>wydz->liczbaInstytutow())
                {
                    throw blad.zakres;
                }
                system( "clear");

                instytut* inst = wydz->pokazInstytut(i);
                inst->wyswietlDane();
                inst->wyswietlZaklady();
                cout<<"Wyswietl pracownikow danego zakladu - 1"<<endl;
                cout<<"Wpisz dowolny znak, aby powrocic do ekranu glownego"<<endl;
                cout<<"Zamknij system - \"q\""<<endl;
                cin>>wpisane;
                if(wpisane =="1")
                {
                    system( "clear");
                    inst->wyswietlDane();
                    inst->wyswietlZaklady();

                    cout<<endl<<"Podaj numer zakladu, ktorego pracownikow chcesz wyswietlic: ";
                    cin>>i;
                    if(!cin.good())
                    {
                        throw blad.liczba;
                    }
                    if(i<0||i>inst->liczbaZakladow())
                    {
                        throw blad.zakres;
                    }
                    system( "clear");

                    zaklad* zak = inst->pokazZaklad(i);
                    zak->wyswietlDane();
                    zak->wyswietlPracownikow();
                    cout<<endl<<"Zwolnij pracownika - 1"<<endl;
                    cout<<"Dodaj pracownika- 2"<<endl;
                    cout<<"Promuj pracownika - 3"<<endl;
                    cout<<"Zmien stanowisko naukowe pracownika - 4"<<endl;
                    cout<<"Zmien dyrektora zakladu - 5"<<endl;
                    cout<<"Zamknij system - \"q\""<<endl;
                    cin>>wpisane;
                    //zwolnienie pracownika zakladu
                    if (wpisane == "1")
                    {
                        int i;
                        system( "clear");
                        zak->wyswietlDane();
                        zak->wyswietlPracownikow();
                        cout<<endl<<"Podaj numer pracownika, ktorego chcesz zwolnic: ";
                        cin>>i;
                        if(!cin.good())
                        {
                            throw blad.liczba;
                        }
                        if(i<0||i>zak->liczbaPracownikow())
                        {
                            throw blad.zakres;
                        }
                        if(zak->pokaz_pracownika(i)==zak->pokazDyrektora())
                        {
                            throw blad.zwolnienieDyrektora;
                        }
                        system ( "clear" );
                        cout<<"Zwolniono: ";
                        zak->pokaz_pracownika(i)->wyswietlDane();
                        cout<<endl;
                        zak->zwolnijPracownika(zak->pokaz_pracownika(i));
                        zak->wyswietlPracownikow();
                        cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                        cin>>wpisane;
                    }
                    //dodanie nowego pracownika do zakladu
                    if (wpisane =="2")
                    {
                        string imie;
                        string nazwisko;
                        int wiek;
                        cout<<"Podaj imie: ";
                        cin>>imie;
                        cout<<"Podaj nazwisko: ";
                        cin>>nazwisko;
                        cout<<"Podaj wiek: ";
                        cin>>wiek;
                        pracownik* prac = new pracownik(imie, nazwisko, wiek);
                        cout<<endl<<"Wybierz tytul naukowy:"<<endl;
                        cout<<"1 - inzynier, 2 - magister, 3 - doktor, 4 - doktor habilitowany, 5 - profesor :";
                        cin>>wpisane;
                        if (wpisane == "1")
                        {
                            prac->promujNaInzyniera();
                        }
                        if (wpisane == "2")
                        {
                            prac->promujNaMagistra();
                        }
                        if (wpisane == "3")
                        {
                            prac->promujNaDoktora();
                        }
                        if (wpisane == "4")
                        {
                            prac->promujNaDoktoraHab();
                        }
                        if (wpisane == "5")
                        {
                            prac->promujNaProfesora();
                        }
                        cout<<endl<<"Stanowisko dydaktyczne:"<<endl;
                        cout<<"1 - asystent, 2 - adiunkt, 3 - profesor zwyczajny, 4 - profesor nadzwyczajny, 5 - wykladowca, 6 - starszy wykladowca, 7 - docent :";
                        cin>>wpisane;
                        if (wpisane == "1")
                        {
                            prac->promujNaAsystenta();
                        }
                        if (wpisane == "2")
                        {
                            prac->promujNaAdiunkta();
                        }
                        if (wpisane == "3")
                        {
                            prac->promujNaProfesoraZw();
                        }
                        if (wpisane == "4")
                        {
                            prac->promujNaProfesoraNadzw();
                        }
                        if (wpisane == "5")
                        {
                            prac->promujNaWykladowce();
                        }
                        if (wpisane == "6")
                        {
                            prac->promujNaSatrszegoWykladowce();
                        }
                        if (wpisane == "7")
                        {
                            prac->promujNaDocenta();
                        }
                        zak->dodajPracownika(prac);
                        cout<<"Dodano pracownika: ";
                        prac->wyswietlDane();
                        cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                        cin>>wpisane;
                    }
                    //promocja pracownika (tytul naukowy)
                    if (wpisane =="3")
                    {
                        int i;
                        system( "clear");
                        zak->wyswietlDane();
                        zak->wyswietlPracownikow();
                        cout<<endl<<"Podaj numer pracownika, ktorego chcesz promowac: ";
                        cin>>i;
                        if(!cin.good())
                        {
                            throw blad.liczba;
                        }
                        if(i<0||i>zak->liczbaPracownikow())
                        {
                            throw blad.zakres;
                        }
                        pracownik* prac = zak->pokaz_pracownika(i);
                        cout<<endl<<"Wybierz tytul naukowy:"<<endl;
                        cout<<"1 - inzynier, 2 - magister, 3 - doktor, 4 - doktor habilitowany, 5 - profesor :";
                        cin>>wpisane;
                        if (wpisane == "1")
                        {
                            prac->promujNaInzyniera();
                        }
                        if (wpisane == "2")
                        {
                            prac->promujNaMagistra();
                        }
                        if (wpisane == "3")
                        {
                            prac->promujNaDoktora();
                        }
                        if (wpisane == "4")
                        {
                            prac->promujNaDoktoraHab();
                        }
                        if (wpisane == "5")
                        {
                            prac->promujNaProfesora();
                        }

                        cout<<"Wypromowano pracownika: ";
                        prac->wyswietlDane();
                        cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                        cin>>wpisane;

                    }
                    //zmiana stanowiska dydaktycznego
                    if (wpisane =="4")
                    {
                        int i;
                        system( "clear");
                        zak->wyswietlDane();
                        zak->wyswietlPracownikow();
                        cout<<endl<<"Podaj numer pracownika, ktorego stanowisko chcesz zmienic: ";
                        cin>>i;
                        if(!cin.good())
                        {
                            throw blad.liczba;
                        }
                        if(i<0||i>zak->liczbaPracownikow())
                        {
                            throw blad.zakres;
                        }
                        pracownik* prac = zak->pokaz_pracownika(i);
                        cout<<endl<<"Wybierz stanowisko, ktore ma zostac przypisane:"<<endl;
                        cout<<"1 - asystent, 2 - adiunkt, 3 - profesor zwyczajny, 4 - profesor nadzwyczajny, 5 - wykladowca, 6 - starszy wykladowca, 7 - docent :";
                        cin>>wpisane;
                        if (wpisane == "1")
                        {
                            prac->promujNaAsystenta();
                        }
                        if (wpisane == "2")
                        {
                            prac->promujNaAdiunkta();
                        }
                        if (wpisane == "3")
                        {
                            prac->promujNaProfesoraZw();
                        }
                        if (wpisane == "4")
                        {
                            prac->promujNaProfesoraNadzw();
                        }
                        if (wpisane == "5")
                        {
                            prac->promujNaWykladowce();
                        }
                        if (wpisane == "6")
                        {
                            prac->promujNaSatrszegoWykladowce();
                        }
                        if (wpisane == "7")
                        {
                            prac->promujNaDocenta();
                        }

                        cout<<"Wypromowano pracownika: ";
                        prac->wyswietlDane();
                        cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                        cin>>wpisane;

                    }
                    //zmiana dyrektora zakladu
                    if (wpisane == "5")
                    {
                        int i;
                        system( "clear");
                        zak->wyswietlDane();
                        zak->wyswietlPracownikow();
                        cout<<endl<<"Podaj numer pracownika, ktorego ma zostac dyrektorem: ";
                        cin>>i;
                        if(!cin.good())
                        {
                            throw blad.liczba;
                        }
                        if(i<0||i>zak->liczbaPracownikow())
                        {
                            throw blad.zakres;
                        }
                        system ( "clear" );
                        cout<<"Nowy dyrektor: ";
                        zak->pokaz_pracownika(i)->wyswietlDane();
                        cout<<endl;
                        zak->zmienDyrektora(zak->pokaz_pracownika(i));
                        zak->wyswietlDane();
                        cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                        cin>>wpisane;
                    }
                }
            }
        }
        if(wpisane == "3")
        {
            system( "clear" );
            wydz->wyswietlDane();
            wydz->wyswietlProdziekanow();
            cout<<"Wpisz dowolny znak, aby powrocic do ekranu glownego"<<endl;
            cout<<"Zamknij system - \"q\""<<endl;
            cin>>wpisane;
        }
    }
    string e = "end";
    throw e;
};
