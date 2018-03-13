#include <iostream>
#include "matrix.h"

using namespace std;


int main()
{
matrix a(2,1);
matrix b(2,1);
a.value[1][1]=10;
a.value[2][1]=10;
b.value[1][1]=5;
b.value[2][1]=10;
b-=a;
b-=a;

cout<<b;
return 0;

}
