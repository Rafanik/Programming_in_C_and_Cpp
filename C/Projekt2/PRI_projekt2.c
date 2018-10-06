#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ncurses.h>
#define MAX 70

typedef struct
{
    char value[MAX+3];
    char sign;
    char end;
} number;

number result= {"0",' '};






void reverse(char numb[])// jako parametry przyjmuje tablice oraz ilosc zapelnionych komorek (w przypadku napisu, bez ostatniej), odwraca kolejnosc elementow tablicy
{
    char temp;
    int i, j;
    int size = strlen(numb);

    for(i=0, j=size-1; i<(size/2); i++, j--)
    {
        temp=numb[i];
        numb[i]=numb[j];
        numb[j]=temp;
    }
}

void copy(char fnumb[],char snumb[])//funkcja kopiuje zawartosc pierwszej tablicy do drugiej, jako parametry przyjmuje dwie tablice (pierwsza bdz kopiowana) oraz dlugosci tych tablic
{
    int i=0;
    int fsize=strlen(fnumb), ssize=strlen(snumb);
    for(i=0; i<fsize; i++)
    {
        snumb[i]=fnumb[i];
    }
    for(; i<ssize; i++)
    {
        snumb[i]=0;
    }
}

void clearTab(char tab[],int size)//funkcja pobiera tablice oraz jej rozmiar i w kazde pole wpisuje wartosc 0

{
    int i;
    for (i=0; i<size; i++)
    {
        tab[i]=0;
    }
}

void add(char fnumb[],char snumb[])//funkcja pobiera dwie tablice znakowe z cyframi od 0 do 10 oraz ich dlugosci i dodaje je do siebie
{
    int fsize=strlen(fnumb), ssize=strlen(snumb);
    reverse(fnumb);
    reverse(snumb);
    clearTab(result.value, sizeof result.value);
    result.value[0]='0';
    int temp;
    int i;
    for (i=0; (i<=fsize-1)||(i<=ssize-1); i++)//indeks ostatniej komorki jest o 1 mniejszy od dlugosci, stad fsize-1
    {
        int a = (i<=fsize-1)?fnumb[i]-'0':0;//wartosci przechowywane na tych polach, jesli wyjdzie poza liczbe to 0
        int b = (i<=ssize-1)?snumb[i]-'0':0;
        int c = result.value[i]-'0';
        result.value[i]='0'+(a+b+c)%10;
        result.value[i+1]='0'+((a+b+c)-(a+b+c)%10)/10;

    }
    result.value[strlen(result.value)-1]=result.value[strlen(result.value)-1]=='0'?0:result.value[strlen(result.value)-1];//jesli ostatnia (po obrocie pierwsza) cyfra jest 0 to wyczyscic te komorke
    reverse(fnumb);
    reverse(snumb);
    reverse(result.value);

    if(strlen(result.value)>MAX)
    {
        attron( COLOR_PAIR( 1 ) );
        printw("\nWynik jest zbyt duzy.\nMaksymalna dlugosc wyniku: %d\n",MAX);
        attroff( COLOR_PAIR( 1 ) );
        clearTab(result.value,sizeof result.value);
        result.value[0]='0';
    }

}

void mul(char fnumb[],char snumb[])//funkcja pobiera dwie tablice znakowe z cyframi od 0 do 10 (pierwsza liczba musi byc wieksza od drugiej) oraz ich dlugosci i odejmuje je do siebie
{
    int fsize=strlen(fnumb), ssize=strlen(snumb);
    reverse(fnumb);
    reverse(snumb);
    clearTab(result.value,sizeof result.value);
    result.value[0]='0';
    char tempresult[MAX+1]= {'0'};
    char tempresult1[MAX+1]= {'0'};
    int temp;
    int i;
    int j;
    for (i=0; i<=fsize-1; i++)
    {
        for(j=0; j<=ssize-1; j++ )
        {


            int a = (i<=fsize-1)?fnumb[i]-'0':0;//wartosci przechowywane na tych polach, jesli wyjdzie poza liczbe to 0
            int b = (j<=ssize-1)?snumb[j]-'0':0;
            int c = tempresult[i+j]-'0';
            tempresult[i+j]='0'+(a*b+c)%10;
            tempresult[i+j+1]='0'+((a*b+c)-(a*b+c)%10)/10;
        }

        tempresult[strlen(tempresult)-1]=tempresult[strlen(tempresult)-1]=='0'?0:tempresult[strlen(tempresult)-1];
        reverse(tempresult);
        copy(result.value,tempresult1);
        if(strlen(tempresult)>MAX)
        {
            attron( COLOR_PAIR( 1 ) );
            printw("\nWynik jest zbyt duzy.\nMaksymalna dlugosc wyniku: %d\n",MAX);
            attroff( COLOR_PAIR( 1 ) );
            clearTab(result.value,sizeof result.value);
            result.value[0]='0';
            break;
        }
        add(tempresult1,tempresult);

        clearTab(tempresult1,sizeof tempresult1);
        clearTab(tempresult,sizeof tempresult);

        int m = 0;
        for(; m<=i+1; m++)
        {
            tempresult[m]='0';
        }

    }
    int a;
    if(result.value[0]=='0')
    {
        for(a=strlen(result.value)-1; a>0; a--)
        {
            if(result.value[a]!='0')
            {
                break;
            }
            result.value[a]= 0;//jesli ostatnia (po obrocie pierwsza) cyfra jest 0 to wyczyscic te komorke
        }
    }
    reverse(fnumb);
    reverse(snumb);
}

