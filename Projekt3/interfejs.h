#ifndef INTERFEJS_H_INCLUDED
#define INTERFEJS_H_INCLUDED
//klasa zawierajaca stringi z bledami pojawiajacymni sie przy uzyciu interfejsu
class bledy
{
public:
    const string zakres = "Wybrano numer spoza zakresu!";
    const string liczba= "Nie podano liczby!";
    const string zwolnienieDziekana= "Nie mozna zwolnic dziekana!";
    const string zwolnienieDyrektora="Nie mozna zwolnic dyrektora!";
    const string koniecProgramu= "Zakonczono dzialanie programu";
};
//funkcja umozliwiajaca dzialanie na wskazanym wydziale
void interfejs(wydzial*);
//funkcja obslugujaca bledy f. interfejs()
void interfejsBezpieczny();


#endif // INTERFEJS_H_INCLUDED
