#include <iostream>
#include "matrix.h"

/*class matrix
{
int rows;
int columns;
int** value;*/

matrix::matrix(int a, int b){
rows=a;
columns=b;
int** pixmap;
        pixmap = new int* [rows];
        int i;
        for(i = 0; i < rows; i++)
            pixmap[i] = new int [columns];
value = pixmap;

}


//};


