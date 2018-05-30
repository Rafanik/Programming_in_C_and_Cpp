#ifndef TYTULYNAUKOWE_H_INCLUDED
#define TYTULYNAUKOWE_H_INCLUDED
#include <string>
using namespace std;
//sciezka naukowa

class tytulNaukowy
{
string tytul =" ";
public:
virtual inline string podajTytul(){return tytul;}
};



class inzynier : public tytulNaukowy
{
protected:
    const string tytul = "inz. ";
public:
    virtual inline string podajTytul(){return tytul;}
};

class magister : public inzynier
{
protected:
    const string tytul = "mgr inz. ";
public:
    virtual inline string podajTytul(){return tytul;}
};

class doktor : public magister
{
protected :
    const string tytul ="dr ";
public :
    virtual inline string podajTytul(){return tytul;}

};

class doktorHab : public doktor
{
protected :
    const string tytul ="dr hab. ";
public :
    virtual inline string podajTytul(){return tytul;}
};

class profesor : public doktorHab
{
protected :
    const string tytul = "prof. ";
public :
    virtual inline string podajTytul(){return tytul;}

};



#endif // TYTULYNAUKOWE_H_INCLUDED
