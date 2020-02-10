#include <iostream>
#include <complex>
#include "TEST_TENSOR.h"
#define START "Rozpoczynam testowanie metod dla typu: "
#define TEST "Test metody: "
#define WYNIK " zakonczyl sie wynikiem: "
#define ERROR "Wrong dimensions!"

//test dzialania metod szablonu klasy Tensor dla typu int
bool testInt()
{
    cout<<START<<"int"<<endl<<endl;
//utworzenie tensorow, na ktorych beda testowane dzialania oraz tensora wyniku

    //tensory na ktorych wykonywane beda operacje i tensor, do ktorego zapisany bdz wynik
    Tensor<int> t1(2,2,2);
    Tensor<int> t2(2,2,2);
    Tensor<int> t3(2,2,2);

    //tensory z wynikami odpowiednich dzialan
    Tensor<int> resPlus(2,2,2);
    Tensor<int> resMul(2,2,2);
    Tensor<int> resMin(2,2,2);

    //elementy pierwszego tensora
    int t1_el1=3, t1_el2=4, t1_el3=3, t1_el4=0;
    int t1_el5=-1, t1_el6=4, t1_el7=2, t1_el8=3;

    //elementy drugiego tensora
    int t2_el1=1, t2_el2=4, t2_el3=3, t2_el4=6;
    int t2_el5=2, t2_el6=10, t2_el7=1, t2_el8=9;

//wpisanie wartosci odpowiednich tensorow
    t1.change(t1_el1,0,0,0);
    t1.change(t1_el2,0,0,1);
    t1.change(t1_el3,0,1,0);
    t1.change(t1_el4,0,1,1);
    t1.change(t1_el5,1,0,0);
    t1.change(t1_el6,1,0,1);
    t1.change(t1_el7,1,1,0);
    t1.change(t1_el8,1,1,1);

    t2.change(t2_el1,0,0,0);
    t2.change(t2_el2,0,0,1);
    t2.change(t2_el3,0,1,0);
    t2.change(t2_el4,0,1,1);
    t2.change(t2_el5,1,0,0);
    t2.change(t2_el6,1,0,1);
    t2.change(t2_el7,1,1,0);
    t2.change(t2_el8,1,1,1);

    resPlus.change(t1_el1+t2_el1,0,0,0);
    resPlus.change(t1_el2+t2_el2,0,0,1);
    resPlus.change(t1_el3+t2_el3,0,1,0);
    resPlus.change(t1_el4+t2_el4,0,1,1);
    resPlus.change(t1_el5+t2_el5,1,0,0);
    resPlus.change(t1_el6+t2_el6,1,0,1);
    resPlus.change(t1_el7+t2_el7,1,1,0);
    resPlus.change(t1_el8+t2_el8,1,1,1);

    resMin.change(t1_el1-t2_el1,0,0,0);
    resMin.change(t1_el2-t2_el2,0,0,1);
    resMin.change(t1_el3-t2_el3,0,1,0);
    resMin.change(t1_el4-t2_el4,0,1,1);
    resMin.change(t1_el5-t2_el5,1,0,0);
    resMin.change(t1_el6-t2_el6,1,0,1);
    resMin.change(t1_el7-t2_el7,1,1,0);
    resMin.change(t1_el8-t2_el8,1,1,1);

    resMul.change(t1_el1*t2_el1,0,0,0);
    resMul.change(t1_el2*t2_el2,0,0,1);
    resMul.change(t1_el3*t2_el3,0,1,0);
    resMul.change(t1_el4*t2_el4,0,1,1);
    resMul.change(t1_el5*t2_el5,1,0,0);
    resMul.change(t1_el6*t2_el6,1,0,1);
    resMul.change(t1_el7*t2_el7,1,1,0);
    resMul.change(t1_el8*t2_el8,1,1,1);

    //test metody read
    if(t1.read(0,1,1)!=t1_el4)
    {
        return false;
    }
    if(t2.read(1,0,0)!=t2_el5)
    {
        cout<<TEST<< "read"<< WYNIK <<0<<endl;
        return false;
    }
    cout<<TEST<< "read"<< WYNIK <<1<<endl;

    //test metody +
    t3=t1+t2;
    if(t3!=resPlus)
    {
        cout<<TEST<< "operator +"<< WYNIK <<0<<endl;
        return false;
    }
    cout<<TEST<< "operator +"<< WYNIK <<1<<endl;

    //test metody -
    t3=t1-t2;
    if(t3!=resMin)
    {
        cout<<TEST<< "operator -"<< WYNIK <<0<<endl;
        return false;
    }
    cout<<TEST<< "operator -"<< WYNIK <<1<<endl;

    //test metody *
    t3=t1*t2;
    if(t3!=resMul)
    {
        cout<<TEST<< "operator *"<< WYNIK <<0<<endl;
        return false;
    }
    cout<<TEST<< "operator *"<< WYNIK <<1<<endl;

    //test metody +=
    t1+=t2;
    if(t1!=resPlus)
    {
        cout<<TEST<< "operator +="<< WYNIK <<0<<endl;;
        return false;
    }
    cout<<TEST<< "operator +="<< WYNIK <<1<<endl;

    //test metody ==
    if(t1==t2)
    {
        cout<<TEST<< "operator =="<< WYNIK <<0<<endl;
        return false;
    }
    else
    {
        cout<<TEST<< "operator =="<< WYNIK <<1<<endl;
        return true;
    }
}


