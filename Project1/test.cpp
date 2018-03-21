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
    cin.clear();
    cin.ignore(INT_MAX,'\n');
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
 void test(){//funkcja testujca zadane funkcje operatorow
 cout<<"Please insert matrix A:"<<endl;
 matrix a=inserting();
 cout<<"Please insert matrix B:"<<endl;
 matrix b=inserting();
 bool exit = 1;
 while(exit){//dzialanie w petli dopoki uzytkownik nie chce zakonczyc wykonywania operacji
 cout<<"Type the number of the operation, you want to perform:"<<endl;
 cout<<"1 - A+B"<<endl<<"2 - A-B"<<endl<<"3 - A*B"<<endl<<"4 - A==B"<<endl<<"5 - A!=B"<<endl<<"6 - A=A+B"<<endl<<"7 - A=A-B"<<endl<<"8 - A=A*B"<<endl<<"9 - A="<<endl<<"10- B="<<endl;
 int x;
 cin>>x;
while(!cin.good())//zabezpieczenie przed wpisaniem blednego znaku
        {
            cout<<endl<<"Type numbers from 1 to 10"<<endl;
            cin.clear();
            cin.ignore(INT_MAX,'\n');//w przypadku blednych danych wyczyszczenie reszty bufora
            cin>>x;
        }
 matrix c;
 bool w;
 switch(x){//wybor opcji za pomoca numerka

 case 1: c=a+b;
 cout<<endl<<"A+B="<<endl<<c<<endl;
 break;
 case 2: c=a-b;
 cout<<endl<<"A-B="<<endl<<c<<endl;
 break;
 case 3: c=a*b;
 cout<<endl<<"A*B="<<endl<<c<<endl;
 break;
 case 4: w=a==b;
 cout<<endl<<"Logic value of operation A==B: "<<w<<endl;
 break;
 case 5: w=a!=b;
 cout<<endl<<"Logic value of operation A!=B: "<<w<<endl;
 break;
 case 6: a+=b;
 cout<<endl<<"A="<<endl<<a<<endl;
 break;
 case 7: a-=b;
 cout<<endl<<"A="<<endl<<a<<endl;
 break;
 case 8: a*=b;
 cout<<endl<<"A="<<endl<<a<<endl;
 break;
 case 9: cout<<endl<<"A="<<endl<<a;
 break;
 case 10: cout<<endl<<"B="<<endl<<b;
 break;
 default:
 cout<<endl<<"There is no such an option."<<endl;
 break;
 }

 cout<<"Do you want to perform another operation? (1/0)";
 cin>>exit;


 }
 }
