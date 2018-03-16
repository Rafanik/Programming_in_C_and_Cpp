#include <iostream>

using namespace std;

class matrix{
public:
int rows;//liczba wierszy
int columns;//liczba kolumn
int**value;//wskanik na pierwsze pole tablicy wartosci
matrix(int a, int b);//konstruktor

friend ostream& operator<<(ostream &os,matrix &m);
friend istream& operator>>(istream &is,matrix &m);
matrix operator+(matrix &b);
void operator+=(matrix &b);
matrix operator-(matrix &b);
void operator-=(matrix &b);
bool operator==(matrix &b);
bool operator!=(matrix &b);
};