//testowanie dla typu double
bool testDouble()
{
    cout<<START<<"double"<<endl<<endl;
//utworzenie tensorow, na ktorych beda testowane dzialania oraz tensora wyniku

    //tensory na ktorych wykonywane beda operacje i tensor, do ktorego zapisany bdz wynik
    Tensor<double> t1(2,2,2);
    Tensor<double> t2(2,2,2);
    Tensor<double> t3(2,2,2);

    //tensory z wynikami odpowiednich dzialan: dodawania, mnozenia, odejmowania
    Tensor<double> resPlus(2,2,2);
    Tensor<double> resMul(2,2,2);
    Tensor<double> resMin(2,2,2);

    //elementy pierwszego tensora
    double t1_el1=3.1, t1_el2=4, t1_el3=3.7, t1_el4=0;
    double t1_el5=-1, t1_el6=4.8, t1_el7=2.0, t1_el8=3;

    //elementy drugiego tensora
    double t2_el1=1, t2_el2=4.4, t2_el3=3, t2_el4=6;
    double t2_el5=2.8, t2_el6=10.9, t2_el7=1, t2_el8=9;

    //ustawienie wartosci odpowiednich tensorow
    t1.change(t1_el1,0,0,0);
    t1.change(t1_el2,0,0,1);
    t1.change(t1_el3,0,1,0);
    t1.change(t1_el4,0,1,1);
    t1.change(t1_el5,1,0,0);
    t1.change(t1_el6,1,0,1);
    t1.change(t1_el7,1,1,0);
    t1.change(t1_el8,1,1,1);

    t2.change(t2_el1,0,0,0);
    t2.change(t2_el2,0,0,1);
    t2.change(t2_el3,0,1,0);
    t2.change(t2_el4,0,1,1);
    t2.change(t2_el5,1,0,0);
    t2.change(t2_el6,1,0,1);
    t2.change(t2_el7,1,1,0);
    t2.change(t2_el8,1,1,1);

    resPlus.change(t1_el1+t2_el1,0,0,0);
    resPlus.change(t1_el2+t2_el2,0,0,1);
    resPlus.change(t1_el3+t2_el3,0,1,0);
    resPlus.change(t1_el4+t2_el4,0,1,1);
    resPlus.change(t1_el5+t2_el5,1,0,0);
    resPlus.change(t1_el6+t2_el6,1,0,1);
    resPlus.change(t1_el7+t2_el7,1,1,0);
    resPlus.change(t1_el8+t2_el8,1,1,1);

    resMin.change(t1_el1-t2_el1,0,0,0);
    resMin.change(t1_el2-t2_el2,0,0,1);
    resMin.change(t1_el3-t2_el3,0,1,0);
    resMin.change(t1_el4-t2_el4,0,1,1);
    resMin.change(t1_el5-t2_el5,1,0,0);
    resMin.change(t1_el6-t2_el6,1,0,1);
    resMin.change(t1_el7-t2_el7,1,1,0);
    resMin.change(t1_el8-t2_el8,1,1,1);

    resMul.change(t1_el1*t2_el1,0,0,0);
    resMul.change(t1_el2*t2_el2,0,0,1);
    resMul.change(t1_el3*t2_el3,0,1,0);
    resMul.change(t1_el4*t2_el4,0,1,1);
    resMul.change(t1_el5*t2_el5,1,0,0);
    resMul.change(t1_el6*t2_el6,1,0,1);
    resMul.change(t1_el7*t2_el7,1,1,0);
    resMul.change(t1_el8*t2_el8,1,1,1);

    //test metody read
    if(t1.read(0,1,1)!=t1_el4)
    {
        return false;
    }
    if(t2.read(1,0,0)!=t2_el5)
    {
        cout<<TEST<< "read"<< WYNIK <<0<<endl;
        return false;
    }
    cout<<TEST<< "read"<< WYNIK <<1<<endl;

    //test metody +
    t3=t1+t2;
    if(t3!=resPlus)
    {
        cout<<TEST<< "operator +"<< WYNIK <<0<<endl;
        return false;
    }
    cout<<TEST<< "operator +"<< WYNIK <<1<<endl;

    //test metody -
    t3=t1-t2;
    if(t3!=resMin)
    {
        cout<<TEST<< "operator -"<< WYNIK <<0<<endl;
        return false;
    }
    cout<<TEST<< "operator -"<< WYNIK <<1<<endl;

    //test metody *
    t3=t1*t2;
    if(t3!=resMul)
    {
        cout<<TEST<< "operator *"<< WYNIK <<0<<endl;
        return false;
    }
    cout<<TEST<< "operator *"<< WYNIK <<1<<endl;

    //test metody +=
    t1+=t2;
    if(t1!=resPlus)
    {
        cout<<TEST<< "operator +="<< WYNIK <<0<<endl;;
        return false;
    }
    cout<<TEST<< "operator +="<< WYNIK <<1<<endl;

    //test metody ==
    if(t1==t2)
    {
        cout<<TEST<< "operator =="<< WYNIK <<0<<endl;
        return false;
    }
    else
    {
        cout<<TEST<< "operator =="<< WYNIK <<1<<endl;
        return true;
    }
}


