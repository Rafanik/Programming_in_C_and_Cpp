/*
autor: Rafał Szczepanik
plik nagłówkowy klasy matrix
*/
#include <iostream>

using namespace std;

class matrix{
public:
int rows;//liczba wierszy
int columns;//liczba kolumn
int**value;//wskanik na pierwsze pole tablicy wartosci
matrix(int a=1, int b=1);//konstruktor
~matrix();//destruktor;

friend ostream& operator<<(ostream &os,matrix &m);
friend istream& operator>>(istream &is,matrix &m);
matrix operator+(const matrix &b)const;
void operator+=(matrix &b);
matrix operator-(const matrix &b)const;
void operator-=(matrix &b);
matrix operator*(const matrix &b)const;
void operator*=(matrix &b);
bool operator==(matrix &b);
bool operator!=(matrix &b);
matrix& operator=(const matrix &b);
};

// Funkcje testujce:

matrix inserting();//funkcja pozwalająca uzytkownikowi stworzyc macierz o zadanych wymiarach i wypelnic jej wartosci
void test();// funkcja pozwalajaca na przetestowanie dzialania powyzej zdefiniowanych przeciazen operatorow