void sub(char fnumb[],char snumb[])//funkcja pobiera dwie tablice znakowe z cyframi od 0 do 10 (pierwsza liczba musi byc wieksza od drugiej) oraz ich dlugosci i odejmuje je do siebie
{
    int fsize=strlen(fnumb), ssize=strlen(snumb);
    reverse(fnumb);
    reverse(snumb);
    clearTab(result.value,sizeof result.value);
    result.value[0]='0';

    int i;
    for (i=0; (i<=fsize-1)||(i<=ssize-1); i++)
    {
        int a = (i<=fsize-1)?fnumb[i]-'0':0;//wartosci przechowywane na tych polach, jesli wyjdzie poza liczbe to 0
        int b = (i<=ssize-1)?snumb[i]-'0':0;
        int c = result.value[i]-'0';
        if(a-b+c<0)
        {
            result.value[i]='0'+abs(10+(a-b+c))%10;
            result.value[i+1]='0'-1;
        }
        else
        {
            result.value[i]='0'+a-b+c;
            result.value[i+1]='0';
        }
    }
    int a;
    for(a=strlen(result.value)-1; a>0; a--)
    {
        if(result.value[a]!='0')
        {
            break;
        }
        result.value[a]= 0;//jesli ostatnia (po obrocie pierwsza) cyfra jest 0 to wyczyscic te komorke
    }
    reverse(fnumb);
    reverse(snumb);
    reverse(result.value);
    if(strlen(result.value)>MAX)
    {
        attron( COLOR_PAIR( 1 ) );
        printw("\nWynik jest zbyt duzy.\nMaksymalna dlugosc wyniku: %d\n",MAX);
        attroff( COLOR_PAIR( 1 ) );
        clearTab(result.value,sizeof result.value);
        result.value[0]='0';
    }
}

void fac(char fnumb[])
{

    char one[MAX+1]= {'1'};
    char tempresult[MAX+1]= {'1'};
    char tempresult1[MAX+1]= {'1'};
    int i=0;
    if(strcmp(fnumb,one)==0||strcmp(fnumb,"0")==0)
    {
        clearTab(result.value,strlen(result.value));
        result.value[0]='1';
    }
    else
    {
        result.value[0]='1';
        while(strcmp(fnumb,tempresult)!=0)
        {
            if(strcmp(result.value,"0")==0)
            {
                break;
            }
            ++i;
            add(tempresult,one);
            copy(result.value,tempresult);
            mul(tempresult1,tempresult);
            copy(result.value,tempresult1);
        }
    }
}

void print(number fnumb,number snumb,char symb)
{
    if(fnumb.sign=='-'&&snumb.sign!='-')
    {
        printw("%c%s%c%s",fnumb.sign,fnumb.value,symb,snumb.value);
    }
    else
    {
        if(snumb.sign=='-'&&fnumb.sign!='-')
        {
            printw("%s%c%c%s",fnumb.value,symb,snumb.sign,snumb.value);
        }
        else
        {
            if(fnumb.sign=='-'&&snumb.sign=='-')
            {
                printw("%cs%c%c%s",fnumb.sign,fnumb.value,symb,snumb.sign,snumb.value);

            }
            else
            {
                printw("%s%c%s",fnumb.value,symb,snumb.value);
            }

        }
    }


}

