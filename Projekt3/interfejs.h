#ifndef INTERFEJS_H_INCLUDED
#define INTERFEJS_H_INCLUDED
#include "daneEiTI.h"

class bledy
{
public:
    string zakres = "Wybrano numer spoza zakresu!";
    string liczba= "Nie podano liczby!";
};

void interfejs()
{


    bledy blad;
    wydzial* wydz = wczytaj();
    string wpisane;
    while(wpisane!="q")
    {
        system( "clear" );
        wydz->wyswietlDane();
        cout<<endl<<"Wyswietl liste pracownikow - 1"<<endl;
        cout<<"Wyswietl liste instytutow - 2"<<endl;
        cout<<"Wyswietl liste prodziekanow - 3"<<endl;
        cout<<"Zamknij system - \"q\""<<endl;
        cin>>wpisane;
        if (wpisane=="1")
        {
            system( "clear" );
            wydz->wyswietlDane();
            wydz->wyswietlPracownikow();
            cout<<endl<<"Zwolnij pracownika - 1"<<endl;
            cout<<"Dodaj pracownika- 2"<<endl;
            cout<<"Promuj pracownika - 3"<<endl;
            cout<<"Zamknij system - \"q\""<<endl;
            cin>>wpisane;
            if (wpisane == "1")
            {
                int i;
                system( "clear");
                wydz->wyswietlDane();
                wydz->wyswietlPracownikow();
                cout<<endl<<"Podaj numer pracownika, ktorego chcesz zwolnic: ";
                cin>>i;
                if(i<0||i>wydz->liczbaPracownikow())
                {
                    throw blad.zakres;
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
                wydz->dodajPracownika(prac);
                cout<<"Dodano pracownika: ";
                prac->wyswietlDane();
                cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                cin>>wpisane;
            }
            if (wpisane =="3")
            {
                int i;
                system( "clear");
                wydz->wyswietlDane();
                wydz->wyswietlPracownikow();
                cout<<endl<<"Podaj numer pracownika, ktorego chcesz promowac: ";
                cin>>i;
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
        }
        if(wpisane == "2")
        {
            system( "clear");
            wydz->wyswietlDane();
            wydz->wyswietlInstytuty();
            cout<<"Wyswietl pracownikow danego instytutu - 1"<<endl;
            cout<<"Wyswietl zaklady danego instytutu - 2"<<endl;
            cout<<"Zamknij system - \"q\""<<endl;
            cin>>wpisane;
            if(wpisane == "1")
            {
                int i;
                system( "clear");
                wydz->wyswietlInstytuty();
                cout<<endl<<"Podaj numer instytutu, ktorego pracownikow chcesz wyswietlic: ";
                cin>>i;
                system( "clear");

                instytut* inst = wydz->pokazInstytut(i);
                inst->wyswietlDane();
                inst->wyswietlPracownikow();
                cout<<endl<<"Zwolnij pracownika - 1"<<endl;
                cout<<"Dodaj pracownika- 2"<<endl;
                cout<<"Promuj pracownika - 3"<<endl;
                cout<<"Zamknij system - \"q\""<<endl;
                cin>>wpisane;

                if (wpisane == "1")
                {
                    int i;
                    system( "clear");
                    inst->wyswietlDane();
                    inst->wyswietlPracownikow();
                    cout<<endl<<"Podaj numer pracownika, ktorego chcesz zwolnic: ";
                    cin>>i;
                    if(i<0||i>inst->liczbaPracownikow())
                    {
                        throw blad.zakres;
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
                    inst->dodajPracownika(prac);
                    cout<<"Dodano pracownika: ";
                    prac->wyswietlDane();
                    cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                    cin>>wpisane;
                }
                if (wpisane =="3")
                {
                    int i;
                    system( "clear");
                    inst->wyswietlDane();
                    inst->wyswietlPracownikow();
                    cout<<endl<<"Podaj numer pracownika, ktorego chcesz promowac: ";
                    cin>>i;
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
            }
            if(wpisane == "2")
            {
             int i;
                system( "clear");
                wydz->wyswietlDane();
                wydz->wyswietlInstytuty();
                cout<<endl<<"Podaj numer instytutu, ktorego zaklady chcesz wyswietlic: ";
                cin>>i;
                system( "clear");

                instytut* inst = wydz->pokazInstytut(i);
                inst->wyswietlDane();
                inst->wyswietlZaklady();
                cout<<"Wyswietl pracownikow danego zakladu - 1"<<endl;
                cout<<"Zamknij system - \"q\""<<endl;
                cin>>wpisane;
                if(wpisane =="1")
                {
                system( "clear");
                inst->wyswietlDane();
                inst->wyswietlZaklady();

                cout<<endl<<"Podaj numer zakladu, ktorego pracownikow chcesz wyswietlic: ";
                cin>>i;
                system( "clear");

                zaklad* zak = inst->pokazZaklad(i);
                zak->wyswietlDane();
                zak->wyswietlPracownikow();
                cout<<endl<<"Zwolnij pracownika - 1"<<endl;
                cout<<"Dodaj pracownika- 2"<<endl;
                cout<<"Promuj pracownika - 3"<<endl;
                cout<<"Zamknij system - \"q\""<<endl;
                cin>>wpisane;

            if (wpisane == "1")
            {
                int i;
                system( "clear");
                zak->wyswietlDane();
                zak->wyswietlPracownikow();
                cout<<endl<<"Podaj numer pracownika, ktorego chcesz zwolnic: ";
                cin>>i;
                if(i<0||i>zak->liczbaPracownikow())
                {
                    throw blad.zakres;
                }

                system ( "clear" );
                cout<<"Zwolniono: ";
                zak->pokaz_pracownika(i)->wyswietlDane();
                cout<<endl;
                zak->zwolnijPracownika(wydz->pokaz_pracownika(i));
                zak->wyswietlPracownikow();
                cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                cin>>wpisane;
            }
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
                zak->dodajPracownika(prac);
                cout<<"Dodano pracownika: ";
                prac->wyswietlDane();
                cout<<endl<<"Nacisnij dowolny klawisz, zeby przejsc dalej."<<endl;
                cin>>wpisane;
            }
            if (wpisane =="3")
            {
                int i;
                system( "clear");
                zak->wyswietlDane();
                zak->wyswietlPracownikow();
                cout<<endl<<"Podaj numer pracownika, ktorego chcesz promowac: ";
                cin>>i;
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
                }
            }
        }
    }
}


#endif // INTERFEJS_H_INCLUDED
