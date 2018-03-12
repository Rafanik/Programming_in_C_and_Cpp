#include <iostream>
#include "matrix.h"

using namespace std;


int main()
{
matrix a(3,4);
a.value[1][20]=10;

cout<<a.rows;

return 0;
}
