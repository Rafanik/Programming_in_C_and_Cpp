#include <iostream>
#include "TEST_TENSOR.h"
//definicje używanych napisów
#define START "Rozpoczynam testowanie metod dla typu: "
#define TEST "Test metody: "
#define WYNIK " zakonczyl sie wynikiem: "

//Scenariusz testowy dla poszczególnych klas
void testInt(){//test klasy int
cout<<START<<"int"<<endl<<endl;
Tensor<int> t1(1,1,2);//stworzenie zerowych tensorów o odpowiednich wymiarach
Tensor<int> t2(1,1,2);
Tensor<int> wynik(1,1,2);
TestTensor<int> test(t1, t2, wynik);
cout<<TEST<<"Change i Read"<<WYNIK<<test.testChangeRead(7)<<endl<<endl;//test metod change oraz read
test.reset(2,3,4,5);//ustawienie wartości pól tensorów, na których testowane będzie działanie metody operator+
test.setResult(6,8);//ustawienie przewidywanego wyniku działania metody operator+ /+= w polach tensora wynik
cout<<TEST<<"Op+"<<WYNIK<<test.testOpPlus()<<endl<<endl;// przeprowadzenie testu operator+ oraz operator+= i wyświetlenie wyniku testu
cout<<TEST<<"Op+="<<WYNIK<<test.testOpPlusEq()<<endl<<endl;
test.reset(8,3,4,5);//ustawienie wartości pól tensorów, na których testowane będzie działanie metody operator- /-=
test.setResult(4,-2);//ustawienie przewidywanego wyniku działania metody operator- /-= w polach tensora wynik
cout<<TEST<<"Op-"<<WYNIK<<test.testOpMin()<<endl<<endl;// przeprowadzenie testu operator- oraz operator-= i wyświetlenie wyniku testu
cout<<TEST<<"Op-="<<WYNIK<<test.testOpMinEq()<<endl<<endl;
test.reset(3,3,4,5);//ustawienie wartości pól tensorów, na których testowane będzie działanie metody operator* /*=
test.setResult(12,15);//ustawienie przewidywanego wyniku działania metody operator* /*= w polach tensora wynik
cout<<TEST<<"Op*"<<WYNIK<<test.testOpMul()<<endl<<endl;// przeprowadzenie testu operator* oraz operator*= i wyświetlenie wyniku testu
cout<<TEST<<"Op*="<<WYNIK<<test.testOpMulEq()<<endl<<endl;
test.reset(7,9,7,9);//ustawienie wartości pól tensorów, na których testowane będzie działanie metody operator=
cout<<TEST<<"Op=="<<WYNIK<<test.testOpEq(1)<<endl<<endl;// przeprowadzenie testu operator==/ !=/ = i wyświetlenie wyniku testu
cout<<TEST<<"Op!="<<WYNIK<<test.testOpDif(0)<<endl<<endl;
cout<<TEST<<"Op="<<WYNIK<<test.testOpPrz()<<endl<<endl;

}
//schemat testowania analogiczny jak dla klasy int
void testDouble(){
cout<<START<<"double"<<endl<<endl;
Tensor<double> t1(1,1,2);
Tensor<double> t2(1,1,2);
Tensor<double> wynik(1,1,2);
TestTensor<double> test(t1, t2, wynik);
cout<<TEST<<"Change i Read"<<WYNIK<<test.testChangeRead(7)<<endl<<endl;
test.reset(2.2,3.5,4.1,5.1);
test.setResult(6.3,8.6);
cout<<TEST<<"Op+"<<WYNIK<<test.testOpPlus()<<endl<<endl;
cout<<TEST<<"Op+="<<WYNIK<<test.testOpPlusEq()<<endl<<endl;
test.reset(8,3.2,4.3,5.7);
test.setResult(3.7,-2.5);
cout<<TEST<<"Op-"<<WYNIK<<test.testOpMin()<<endl<<endl;
cout<<TEST<<"Op-="<<WYNIK<<test.testOpMinEq()<<endl<<endl;
test.reset(2.5,3,4.0,0.5);
test.setResult(10,1.5);
cout<<TEST<<"Op*"<<WYNIK<<test.testOpMul()<<endl<<endl;
cout<<TEST<<"Op*="<<WYNIK<<test.testOpMulEq()<<endl<<endl;
test.reset(7.34,9.33,7.34,9.33);
cout<<TEST<<"Op=="<<WYNIK<<test.testOpEq(1)<<endl<<endl;
cout<<TEST<<"Op!="<<WYNIK<<test.testOpDif(0)<<endl<<endl;
cout<<TEST<<"Op="<<WYNIK<<test.testOpPrz()<<endl<<endl;
}
