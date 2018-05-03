#ifndef TENSOR_H_INCLUDED
#define TENSOR_H_INCLUDED
#include <string>
#include <iomanip>

using namespace std;

template <class T> class Tensor;
template <class T> std::istream& operator>>( std::istream &is, Tensor<T> &t);

template <class T> class Tensor;
template <class T> std::ostream& operator<<( std::ostream &os, const Tensor<T> &t);

template <class T>
class Tensor
{
    int dimx, dimy, dimz; //wymiary x, y ,z tensora
    T ***tab;  //trojwymiarowa tablica przechowujaca wartosci tensora
public:

    Tensor( int, int, int);  //konstruktor podstawowy
    Tensor( T const &);  //konstruktor kopiujacy
    ~Tensor();  //destruktor
    //przeciazenia operatorow
    Tensor& operator=(const Tensor &);
    bool operator==(Tensor const &);
    bool operator!=(Tensor const &);
    Tensor operator+(Tensor const &);
    Tensor& operator+=(Tensor const &);
    Tensor operator-(Tensor const &) const;
    Tensor& operator-=(Tensor const &);
    Tensor operator*(Tensor const &);
    Tensor& operator*=(Tensor const &);
    //metody klasy
    inline T read(int a, int b, int c)
    {
        if (a>dimx||b>dimy||c>dimz) throw 1;
        else return tab[a][b][c];
    }

    void change(T, int, int, int);

    friend ostream& operator<< <> (ostream &os, const Tensor<T> &t);

    friend istream& operator>> <> (istream &is, Tensor<T> &t);

};

template <class T>
std::ostream& operator<<(std::ostream &os, const Tensor<T> &t)
{

    for (int i=0; i<t.dimx; i++)
    {
        for (int j=0; j<t.dimy; j++)
        {
            for (int k=0; k<t.dimz; k++)
            {
                os<<setfill(' ');
                os<<setw(5);//ustawienie szerokosci pola
                os<<t.tab[i][j][k];
            }
            os<<"\n";
        }
        os<<setfill('*');//oddzielenie pol symbolami '*'
        os<<setw(5*t.dimz)<<'*'<<endl;
    }
    return os;
}

template <class T>
std:: istream& operator>> (istream &is, Tensor<T> &t)
{
    T liczba;
    for(int i=0; i<t.dimx; i++)
    {
        for (int j=0; j<t.dimy; j++)
        {
            cout<<"Podaj "<<t.dimz<<" liczb/y dla "<<i+1<<". wiersza i "<<j+1<<". kolumny:"<<endl;
            for (int k=0; k<t.dimz; k++)
            {
                is>>liczba;
                if (is.good())   //jesli wczytana dana jest lub moze byc przekonwertowana na dany type
                {
                    t.tab[i][j][k]=liczba;
                }
                else   //w przeciwnym przypadku blad
                {
                    k--;
                    is.clear();
                    is.sync();
                }
            }
        }
    }
    return is;
}


template <class T>
Tensor<T>::Tensor( int x=0, int y=0, int z=0)  //konstruktor podstawowy
{
    tab = new T **[x];
    for (int i=0; i<x; i++)
    {
        tab[i]= new T *[y];
        for(int j=0; j<y; j++)
        {
            tab[i][j]=new T [z]();
        }
    }
    dimx=x;
    dimy=y;
    dimz=z;
}

template <class T>
Tensor<T>::Tensor( T const &t)  //konstruktor kopiujacy
{
    tab = new T **[t.dimx];
    for(int i = 0; i<t.dimx; i++)
    {
        tab[i] = new T *[t.dimy];
        for(int j=0; j< t.dimy; j++)
        {
            tab[i][j]=new T [t.dimz];
            for (int k=0; k<t.dimz; k++)
            {
                this->tab[i][j][k]=t.tab[i][j][k];
            }
        }

    }
    dimx=t.dimx;
    dimy=t.dimy;
    dimz=t.dimz;
}

template <class T>
Tensor<T>::~Tensor()  //destruktor
{
    for (int i=0; i<dimy; i++)
    {
        for (int j=0; j<dimz; j++)
        {
            delete[] tab[i][j];
        }
        delete[] tab[i];
    }
    delete[] tab;
}


template <class T>
Tensor<T>& Tensor<T>::operator=(const Tensor &t) //przypisanie tensora
{
    dimx=t.dimx;
    dimy=t.dimy;
    dimz=t.dimz;
    tab = new T** [dimx];

    for(int i=0; i<dimx; i++)
    {
        tab[i] = new T* [dimy];
        for(int j=0; j<dimy; j++)
        {
            tab[i][j] = new T [dimz];
        }
    }

    for(int i=0; i<dimx; i++)
    {
        for(int j=0; j<dimy; j++)
        {
            for(int k=0; k<dimz; k++)
            {
                tab[i][j][k]=t.tab[i][j][k];
            }
        }
    }

    return *this;
}

