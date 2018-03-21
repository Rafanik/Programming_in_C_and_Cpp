#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
matrix a(1,2);
a.value[0][0]=1;
matrix b(1,2);
b.value[0][0]=2;

a-=b;
cout<<a;

return 0;

}
