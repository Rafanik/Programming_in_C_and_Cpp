/* Rafał Szczepanik
*plik żródłowy klasy matrix zwierajacy implementacje funkcji testujacych
*/
#include <iostream>
#include "matrix.h"
#include <limits.h>

matrix inserting()//funkcja pozwala uzytkownikowi okreslic wymiary wprowadzanej macierzy a nastepnie wprowadzic jej wartosci poziomu konsoli
{
    int rows, columns;
    cout<<endl<<"Give the dimensions of matrix:"<<endl;
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
    cout<<endl<<"Your matrix is:"<<endl<<a;
    return a;

}
void test() //funkcja testujca zadane funkcje operatorow
{
    cout<<endl<<"Please insert matrix A:"<<endl;
    matrix a=inserting();
    cout<<endl<<"Please insert matrix B:"<<endl;
    matrix b=inserting();
    bool exit = 1;
    while(exit) //dzialanie w petli dopoki uzytkownik nie chce zakonczyc wykonywania operacji
    {
        cout<<endl<<"Type the number of the operation, you want to perform:"<<endl;
        cout<<"1 - A+B"<<endl<<"2 - A-B"<<endl<<"3 - A*B"<<endl<<"4 - A==B"<<endl<<"5 - A!=B"<<endl<<"6 - A=A+B"<<endl<<"7 - A=A-B"<<endl<<"8 - A=A*B"<<endl<<"9 - A="<<endl<<"10- B="<<endl<<"11 - A(x,y)="<<endl<<"12 - A(x,y)=v"<<endl;
        int x;
        int rows,cols,val;//zmienne pomocnicze r-rows, c columns, v - value
        cin>>x;
        while(!cin.good())//zabezpieczenie przed wpisaniem blednego znaku
        {
            cout<<endl<<"Type numbers from 1 to 12"<<endl;
            cin.clear();
            cin.ignore(INT_MAX,'\n');//w przypadku blednych danych wyczyszczenie reszty bufora
            cin>>x;
        }
        matrix c;
        bool w;
        switch(x) //wybor opcji za pomoca numerka
        {

        case 1:
            c=a+b;
            cout<<endl<<"A+B="<<endl<<c<<endl;
            break;
        case 2:
            c=a-b;
            cout<<endl<<"A-B="<<endl<<c<<endl;
            break;
        case 3:
            c=a*b;
            cout<<endl<<"A*B="<<endl<<c<<endl;
            break;
        case 4:
            w=a==b;
            cout<<endl<<"Logic value of operation A==B: "<<w<<endl;
            break;
        case 5:
            w=a!=b;
            cout<<endl<<"Logic value of operation A!=B: "<<w<<endl;
            break;
        case 6:
            a+=b;
            cout<<endl<<"A="<<endl<<a<<endl;
            break;
        case 7:
            a-=b;
            cout<<endl<<"A="<<endl<<a<<endl;
            break;
        case 8:
            a*=b;
            cout<<endl<<"A="<<endl<<a<<endl;
            break;
        case 9:
            cout<<endl<<"A="<<endl<<a;
            break;
        case 10:
            cout<<endl<<"B="<<endl<<b;
            break;
        case 11:
            cout<<endl<<"Type the coordinates"<<endl<<"x:";
            cin>>rows;
            cout<<endl<<"y:";
            cin>>cols;
            cout<<endl<<"A(x,y)="<<a.getValue(rows,cols);
            break;
        case 12:
            cout<<endl<<"Type the coordinates"<<endl<<"x:";
            cin>>rows;
            cout<<endl<<"y:";
            cin>>cols;
            cout<<endl<<"Type the value that is to be set:";
            cin>>val;
            a.setValue(rows,cols,val);
            cout<<endl<<"A(x,y)="<<a.getValue(rows,cols)<<endl;
            break;
        default:
            cout<<endl<<"There is no such an option."<<endl;
            break;
        }

        cout<<endl<<"Do you want to perform another operation? (1/0)";
        cin>>exit;


    }
}
