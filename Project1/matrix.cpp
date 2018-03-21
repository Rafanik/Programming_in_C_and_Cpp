#include <iostream>
#include "matrix.h"
#include <limits.h>

using namespace std;
/* klasa matrix reprezentuje macierz; operacje +,-,*,+=,-=,*= w przypadku niezgodnosci wymiarow zwracaja macierz zerowa oraz komunikat o bledzie
*/

matrix::matrix(int a, int b)
{
    rows=a;
    columns=b;
    value = new int* [rows];
    int i;
    for(i = 0; i <= rows-1; i++)
        value[i] = new int [columns];
    for(int i=0; i<=rows-1; i++)
        {
            for(int j=0; j<=columns-1; j++)
            {
                value[i][j]=0;
            }
        }
}

matrix::~matrix(){
for(int i =0; i<=rows-1; i++){
delete[] value[i];
}
delete[] value;
}

ostream& operator<<(ostream &os,matrix &m)
{
    for(int i=0; i<=m.rows-1; i++)
    {
        for(int j=0; j<=m.columns-1; j++)
        {
            os<<m.value[i][j]<<' ';
        }
        os<<endl;
    }
    return os;
}

istream& operator>>(istream& is,matrix &m)//wprowadzanie wartosci elementow macierzy odbywa sie po wierszu; jezeli zostanie wprowadzone za duzo liczb, ich ilosc zostanie obcieta do wymiaru macierzy
{
char check;
    cout<<"Insert "<<m.columns<<" value(s) in each row."<<endl;
    for(int i=0; i<=m.rows-1; i++)
    {
        cout<<i+1<<": ";
        for(int j=0; j<=m.columns-1; j++)
        {

            is>>m.value[i][j];
            if(!is.good()){//sprawdzenie poprawnosci danych
            is.clear();//wyczyszczenie flag bledow
            is.ignore(INT_MAX, '\n');//usuniecie z bufora pozostalych znakow az do konca linii
            cout<<"Bad data."<<endl;//komunikat o blednych danych
            i--;
            break;
            }
            if(j==m.columns-1){
            is.ignore(INT_MAX,'\n');//ignorowanie dlaszych liczb niz dlugosc wiersza
            }
        }
    }
}

matrix matrix::operator+(const matrix &b) const
{
   matrix result(rows,columns);//warunek aby macierze mozna bylo dodac

    if(rows==b.rows&&columns==b.columns)
    {

        for(int i=0; i<=rows-1; i++)
        {
            for(int j=0; j<=columns-1; j++)
            {
                result.value[i][j]=(value[i][j]+b.value[i][j]);
            }
        }
    }
    else
    {
        cout<<"Matrix dimensions are not correct."<<endl;//komunikat o bledzie
    }
    return result;
}

matrix matrix::operator-(const matrix &b)const
{
    matrix result(rows,columns);
    if(rows==b.rows&&columns==b.columns)//warunek aby macierze mozna bylo odjac
    {
        for(int i=0; i<=rows-1; i++)
        {
            for(int j=0; j<=columns-1; j++)
            {
                result.value[i][j]=(value[i][j]-b.value[i][j]);
            }
        }
    }
    else
    {
        cout<<"Matrix dimensions are not correct."<<endl;//komunikat o bledzie
    }
    return result;
}

matrix matrix::operator*(const matrix &b)const
{

    matrix result(rows,b.columns);

    if(columns==b.rows)//warunek aby dalo sie pomnozyc macierze
    {

        for(int i=0; i<=result.rows-1; i++)
        {
            for(int j=0; j<=result.columns-1; j++)
            {
                for(int k=0;k<=columns-1;k++)
                result.value[i][j]=result.value[i][j]+(value[i][k]*b.value[k][j]);//wypelnianie kolejnych elementow macierzy
            }
        }
    return result;
    }
    else
    {
        cout<<"Matrix dimensions are not correct."<<endl;//komunikat bledu
        return result;
    }

}


matrix& matrix::operator=(const matrix &b)
{

    for(int i = 0; i<=rows-1; i++)//zwolnienie pamieci pierwotnej macierzy
    {
        delete[] value[i];
    }
    delete[] value;
    rows=b.rows;//przypisanie wartosci liczby wierszy i kolumn
    columns=b.columns;
    value = new int* [rows];//zaalokowanie nowej macierzy
    for(int i = 0; i <= rows-1; i++)
    {
        value[i] = new int [columns];
    }
    for(int i=0; i<=rows-1; i++)//wpisanie wartosci do nowej macierzy
        {
            for(int j=0; j<=columns-1; j++)
            {
                value[i][j]=b.value[i][j];
            }
        }
return *this;
}


bool matrix::operator==(matrix &b)
{
    if(rows==b.rows&&columns==b.columns)//sprawdzenie warunku zgodnosci wymiarow
    {
        for(int i=0; i<=rows-1; i++)
        {
            for(int j=0; j<=columns-1; j++)
            {
                if(value[i][j]!=b.value[i][j])//sprawdzenie warunku zgodnosci wartosci elementow
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}


bool matrix::operator!=(matrix &b)
{
    return !matrix::operator==(b);//dzialanie antagonistyczne do operatora ==
}

void matrix::operator+=(matrix &b)
{
    if(rows==b.rows&&columns==b.columns)//sprawdzenie czy macierze mozna dodac
    {
        for(int i=0; i<=rows-1; i++)
        {
            for(int j=0; j<=columns-1; j++)
            {
                value[i][j]=(value[i][j]+b.value[i][j]);//przypisanie wartosci kolejnym elementom
            }
        }
    }
    else
    {
        cout<<"Matrix dimensions are not correct."<<endl;//komunikat o bledzie
    }
}



void matrix::operator-=(matrix &b)
{
    if(rows==b.rows&&columns==b.columns)//sprawdzenie czy macierze mozna odjac
    {
        for(int i=0; i<=rows-1; i++)
        {
            for(int j=0; j<=columns-1; j++)
            {
                value[i][j]=(value[i][j]-b.value[i][j]);//przypisanie wartosci kolejnym elementom
            }
        }
    }
    else
    {
        cout<<"Matrix dimensions are not correct."<<endl;//komunikat o bledzie
    }
}



void matrix::operator*=(matrix &b)
{

    matrix result(rows,b.columns);

    if(columns==b.rows)//warunek aby dalo sie pomnozyc macierze
    {

        for(int i=0; i<=result.rows-1; i++)
        {
            for(int j=0; j<=result.columns-1; j++)
            {
                for(int k=0;k<=columns-1;k++)
                result.value[i][j]=result.value[i][j]+(value[i][k]*b.value[k][j]);//wypelnianie kolejnych elementow macierzy
            }
        }
    }
    else
    {
        cout<<"Matrix dimensions are not correct."<<endl;//komunikat o bledzie
    }

    *this=result;


}

