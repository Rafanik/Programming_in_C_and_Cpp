#ifndef INTERFEJS_H_INCLUDED
#define INTERFEJS_H_INCLUDED

class bledy
{
public:
    const string zakres = "Wybrano numer spoza zakresu!";
    const string liczba= "Nie podano liczby!";
    const string zwolnienieDziekana= "Nie mozna zwolnic dziekana!";
    const string koniecProgramu= "Zakonczono dzialanie programu";
};

void interfejs();

void interfejsBezpieczny();


#endif // INTERFEJS_H_INCLUDED
