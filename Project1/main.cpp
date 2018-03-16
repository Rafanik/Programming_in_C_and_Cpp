#include <iostream>
#include "matrix.h"

using namespace std;

matrix inserting(){
int rows, columns;
cout<<"Give the dimensions of matrix:"<<endl<<"rows:";
cin>>rows;
cout<<"columns:";
cin>>columns;
matrix a(rows, columns);
cin>>a;
cout<<"Your matrix is:"<<endl<<a;
return a;

}

int main()
{
inserting();
return 0;

}
