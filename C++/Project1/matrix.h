/*
autor: Rafał Szczepanik
plik nagłówkowy klasy matrix
*/
#include <iostream>

using namespace std;

class matrix
{
public:
    int rows;//liczba wierszy
    int columns;//liczba kolumn
    int**value;//wskanik na pierwsze pole tablicy wartosci
    matrix(int a=1, int b=1);//konstruktor
    ~matrix();//destruktor;

    friend ostream& operator<<(ostream &os,matrix &m);
    friend void operator>>(istream &is,matrix &m);
    int getValue(int r,int c);//pobranie wartosci spod danej wspolrzednej
    void setValue(int r, int c, int val);//wpisanie zadanej wartosci pod wspolrzedna
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

matrix inserting();
void test();