int main()
{
    initscr(); //Start
    start_color();
    char c;
    char input[256];
    char symb;
    number fnumb,snumb;
    fnumb.end=0;
    snumb.end=0;
    clearTab(input,sizeof input);
    noecho();
    int i;
    init_pair( 1, COLOR_RED, COLOR_BLACK ); //3
    init_pair( 2, COLOR_GREEN, COLOR_BLACK ); //3

    while(c!='Q')
    {
        int i =0;
        fnumb.end=0;
        snumb.end=0;
        clearTab(fnumb.value,sizeof fnumb.value);
        clearTab(snumb.value,sizeof snumb.value);
        fnumb.sign=' ';
        snumb.sign=' ';
        symb=0;
        printw("Poprzedni wynik: %c%s\nAby uzyc wcisnij \"a\"\nAby skasowac wpisywana liczbe, wcisnij \"c\"\nAby zakonczyc program, wcisnij \"Q\"\n\n",result.sign,result.value);

        while(fnumb.end==0&&c!='Q')
        {
            c = getch();
            if(c=='c')
            {
                i=0;
                clearTab(fnumb.value,sizeof fnumb.value);
                fnumb.sign=' ';
                clear();
                printw("Poprzedni wynik: %c%s\nAby uzyc wcisnij \"a\"\nAby skasowac wpisywana liczbe, wcisnij \"c\"\nAby zakonczyc program, wcisnij \"Q\"\n\n",result.sign,result.value);
                print(fnumb,snumb,symb);
            }
            else
            {

                if(i==0&&c=='a')
                {
                    copy(result.value,fnumb.value);
                    fnumb.sign=result.sign;
                    print(fnumb,snumb,symb);
                    fnumb.end=1;

                    while(symb==0)
                    {
                        c = getch();

                        if(c=='c')
                        {
                            i=0;
                            fnumb.end=0;
                            clearTab(fnumb.value,sizeof fnumb.value);
                            fnumb.sign=' ';
                            clear();
                            printw("Poprzedni wynik: %c%s\nAby uzyc wcisnij \"a\"\nAby skasowac wpisywana liczbe, wcisnij \"c\"\nAby zakonczyc program, wcisnij \"Q\"\n\n",result.sign,result.value);
                            print(fnumb,snumb,symb);
                            break;
                        }
                        else
                        {
                            if(c=='-'||c=='*'||c=='+'||c=='!')
                            {
                                if(c=='!')
                                {
                                    printw("%c=",c);
                                }
                                else
                                {
                                    printw("%c",c);
                                }
                                break;
                            }
                            else
                            {
                                if(c=='Q')
                                {
                                    break;
                                }
                                else
                                {
                                    clear();
                                    printw("Poprzedni wynik: %c%s\nAby uzyc wcisnij \"a\"\nAby skasowac wpisywana liczbe, wcisnij \"c\"\nAby zakonczyc program, wcisnij \"Q\"\n\n",result.sign,result.value);
                                    attron( COLOR_PAIR( 1 ) ); //4

                                    printw("Bledny znak: %c\n",c);
                                    attroff( COLOR_PAIR( 1 ) );
                                    print(fnumb,snumb,symb);
                                }
                            }
                        }

                    }
                }
                else
                {
                    if(i==0&&c=='-')
                    {
                        fnumb.sign='-';
                        printw("%c",c);
                    }
                    if(i!=0&&(c=='-'||c=='*'||c=='+'||c=='!'))
                    {
                        fnumb.end=1;

                        if(c=='!')
                        {
                            printw("%c=",c);
                        }
                        else
                        {
                            printw("%c",c);
                        }
                        break;
                    }
                    else
                    {
                        if(c!='Q'&&c!='-'&&(c<'0'||c>'9'))
                        {
                            clear();
                            printw("Poprzedni wynik: %c%s\nAby uzyc wcisnij \"a\"\nAby skasowac wpisywana liczbe, wcisnij \"c\"\nAby zakonczyc program, wcisnij \"Q\"\n\n",result.sign,result.value);
                            attron( COLOR_PAIR( 1 ) ); //4
                            printw("Bledny znak: %c\n",c);
                            attroff( COLOR_PAIR( 1 ) );
                            print(fnumb,snumb,symb);

                        }

                        if((c>='0'&&c<='9')&&i<MAX&&(fnumb.value[0]!='0'))
                        {
                            fnumb.value[i]=c;
                            printw("%c",c);
                            i++;
                        }
                    }
                }
            }
        }
        symb=c;
        i=0;
        while(snumb.end==0&&c!='Q'&&symb!='!')
        {
            c = getch();
            if(c=='c')
            {
                i=0;
                clearTab(snumb.value,sizeof snumb.value);
                snumb.sign=' ';
                clear();
                printw("Poprzedni wynik: %c%s\nAby uzyc wcisnij \"a\"\nAby skasowac wpisywana liczbe, wcisnij \"c\"\nAby zakonczyc program, wcisnij \"Q\"\n\n",result.sign,result.value);
                print(fnumb,snumb,symb);

            }
            else
            {

                if(i==0&&c=='a')
                {
                    copy(result.value,snumb.value);
                    snumb.sign=result.sign;
                    clear();
                    printw("Poprzedni wynik: %c%s\nAby uzyc wcisnij \"a\"\nAby skasowac wpisywana liczbe, wcisnij \"c\"\nAby zakonczyc program, wcisnij \"Q\"\n\n",result.sign,result.value);
                    print(fnumb,snumb,symb);
                    printw("=");
                    snumb.end=1;
                }
                else
                {

                    if(i!=0&&c=='=')
                    {
                        snumb.end=1;
                        printw("=");
                        break;
                    }

                    if(i==0&&c=='-')
                    {
                        snumb.sign='-';
                        printw("%c",c);
                    }
                    else
                    {

                        if(c!='Q'&&(c<'0'||c>'9'))


                        {
                            clear();
                            printw("Poprzedni wynik: %c%s\nAby uzyc wcisnij \"a\"\nAby skasowac wpisywana liczbe, wcisnij \"c\"\nAby zakonczyc program, wcisnij \"Q\"\n\n",result.sign,result.value);
                            attron( COLOR_PAIR( 1 ) ); //4
                            printw("Bledny znak: %c\n",c);
                            attroff( COLOR_PAIR( 1 ) );
                            print(fnumb,snumb,symb);

                        }
                        {
                            if((c>='0'&&c<='9')&&i<MAX&&(snumb.value[0]!='0'))
                            {
                                snumb.value[i]=c;
                                printw("%c",c);
                                i++;
                            }
                        }
                    }
                }
            }
        }
        if(c!='Q')
        {
            if(symb=='-'&&snumb.sign=='-')
            {
                symb='+';
                snumb.sign=' ';
            }
            if(symb=='+'&&snumb.sign=='-')
            {
                symb='-';
                snumb.sign=' ';
            }
            switch(symb)
            {
                result.sign=' ';

            case '!':

                if(fnumb.sign=='-')
                {
                    attron( COLOR_PAIR( 1 ) );
                    printw("\nSilnia nie jest zdefiniowana dla liczb ujemnych.\n",MAX);
                    attroff( COLOR_PAIR( 1 ) );
                    copy("0",result.value);
                    result.sign=' ';
                }
                else
                {
                    result.sign=' ';
                    fac(fnumb.value);
                }
                break;

            case '+':
                if(fnumb.sign==snumb.sign)
                {
                    result.sign=fnumb.sign;
                    add(fnumb.value,snumb.value);
                    break;
                }
                else
                {
                    if(fnumb.sign=='-')
                    {
                        if (strlen(snumb.value)==strlen(fnumb.value))
                        {
                            if(strcmp(fnumb.value,snumb.value)>0)
                            {
                                sub(snumb.value,fnumb.value);
                                result.sign='-';
                                break;
                            }
                            else
                            {
                                sub(fnumb.value,snumb.value);
                                result.sign=' ';
                                break;
                            }
                        }

                        if (strlen(snumb.value)>strlen(fnumb.value))
                        {
                            sub(snumb.value,fnumb.value);
                            result.sign=' ';
                            break;
                        }
                        if(strlen(snumb.value)<strlen(fnumb.value))
                        {
                            sub(fnumb.value,snumb.value);
                            result.sign='-';
                            break;
                        }
                    }
                }

            case '*':
                if(fnumb.sign==snumb.sign)
                {
                    result.sign=' ';
                }
                else
                {
                    result.sign='-';
                }
                mul(fnumb.value,snumb.value);
                break;
            case '-':

                if(fnumb.sign=='-')
                {
                    result.sign='-';
                    add(fnumb.value,snumb.value);
                }
                else
                {

                    if (strlen(snumb.value)==strlen(fnumb.value))
                    {
                        if(strcmp(fnumb.value,snumb.value)<0)
                        {
                            sub(snumb.value,fnumb.value);
                            result.sign='-';
                            break;
                        }
                        else
                        {
                            sub(fnumb.value,snumb.value);
                            result.sign=' ';
                            break;
                        }
                    }

                    if (strlen(snumb.value)>strlen(fnumb.value))
                    {
                        sub(snumb.value,fnumb.value);
                        result.sign='-';
                        break;
                    }
                    if(strlen(snumb.value)<strlen(fnumb.value))
                    {
                        sub(fnumb.value,snumb.value);
                        break;
                    }
                }
            }
            if(result.value[0]=='0')
            {
                result.sign=' ';
            }
            attron( COLOR_PAIR( 2 ) );
            if(symb=='!')
            {
                printw("%s\n",result.value);
            }
            else
            {
                if(result.sign=='-')
                    printw("%c%s\n",result.sign, result.value);
                else
                    printw("%s\n", result.value);
            }
            attroff( COLOR_PAIR( 2 ) );
            printw("\nNacisnij dowolny klawisz.");
            getch();
            clear();
        }
    }
    endwin();
    return 0;
}

