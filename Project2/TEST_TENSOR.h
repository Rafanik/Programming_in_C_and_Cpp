#ifndef TEST_TENSOR_H_INCLUDED
#define TEST_TENSOR_H_INCLUDED
//plik naglowkowy funkcji testujacych szablon klasy Tensor
#include "TENSOR.H"

//funkcja testujaca metody klasy Tensor dla typu int
bool testInt();

//funkcja testujaca metody klasy Tensor dla typu double
bool testDouble();

//funkcja testujaca metody klasy Tensor dla typu complex
bool testComplex();

//funkcja testujaca przypadek dzialania na tensorach roznych wymiarow
bool testDimensions();

//funkcja prezentujaca dzialanie metod cin i cout
void testCinCout();

#endif // TEST_TENSOR_H_INCLUDED
