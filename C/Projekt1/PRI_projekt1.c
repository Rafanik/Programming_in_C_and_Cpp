#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b, c ,m; //zmienne wprowadzane przez uzytkwonika
    int n = 10000;
    int i; //zmienna iteracyjna
    float moment;
    float mianownik = 0;
    float licznik = 0;
    char input[256];
    char symb;

    printf("insert a,b,c,m (separated with commas):\n");
    fgets(input,256,stdin);
    sscanf(input, "%f %c %f %c %f %c %f", &a, &symb, &b, &symb, &c, &symb, &m);

    for(i=0;i<=n;i++)
    {
    licznik=licznik+pow(i*c/n,4);
    mianownik=mianownik+pow(i*c/n,2);
    }
    moment=0.5*m*licznik/mianownik;
    printf("f(x)=%gx+%g\ny=%g\nm=%gkg\nI=%fkg*m^2\n", a, b, c, m, moment);




    return 0;
}