//testowanie dla typu complex
bool testComplex()
{
    cout<<START<<"complex"<<endl<<endl;
//utworzenie tensorow, na ktorych beda testowane dzialania oraz tensora wyniku

    //tensory na ktorych wykonywane beda operacje i tensor, do ktorego zapisany bdz wynik
    Tensor< complex<int> > t1(2,2,2);
    Tensor< complex<int> > t2(2,2,2);
    Tensor< complex<int> > t3(2,2,2);

    //tensor zawierajacy wyniki odpowiednich dzialan: dodawania, mnozenia, odejmowania
    Tensor< complex<int> > resPlus(2,2,2);
    Tensor< complex<int> > resMul(2,2,2);
    Tensor< complex<int> > resMin(2,2,2);

    //elementy pierwszego tensora
    complex<int> t1_el1(9,7), t1_el2(8,8), t1_el3(8,6), t1_el4(0,7);
    complex<int> t1_el5(5,5), t1_el6(6,6), t1_el7(0,0), t1_el8(4,4);

    //elementy drugiego tensora
    complex<int> t2_el1(7,8), t2_el2(9,9), t2_el3(8,6), t2_el4(7,5);
    complex<int> t2_el5(10,6), t2_el6(9,9), t2_el7(5,3), t2_el8(7,3);

    //wpisanie wartosci odpowiednich tensorow
    t1.change(t1_el1,0,0,0);
    t1.change(t1_el2,0,0,1);
    t1.change(t1_el3,0,1,0);
    t1.change(t1_el4,0,1,1);
    t1.change(t1_el5,1,0,0);
    t1.change(t1_el6,1,0,1);
    t1.change(t1_el7,1,1,0);
    t1.change(t1_el8,1,1,1);

    t2.change(t2_el1,0,0,0);
    t2.change(t2_el2,0,0,1);
    t2.change(t2_el3,0,1,0);
    t2.change(t2_el4,0,1,1);
    t2.change(t2_el5,1,0,0);
    t2.change(t2_el6,1,0,1);
    t2.change(t2_el7,1,1,0);
    t2.change(t2_el8,1,1,1);

    resPlus.change(t1_el1+t2_el1,0,0,0);
    resPlus.change(t1_el2+t2_el2,0,0,1);
    resPlus.change(t1_el3+t2_el3,0,1,0);
    resPlus.change(t1_el4+t2_el4,0,1,1);
    resPlus.change(t1_el5+t2_el5,1,0,0);
    resPlus.change(t1_el6+t2_el6,1,0,1);
    resPlus.change(t1_el7+t2_el7,1,1,0);
    resPlus.change(t1_el8+t2_el8,1,1,1);

    resMin.change(t1_el1-t2_el1,0,0,0);
    resMin.change(t1_el2-t2_el2,0,0,1);
    resMin.change(t1_el3-t2_el3,0,1,0);
    resMin.change(t1_el4-t2_el4,0,1,1);
    resMin.change(t1_el5-t2_el5,1,0,0);
    resMin.change(t1_el6-t2_el6,1,0,1);
    resMin.change(t1_el7-t2_el7,1,1,0);
    resMin.change(t1_el8-t2_el8,1,1,1);

    resMul.change(t1_el1*t2_el1,0,0,0);
    resMul.change(t1_el2*t2_el2,0,0,1);
    resMul.change(t1_el3*t2_el3,0,1,0);
    resMul.change(t1_el4*t2_el4,0,1,1);
    resMul.change(t1_el5*t2_el5,1,0,0);
    resMul.change(t1_el6*t2_el6,1,0,1);
    resMul.change(t1_el7*t2_el7,1,1,0);
    resMul.change(t1_el8*t2_el8,1,1,1);

    //test metody read
    if(t1.read(0,1,1)!=t1_el4)
    {
        return false;
    }
    if(t2.read(1,0,0)!=t2_el5)
    {
        cout<<TEST<< "read"<< WYNIK <<0<<endl;
        return false;
    }
    cout<<TEST<< "read"<< WYNIK <<1<<endl;

    //test metody +
    t3=t1+t2;
    if(t3!=resPlus)
    {
        cout<<TEST<< "operator +"<< WYNIK <<0<<endl;
        return false;
    }
    cout<<TEST<< "operator +"<< WYNIK <<1<<endl;

    //test metody -
    t3=t1-t2;
    if(t3!=resMin)
    {
        cout<<TEST<< "operator -"<< WYNIK <<0<<endl;
        return false;
    }
    cout<<TEST<< "operator -"<< WYNIK <<1<<endl;

    //test metody *
    t3=t1*t2;
    if(t3!=resMul)
    {
        cout<<TEST<< "operator *"<< WYNIK <<0<<endl;
        return false;
    }
    cout<<TEST<< "operator *"<< WYNIK <<1<<endl;

    //test metody +=
    t1+=t2;
    if(t1!=resPlus)
    {
        cout<<TEST<< "operator +="<< WYNIK <<0<<endl;;
        return false;
    }
    cout<<TEST<< "operator +="<< WYNIK <<1<<endl;

    //test metody ==
    if(t1==t2)
    {
        cout<<TEST<< "operator =="<< WYNIK <<0<<endl;
        return false;
    }
    else
    {
        cout<<TEST<< "operator =="<< WYNIK <<1<<endl;
        return true;
    }
}

