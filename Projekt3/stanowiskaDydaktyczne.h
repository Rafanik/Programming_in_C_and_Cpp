#ifndef STANOWISKADYDAKTYCZNE_H_INCLUDED
#define STANOWISKADYDAKTYCZNE_H_INCLUDED
#include <string>
using namespace std;

//sciezka naukowo dydaktyczna:
class stanowiskoDydaktyczne
{
    const string stanowisko = "brak";
public:
    virtual inline string podajStanowisko()
    {
        return stanowisko;
    }
};

class asystent : public stanowiskoDydaktyczne
{
    const string stanowisko = "asystent";
public:
    virtual inline string podajStanowisko()
    {
        return stanowisko;
    }
};

class adiunkt : public asystent
{
    const string stanowisko = "adiunkt";
public:
    virtual inline string podajStanowisko()
    {
        return stanowisko;
    }
};

class profesorNadzw : public adiunkt
{
    const string stanowisko = "profesor nadzwyczajny";
public:
    virtual inline string podajStanowisko()
    {
        return stanowisko;
    }
};

class profesorZw : public profesorNadzw
{
    const string stanowisko = "profesor zwyczajny";
public:
    virtual inline string podajStanowisko()
    {
        return stanowisko;
    }
};

//sciezka dydaktyczna
class wykladowca : public stanowiskoDydaktyczne
{
    const string stanowisko = "wykladowca";
public:
    virtual inline string podajStanowisko()
    {
        return stanowisko;
    }
};

class starszyWykladowca : public wykladowca
{
    const string stanowisko = "starszy wykladowca";
public:
    virtual inline string podajStanowisko()
    {
        return stanowisko;
    }
};

class docent : public starszyWykladowca
{
    const string stanowisko = "docent";
public:
    virtual inline string podajStanowisko()
    {
        return stanowisko;
    }
};



#endif // STANOWISKADYDAKTYCZNE_H_INCLUDED
