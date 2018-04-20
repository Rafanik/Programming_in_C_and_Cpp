#ifndef TEST_TENSOR_H_INCLUDED
#define TEST_TENSOR_H_INCLUDED
//plik naglowkowy funkcji testujacych szablon klasy Tensor
#include "TENSOR.H"
template <class T>
class TestTensor{
Tensor<T> tens1;
Tensor<T> tens2;
Tensor<T> wynik;;
public:
TestTensor(Tensor<T> &, Tensor<T> &, Tensor<T> &);
//metody
void reset(T , T , T , T );//ustawienie poczatkowych wartosci testujacych
void setResult(T,T);
bool testOpPlus();
bool testOpPlusEq();
bool testOpMin();
bool testOpMinEq();
bool testOpMul();
bool testOpMulEq();
bool testOpEq(bool);
bool testOpDif(bool);
bool testOpPrz();
bool testChangeRead(T);
};

template <class T>
TestTensor<T>::TestTensor(Tensor<T> &t1, Tensor<T> &t2, Tensor<T> &w){
tens1=t1;
tens2=t2;
wynik=w;
}

template<class T>
void TestTensor<T>::reset(T x1, T x2, T y1, T y2){
tens1.change(x1, 0, 0, 0);
tens1.change(x2, 0, 0, 1);
tens2.change(y1, 0, 0, 0);
tens2.change(y2, 0, 0, 1);
}

template<class T>
void TestTensor<T>::setResult(T x1, T x2){
wynik.change(x1, 0, 0, 0);
wynik.change(x2, 0, 0, 1);
}

template <class T>
bool TestTensor<T>::testOpPlus(){
return (tens1+tens2==wynik);
}

template <class T>
bool TestTensor<T>::testOpPlusEq(){
tens1+=tens2;
return tens1==wynik;
}

template <class T>
bool TestTensor<T>::testOpMin(){
return tens1-tens2==wynik;
}

template <class T>
bool TestTensor<T>::testOpMinEq(){
tens1-=tens2;
return tens1==wynik;
}

template <class T>
bool TestTensor<T>::testOpMul(){
return tens1*tens2==wynik;
}

template <class T>
bool TestTensor<T>::testOpMulEq(){
tens1*=tens2;
return tens1==wynik;
}

template<class T>
bool TestTensor<T>::testOpEq(bool b){
return (tens1==tens2)==b;
}

template<class T>
bool TestTensor<T>::testOpDif(bool b){
return (tens1!=tens2)==b;
}

template<class T>
bool TestTensor<T>::testOpPrz(){
tens1=tens2;
return tens1==tens2;
}

template<class T>
bool TestTensor<T>::testChangeRead(T w){
tens1.change(w,0,0,0);
return tens1.read(0,0,0)==w;
}

void testInt();
void testDouble();

#endif // TEST_TENSOR_H_INCLUDED