//funkcja testujaca przypadek dzialania na tensorach roznych wymiarow
bool testDimensions()
{
    cout<<START<<"incorrect dimensions"<<endl<<endl;
//utworzenie tensorow, na ktorych beda testowane dzialania oraz tensora wyniku

    Tensor<int> t1(2,2,2);
    Tensor<int> t2(2,2,3);
    Tensor<int> t3(2,2,2);

    //tensory wynikowe: dodawania, mnozenia, odejmowania
    Tensor<int> resPlus(2,2,2);
    Tensor<int> resMul(2,2,2);
    Tensor<int> resMin(2,2,2);

    //elementy pierwszego tensora
    int t1_el1=3, t1_el2=4, t1_el3=3, t1_el4=0;
    int t1_el5=-1, t1_el6=4, t1_el7=2, t1_el8=3;

    //elementy drugiego tensora
    int t2_el1=1, t2_el2=4, t2_el3=3, t2_el4=6;
    int t2_el5=2, t2_el6=10, t2_el7=1, t2_el8=9;

    //wpisanie wartosci odpowiednich tensorow
    t1.change(t1_el1,0,0,0);
    t1.change(t1_el2,0,0,1);
    t1.change(t1_el3,0,1,0);
    t1.change(t1_el4,0,1,1);
    t1.change(t1_el5,1,0,0);
    t1.change(t1_el6,1,0,1);
    t1.change(t1_el7,1,1,0);
    t1.change(t1_el8,1,1,1);

    t2.change(t2_el1,0,0,0);
    t2.change(t2_el2,0,0,1);
    t2.change(t2_el3,0,1,0);
    t2.change(t2_el4,0,1,1);
    t2.change(t2_el5,1,0,0);
    t2.change(t2_el6,1,0,1);
    t2.change(t2_el7,1,1,0);
    t2.change(t2_el8,1,1,1);

    resPlus.change(t1_el1+t2_el1,0,0,0);
    resPlus.change(t1_el2+t2_el2,0,0,1);
    resPlus.change(t1_el3+t2_el3,0,1,0);
    resPlus.change(t1_el4+t2_el4,0,1,1);
    resPlus.change(t1_el5+t2_el5,1,0,0);
    resPlus.change(t1_el6+t2_el6,1,0,1);
    resPlus.change(t1_el7+t2_el7,1,1,0);
    resPlus.change(t1_el8+t2_el8,1,1,1);

    resMin.change(t1_el1-t2_el1,0,0,0);
    resMin.change(t1_el2-t2_el2,0,0,1);
    resMin.change(t1_el3-t2_el3,0,1,0);
    resMin.change(t1_el4-t2_el4,0,1,1);
    resMin.change(t1_el5-t2_el5,1,0,0);
    resMin.change(t1_el6-t2_el6,1,0,1);
    resMin.change(t1_el7-t2_el7,1,1,0);
    resMin.change(t1_el8-t2_el8,1,1,1);

    resMul.change(t1_el1*t2_el1,0,0,0);
    resMul.change(t1_el2*t2_el2,0,0,1);
    resMul.change(t1_el3*t2_el3,0,1,0);
    resMul.change(t1_el4*t2_el4,0,1,1);
    resMul.change(t1_el5*t2_el5,1,0,0);
    resMul.change(t1_el6*t2_el6,1,0,1);
    resMul.change(t1_el7*t2_el7,1,1,0);
    resMul.change(t1_el8*t2_el8,1,1,1);

    //test metody read
    if(t1.read(0,1,1)!=t1_el4)
    {
        return false;
    }
    if(t2.read(1,0,0)!=t2_el5)
    {
        cout<<TEST<< "read"<< WYNIK <<0<<endl;
        return false;
    }
    cout<<TEST<< "read"<< WYNIK <<1<<endl;

    //test metody +
    try
    {
        t3=t1+t2;
    }
    catch(int error)
    {
        if(error==1)
        {
            cerr<<"Operator +: "<<ERROR<<endl;
        }
    }

    //test metody -
    try
    {
        t3=t1-t2;
    }
    catch(int error)
    {
        if(error==1)
        {
            cerr<<"Operator -: "<<ERROR<<endl;
        }
    }

    //test metody *
    try
    {
        t3=t1*t2;
    }
    catch(int error)
    {
        if(error==1)
        {
            cerr<<"Operator *: "<<ERROR<<endl;
        }
    }

    //test metody ==
    if(t1==t2)
    {
        cout<<TEST<< "operator =="<< WYNIK <<0<<endl;
        return false;
    }
    else
    {
        cout<<TEST<< "operator =="<< WYNIK <<1<<endl;
        return true;
    }
}

//funkcja prezentujaca dzialanie metod cin i cout
void testCinCout()
{
    Tensor<int> t(3,1,1);
    cin>>t;
    cout<<t;
}
