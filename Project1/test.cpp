#include <iostream>
#include "matrix.h"
#include <limits.h>

matrix inserting()//funkcja pozwala uzytkownikowi okreslic wymiary wprowadzanej macierzy a nastepnie wprowadzic jej wartosci poziomu konsoli
{
    int rows, columns;
    cout<<"Give the dimensions of matrix:"<<endl;
    do//sprawdzenie czy zostala podana liczba calkowita w innym przypadku ponowienie prosby o podanie liczby wierszy
    {
        cout<<"rows:";
        if(!cin.good())
        {
            cin.clear();
            cin.ignore(INT_MAX,'\n');//w przypadku blednych danych wyczyszczenie reszty bufora
        }
        cin>>rows;
    }
    while(!cin.good());
    do// analogiczne zabezpieczenie wprowadzania danych jak w przypadku wierszy
    {
        cout<<"columns:";
        if(!cin.good())
        {
            cin.clear();
            cin.ignore(INT_MAX,'\n');
        }
        cin>>columns;
    }
    while(!cin.good());
    matrix a(rows, columns);
    cin>>a;
    cout<<"Your matrix is:"<<endl<<a;
    return a;

}
 void test(){
 cout<<"Please insert matrix A:"<<endl;
 matrix a=inserting();
 cout<<"Please insert matrix A:"<<endl;
 matrix b=inserting();
 bool exit = 1;
 while(exit){
 cout<<"Type the number of the operation, you want to perform:"<<endl;
 cout<<"1 - A+B"<<endl<<"2 - A-B"<<endl<<"3 - A*B"<<endl<<"4 - A==B"<<endl<<"5 - A!=B"<<endl;
 int x;
 cin>>x;
 matrix c;
 switch(x){

 case 1: c=a;
 break;
 case 2: c=a;
 break;
 case 3: c=a;
 break;
 case 4: //c=a==b;
 break;
 case 5: //c=a!=b;
 break;
 }
 cout<<c;
 cout<<"Do you want to perform another operation? (1/0)";
 cin>>exit;


 }
 }