template <class T>
bool Tensor<T>::operator==(Tensor const  &t)// porownanie tensora
{
    if (!(dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz)) return false;//porownanie wymiarow
    for (int i=0; i<dimx; i++)
    {
        for (int j=0; j<dimy; j++)
        {
            for(int k=0; k<dimz; k++)
            {
                if(this->tab[i][j][k]!=t.tab[i][j][k]) return false;//porownanie poszczegolnych wartosci
            }
        }
    }
    return true;
}

template<class T>
bool Tensor<T>::operator!=(Tensor const  &t)//dzialanie przeciwne do ==
{
    return !(*this==t);
}

template<class T>
Tensor<T> Tensor<T>::operator+(Tensor const &t)
{
    Tensor p(dimx, dimy, dimz);

    if ((dimx==t.dimx)&&(dimy==t.dimy)&&(dimz==t.dimz))
    {


        for (int i=0; i<dimx; i++)
        {
            for (int j=0; j<dimy; j++)
            {
                for(int k=0; k<dimz; k++)
                {
                    p.tab[i][j][k]=this->tab[i][j][k]+t.tab[i][j][k];//sumowanie wartosci poszczegolnych pol

                }
            }
        }
        return p;
    }
    else
    {
        throw 1;//rzucenie wartoscia w przypadku bledu
    }
}
template<class T>
Tensor<T>& Tensor<T>::operator+=(Tensor const  &t)
{
    if (!(dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz))
        throw 1;//rzucenie bledem w przypadku konfliktu wymiarow
    else
    {
        for (int i=0; i<dimx; i++)
        {
            for (int j=0; j<dimy; j++)
            {
                for(int k=0; k<dimz; k++)
                {
                    this->tab[i][j][k]=this->tab[i][j][k]+t.tab[i][j][k];//sumowanie wartosci poszczegolnych pol
                }
            }
        }
        return *this;
    }
}

template<class T>
Tensor<T> Tensor<T>::operator-(Tensor const  &t) const
{
    Tensor p(dimx, dimy, dimz);// tensor pomocniczy

    if ((dimx==t.dimx)&&(dimy==t.dimy)&&(dimz==t.dimz))
    {


        for (int i=0; i<dimx; i++)
        {
            for (int j=0; j<dimy; j++)
            {
                for(int k=0; k<dimz; k++)
                {
                    p.tab[i][j][k]=this->tab[i][j][k]-t.tab[i][j][k];//odejmowanie warotsci poszczegolnych pol

                }
            }
        }
        return p;
    }
    else
    {
        throw 1;//rzucenie bledem w przypadku konfliktu wymiarow
    }
}

template<class T>
Tensor<T>& Tensor<T>::operator-=(Tensor const  &t)
{
    if (!(dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz))
        throw 1;// rzucenie bledem w wprzypadku konfliktu wymiarow
    else
    {
        for (int i=0; i<dimx; i++)
        {
            for (int j=0; j<dimy; j++)
            {
                for(int k=0; k<dimz; k++)
                {
                    this->tab[i][j][k]=this->tab[i][j][k]-t.tab[i][j][k];// odejmowanie wartosci poszczegolnych pol
                }
            }
        }
        return *this;
    }
}

template<class T>
Tensor<T> Tensor<T>::operator*(Tensor const  &t)
{
    Tensor p(dimx, dimy, dimz);

    if ((dimx==t.dimx)&&(dimy==t.dimy)&&(dimz==t.dimz))
    {


        for (int i=0; i<dimx; i++)
        {
            for (int j=0; j<dimy; j++)
            {
                for(int k=0; k<dimz; k++)
                {
                    p.tab[i][j][k]=this->tab[i][j][k]*t.tab[i][j][k];//mnozenie wartosci poszczegolnych pol

                }
            }
        }
        return p;
    }
    else
    {
        throw 1;// rzucenie bledem w przypadku konfliktu wymiarow
    }
}

template<class T>
Tensor<T>& Tensor<T>::operator*=(Tensor const  &t)
{
    if (!(dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz))
        throw 1;// rzucenie bledem w wprzypadku konfliktu wymiarow
    else
    {
        for (int i=0; i<dimx; i++)
        {
            for (int j=0; j<dimy; j++)
            {
                for(int k=0; k<dimz; k++)
                {
                    this->tab[i][j][k]=this->tab[i][j][k]*t.tab[i][j][k];// mnozenie poszczegolncyh wartosci pol
                }
            }
        }
        return *this;
    }
}

template <class T>
void Tensor<T>::change(T w, int a, int b, int c)
{
    if(a>dimx||b>dimy||c>dimz) throw 1;//rzucenie bledem gdy rzadana wspolrzedna wykracza poza rozmiar tensora
    else this->tab[a][b][c]=w;
    return;
}

#endif // TENSOR_H_INCLUDED
