#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    short bfType;
    int bfSize;
    short bfReserved1;
    short bfReserved2;
    short bfOffBits;
} FileHeader ;

typedef struct
{
short rgbBlue;
short rgbGreen;
short rgbRed;
short rgbReserved;
} RGBQUAD;

typedef struct
{
    int biSize;
    int biWidth;
    int biHeight;
    short biPlanes;
    short biBitCount;
    int biCompression;
    int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    int biClrUsed;
    int biClrImportant;
} PictureHeader;

typedef struct
{
    short R;
    short G;
    short B;
    short A;

} KoloryRGB ;

short padding;//padding ustalany w funkcjach odczytujacych pixele (padding - dopelnienie do wielokrotnosci 4 w kazdym wierszu)
PictureHeader Picture;//naglowek pliku
FileHeader File;//naglowek pliku, na ktorym pracuje
RGBQUAD pallette[256];

int compare( const int * arg1, const int * arg2 );//funkcja do qsort, uzywanego w funkcji mediana
int mediana(int liczby[],int rozmiar);//funkcja zwracajaca mediane nieposortowanej tablicy integer
int read_BMP_Header(char *bitmap);//funkcja odczytujaca naglowek pliku bmp, jesli uda sie go otworzyc przypisuje wartosci do struktur, jesli nie zwraca 0
int is_a_bmp(char* file_name);//funkcja sprawdza czy podany plik jest bitmapa 1) czy rozszerzenie to .bmp 2) czy zgadza sie typ pliku (pierwsze bity naglowka)
void** create_pixmap(int bits,int width, int height);//funkcja tworzaca dynamiczna, dwuwymiarowa tablice przygotowana do zapisu bitmapy 8,24 lub 32 bitowej
short** read_Bits8(char *bitmap,FileHeader File);//funkcja odczytujaca mape 8 bitowa - zapisuje ja w dwuwymiarowej tablicy dynamicznej
KoloryRGB** read_Bits24(char *bitmap,FileHeader File);// funkcja jak wyzej dla map 24 i 32 bitowej
void copy_Header(char *bitmap,char* nowy);//funkcja kopiuje naglowek pliku o nazwie podanej jako pierwszy argument do pliku o nazwie podanej jako drugi argument
void copy_Header8Sz(char *bitmap,char* nowy);//funkcja nie kopiuje palty kolorow
void write_Bits8(short** pixmap, char* nowy);//funkcja zapisuje tablice utworzona przez funkcje read_Bits8, podana jako pierwszy argument do pliku o nazwie podanej jako drugi argument
void write_Bits24(KoloryRGB** pixmap, char* nowy);//funkcja zapisuje tablice utworzona przez funkcje read_Bits24, podana jako pierwszy argument do pliku o nazwie podanej jako drugi argument

/*Ponizsze funkcje generuja kopie tablicy dwuwymiarowej wygenerowanej przez read_Bits8 lub read_Bits24
wykonujac odpowiednie operacje: negatyw, filtr usredniajacy, maxymalny, minimalny, medianowy
i konwersje na skale szarosci jako parametry przyjmuje oryginalna tablice oraz w przypadku filtrow wymiar maski filtrowania*/

short** negatyw8(short **pixmap);
short** filtrUs8(short **pixmap,int s);
short** filtrMax8(short **pixmap,int s);
short** filtrMin8(short **pixmap,int s);
short** filtrMed8(short **pixmap,int s);
void szary8(char *nowy);

KoloryRGB** szary24(KoloryRGB **pixmap);
KoloryRGB** negatyw24(KoloryRGB **pixmap);
KoloryRGB** filtrMax24(KoloryRGB **pixmap,int s);
KoloryRGB** filtrMin24(KoloryRGB **pixmap,int s);
KoloryRGB** filtrMed24(KoloryRGB **pixmap,int s);
KoloryRGB** filtrUs24(KoloryRGB **pixmap,int s);

int main()
{
    int a =0;
    char* plik;
    while(a==0)
    {
        char nazwa[100];
        printf("Podaj plik bmp:\n");
        scanf("%100s",nazwa);
        plik = nazwa;
        a = is_a_bmp(plik);
        if(a==0)
            printf("%s","Ten plik nie istnieje.\n");
        else printf("%s","Wczytano poprawny plik.\n\n");
    }
    int s;

    if(Picture.biBitCount==24||Picture.biBitCount==32)
    {
        printf("Podaj rozmiar maski filtrow:\n");
        scanf("%d",&s);
        KoloryRGB** pixmap = (KoloryRGB**)read_Bits24(plik,File);

        copy_Header(plik,"24Szary.bmp");
        write_Bits24(szary24(pixmap),"24Szary.bmp");

        copy_Header(plik,"24Negatyw.bmp");
        write_Bits24(negatyw24(pixmap),"24Negatyw.bmp");

        copy_Header(plik,"24FiltrUs.bmp");
        write_Bits24(filtrUs24(pixmap,s),"24FiltrUs.bmp");

        copy_Header(plik,"24FiltrMax.bmp");
        write_Bits24(filtrMax24(pixmap,s),"24FiltrMax.bmp");

        copy_Header(plik,"24FiltrMin.bmp");
        write_Bits24(filtrMin24(pixmap,s),"24FiltrMin.bmp");

        copy_Header(plik,"24FiltrMed.bmp");
        write_Bits24(filtrMed24(pixmap,s),"24FiltrMed.bmp");
    }else

    if(Picture.biBitCount==8)
    {
        printf("Podaj rozmiar maski:\n");
        scanf("%d",&s);
        short** pixmap = read_Bits8(plik,File);

        copy_Header(plik,"8Negatyw.bmp");
        write_Bits8(negatyw8(pixmap),"8Negatyw.bmp");

        copy_Header(plik,"8FiltrUs.bmp");
        write_Bits8(filtrUs8(pixmap,s),"8FiltrUs.bmp");

        copy_Header8Sz(plik,"8FiltrSz.bmp");
        szary8("8FiltrSz.bmp");
        write_Bits8(pixmap,"8FiltrSz.bmp");

        copy_Header(plik,"8FiltrMax.bmp");
        write_Bits8(filtrMax8(pixmap,s),"8FiltrMax.bmp");

        copy_Header(plik,"8FiltrMin.bmp");
        write_Bits8(filtrMin8(pixmap,s),"8FiltrMin.bmp");

        copy_Header(plik,"8FiltrMed.bmp");
        write_Bits8(filtrMed8(pixmap,s),"8FiltrMed.bmp");
    }else{
    printf("Program nie obsluguje map %d bitowych.\nObslugiwane mapy to 8,24 i 32 bitowe.\n",Picture.biBitCount);
    }


    return 0;
}

void** create_pixmap(int bits,int width, int height)
{
    if (bits == 8)
    {
        short** pixmap;
        pixmap = (short **)malloc(sizeof(short*) * height);
        int i;
        for(i = 0; i < height; i++)
            pixmap[i] = (short*)malloc(sizeof(short) * width);
        printf("Create8\n");
        return (void**)pixmap;
    }

    if(bits == 24 || bits == 32)
    {
        KoloryRGB** pixmap;
        pixmap = malloc(sizeof(KoloryRGB*) * height);
        int i;
        for(i = 0; i < height; i++)
            pixmap[i] = (KoloryRGB*)malloc(sizeof(KoloryRGB) * width);
        return (void**)pixmap;
    }
return (void**)0;
}

int compare( const int * arg1, const int * arg2 )
{
    if( * arg1 <* arg2 )
        return - 1;
    if( * arg1 >* arg2 )
        return 1;
    return 0;
}
int mediana(int liczby[],int rozmiar)
{
    qsort(liczby,rozmiar,sizeof liczby[0],( int( * )( const void *, const void * ) ) compare);
    if(rozmiar%2!=0)
        return liczby[rozmiar/2];
    else return (liczby[rozmiar/2]+liczby[rozmiar/2-1])/2;
}

int read_BMP_Header(char *bitmap)
{
    FILE *f = fopen(bitmap,"rb");
    if(f==NULL) return 0;


    printf("\nINFORMACJE O BITMAPIE\n\n");

    fread(&File.bfType,sizeof(File.bfType),1,f);
    printf(" Typ: %x",File.bfType);

    fread(&File.bfSize,sizeof(File.bfSize),1,f);
    printf("\n Rozmiar pliku: %d bajtow",File.bfSize);

    fread(&File.bfReserved1,sizeof(File.bfReserved1),1,f);
    //printf("\n Zarezerwowane1: %d",File.bfReserved1);

    fread(&File.bfReserved2,sizeof(File.bfReserved2),1,f);
    //printf("\n Zarezerwowane2: %d",File.bfReserved2);

    fread(&File.bfOffBits,sizeof(File.bfOffBits),1,f);
    printf("\n Pozycja danych obrazkowych: %d",File.bfOffBits);

    printf("\n");

    fseek(f,14,0);
    fread(&Picture.biSize,sizeof(Picture.biSize),1,f);
    printf("\n Wielkosc naglowka informacyjnego: %d",Picture.biSize);

    fread(&Picture.biWidth,sizeof(Picture.biWidth),1,f);
    printf("\n Szerokosc: %d pikseli",Picture.biWidth);

    fread(&Picture.biHeight,sizeof(Picture.biHeight),1,f);
    printf("\n Wysokosc: %d pikseli",Picture.biHeight);

    fread(&Picture.biPlanes,sizeof(Picture.biPlanes),1,f);
    //printf("\n Liczba platow (zwykle 0): %d",Picture.biPlanes);

    fread(&Picture.biBitCount,sizeof(Picture.biBitCount),1,f);
    printf("\n Liczba bitow na piksel: %d",Picture.biBitCount);

    fread(&Picture.biCompression,sizeof(Picture.biCompression),1,f);
    //printf("\n Kompresja: %d (0=none, 1=RLE-8, 2=RLE-4)",Picture.biCompression);

    fread(&Picture.biSizeImage,sizeof(Picture.biSizeImage),1,f);
    //printf("\n Rozmiar samego rysunku: %d",Picture.biSizeImage);

    fread(&Picture.biXPelsPerMeter,sizeof(Picture.biXPelsPerMeter),1,f);
    //printf("\n Rozdzielczosc pozioma: %d",Picture.biXPelsPerMeter);

    fread(&Picture.biYPelsPerMeter,sizeof(Picture.biYPelsPerMeter),1,f);
    //printf("\n Rozdzielczosc pionowa: %d",Picture.biYPelsPerMeter);

    fread(&Picture.biClrUsed,sizeof(Picture.biClrUsed),1,f);
    printf("\n Liczba kolorow w palecie: %d",Picture.biClrUsed);

    fread(&Picture.biClrImportant,sizeof(Picture.biClrImportant),1,f);
    printf("\n Wazne kolory w palecie: %d\n\n",Picture.biClrImportant);

    if(Picture.biBitCount==8){//odczytanie palety kolorow dla 8 bitowej mapy
    fseek(f, 14+Picture.biSize, SEEK_SET);
    int i;
    for(i=0;i<=255;i++){
    pallette[i].rgbBlue=fgetc(f);
    pallette[i].rgbGreen=fgetc(f);
    pallette[i].rgbRed=fgetc(f);
    pallette[i].rgbReserved=fgetc(f);
    printf("%d) - %d %d %d\n",i,pallette[i].rgbBlue, pallette[i].rgbGreen, pallette[i].rgbRed);
    }
    }

    fclose(f);

    return 1;

}

short** read_Bits8(char *bitmap,FileHeader File)
{
    FILE *f = fopen(bitmap,"rb");
    fseek(f,File.bfOffBits,0);
    padding = (Picture.biWidth)%4 ? 4-(Picture.biWidth)%4 : 0;
    printf("Padding: %d\n",padding);
    short** pixmap = (short**)create_pixmap(Picture.biBitCount,Picture.biWidth,Picture.biHeight);
    int i;
    int j;
    fseek(f, File.bfOffBits,SEEK_SET);
    for(i = 0; i < Picture.biHeight; i++, fseek(f, padding, SEEK_CUR))
    {
        for(j = 0; j < Picture.biWidth; j++)
        {
            pixmap[i][j] = fgetc(f);
        }
    }
    printf("Przeczytane\n");
    fclose(f);
    return pixmap;

}

KoloryRGB** read_Bits24(char *bitmap,FileHeader File)
{
    FILE *f = fopen(bitmap,"rb");
    fseek(f,File.bfOffBits,0);
    if(Picture.biBitCount==24)
        padding = (Picture.biWidth*3)%4 ? 4-(Picture.biWidth*3)%4 : 0;
    if(Picture.biBitCount==32)
        padding = 0;
    if(Picture.biBitCount==16)
        padding = (Picture.biWidth*2)%4 ? 4-(Picture.biWidth*2)%4 : 0;
    printf("Padding: %d\n",padding);
    KoloryRGB** pixmap = (KoloryRGB**)create_pixmap(Picture.biBitCount,Picture.biWidth,Picture.biHeight);
    int i;
    int j;
    fseek(f, File.bfOffBits,SEEK_SET);
    for(i = 0; i < Picture.biHeight; i++, fseek(f, padding, SEEK_CUR))
    {
        for(j = 0; j < Picture.biWidth; j++)
        {
            if(Picture.biBitCount==24)
            {
                pixmap[i][j].B = fgetc(f);
                pixmap[i][j].G = fgetc(f);
                pixmap[i][j].R = fgetc(f);
            }
            if(Picture.biBitCount==32)
            {
                pixmap[i][j].B = fgetc(f);
                pixmap[i][j].G = fgetc(f);
                pixmap[i][j].R = fgetc(f);
                pixmap[i][j].A = fgetc(f);
            }
        }
    }
    printf("Przeczytane. \n");
    fclose(f);
    return pixmap;

}

int is_a_bmp(char* file_name)
{
    char *cc;
    int result = 0;
    cc = strstr(file_name, ".bmp");
    if(cc == NULL)
        return(result);
    read_BMP_Header(file_name);
    if(File.bfType != 0x4d42)
        return(result);
    result = 1;
    return(result);
}

void copy_Header(char *bitmap,char* nowy)
{
    FILE* fn, *fb;
    fn = fopen(nowy,"wt");
    fb = fopen(bitmap,"rb");
    int i;
    fseek(fb, 0, SEEK_SET);
    fseek(fn, 0, SEEK_SET);
    for(i=0; i<File.bfOffBits; i++)
        fputc(fgetc(fb), fn);
    printf("Skopiowany header\n");
}

void copy_Header8Sz(char *bitmap,char* nowy)
{
    FILE* fn, *fb;
    fn = fopen(nowy,"wt");
    fb = fopen(bitmap,"rb");
    int i;
    fseek(fb, 0, SEEK_SET);
    fseek(fn, 0, SEEK_SET);
    for(i=0; i<14+Picture.biSize; i++)
        fputc(fgetc(fb), fn);
    printf("Skopiowany headerSz\n");
}

void write_Bits8(short** pixmap, char* nowy)
{
    FILE* fn;
    fn = fopen(nowy,"wb");
    fseek(fn, File.bfOffBits, SEEK_SET);
    int i;
    int j;
    for(i = 0; i < Picture.biHeight; i++)
    {
        for(j = 0; j < Picture.biWidth; j++)
        {
            fputc(pixmap[i][j], fn);
        }
        int k;
        for(k=0; k<padding; k++)
            fputc(0, fn);
    }
    fclose(fn);
    printf("Wpisane\n");
}

void write_Bits24(KoloryRGB** pixmap, char* nowy)
{
    FILE* fn;
    fn = fopen(nowy,"wb");
    fseek(fn, File.bfOffBits, SEEK_SET);
    int i;
    int j;
    for(i = 0; i < Picture.biHeight; i++)
    {
        for(j = 0; j < Picture.biWidth; j++)
        {
            if(Picture.biBitCount==24)
            {
                fputc(pixmap[i][j].B, fn);
                fputc(pixmap[i][j].G, fn);
                fputc(pixmap[i][j].R, fn);
            }
            if(Picture.biBitCount==32)
            {
                fputc(pixmap[i][j].B, fn);
                fputc(pixmap[i][j].G, fn);
                fputc(pixmap[i][j].R, fn);
                fputc(pixmap[i][j].A, fn);
            }

        }
        int k;
        for(k=0; k<padding; k++)
            fputc(0, fn);
    }
    fclose(fn);
    printf("Wpisane\n");
}

short** negatyw8(short **pixmap)
{
    short** pixmap1 = (short**)create_pixmap(Picture.biBitCount,Picture.biWidth,Picture.biHeight);
    int i, j;
    for(i = 0; i < Picture.biHeight; i++)
    {
        for(j = 0; j < Picture.biWidth; j++)
        {
            pixmap1[i][j] = 255 - pixmap[i][j];
        }
    }
    printf("Negatyw8\n");
    return pixmap1;
}

short** filtrUs8(short **pixmap,int s)
{
    short** pixmap1 = (short**)create_pixmap(Picture.biBitCount,Picture.biWidth,Picture.biHeight);
    int i, j;
    for(i = s/2; i < Picture.biHeight-s/2; i++)
    {
        for(j = s/2; j < Picture.biWidth-s/2; j++)
        {
            int a;
            int b;
            for (a=0; a<s; a++)
            {
                for (b=0; b<s; b++)
                {
                    pixmap1[i][j] = pixmap1[i][j]+pixmap[i+a-s/2][j+b-s/2];
                }
            }
            pixmap1[i][j]=pixmap1[i][j]/(s*s);
        }
    }
    printf("FiltrUs8\n");
    return pixmap1;
}

void szary8(char* nowy)
{
    FILE* fn = fopen(nowy,"wb");
    fseek(fn, 14+Picture.biSize, SEEK_SET);
    int i;
    for(i=0;i<=255;i++){
    pallette[i].rgbBlue=pallette[i].rgbGreen=pallette[i].rgbRed=((0.229*pallette[i].rgbRed)+(0.587*pallette[i].rgbGreen)+(0.114*pallette[i].rgbBlue));
    fputc(pallette[i].rgbBlue,fn);
    fputc(pallette[i].rgbGreen,fn);
    fputc(pallette[i].rgbRed,fn);
    fputc(pallette[i].rgbReserved,fn);
    printf("%d) - %d %d %d\n",i,pallette[i].rgbBlue, pallette[i].rgbGreen, pallette[i].rgbRed);
    }
}

short** filtrMax8(short **pixmap,int s)
{
    short** pixmap1 = (short**)create_pixmap(Picture.biBitCount,Picture.biWidth,Picture.biHeight);
    int i, j;
    for(i = s/2; i < Picture.biHeight-s/2; i++)
    {
        for(j = s/2; j < Picture.biWidth-s/2; j++)
        {
            int a;
            int b;
            for (a=0; a<s; a++)
            {
                for (b=0; b<s; b++)
                {
                    pixmap1[i][j] = (pixmap1[i][j] < pixmap[i+a-s/2][j+b-s/2]) ? pixmap[i+a-s/2][j+b-s/2] : pixmap1[i][j];
                }
            }
        }
    }
    printf("FiltrMax8\n");
    return pixmap1;
}

short** filtrMin8(short **pixmap,int s)
{
    short** pixmap1 = (short**)create_pixmap(Picture.biBitCount,Picture.biWidth,Picture.biHeight);
    int i, j;
    for(i = s/2; i < Picture.biHeight-s/2; i++)
    {
        for(j = s/2; j < Picture.biWidth-s/2; j++)
        {
            int a;
            int b;
            for (a=0; a<s; a++)
            {
                for (b=0; b<s; b++)
                {
                    pixmap1[i][j] = (pixmap1[i][j] > pixmap[i+a-s/2][j+b-s/2]) || (pixmap1[i][j]==0) ? pixmap[i+a-s/2][j+b-s/2] : pixmap1[i][j];
                }
            }
        }
    }
    printf("FiltrMin8\n");
    return pixmap1;
}

short** filtrMed8(short **pixmap,int s)
{

    short** pixmap1 = (short**)create_pixmap(Picture.biBitCount,Picture.biWidth,Picture.biHeight);
    int i, j;
    for(i = s/2; i < Picture.biHeight-s/2; i++)
    {
        for(j = s/2; j < Picture.biWidth-s/2; j++)
        {
            int a;
            int b;
            int c=0;
            int tab[s*s];
            for (a=0; a<s; a++)
            {
                for (b=0; b<s; b++)
                {
                    tab[c]=pixmap[i+a-s/2][j+b-s/2];
                    c++;
                }
            }
            pixmap1[i][j]=mediana(tab,s*s);
        }
    }
    printf("FiltrMed8\n");
    return pixmap1;
}

KoloryRGB** filtrMax24(KoloryRGB **pixmap,int s)
{
    KoloryRGB** pixmap1 = (KoloryRGB**)create_pixmap(Picture.biBitCount,Picture.biWidth,Picture.biHeight);
    int i, j;
    for(i = s/2; i < Picture.biHeight-s/2; i++)
    {
        for(j = s/2; j < Picture.biWidth-s/2; j++)
        {
            int a;
            int b;
            for (a=0; a<s; a++)
            {
                for (b=0; b<s; b++)
                {
                    pixmap1[i][j].R = (pixmap1[i][j].R < pixmap[i+a-s/2][j+b-s/2].R) ? pixmap[i+a-s/2][j+b-s/2].R : pixmap1[i][j].R;
                    pixmap1[i][j].G = (pixmap1[i][j].G < pixmap[i+a-s/2][j+b-s/2].G) ? pixmap[i+a-s/2][j+b-s/2].G : pixmap1[i][j].G;
                    pixmap1[i][j].B = (pixmap1[i][j].B < pixmap[i+a-s/2][j+b-s/2].B) ? pixmap[i+a-s/2][j+b-s/2].B : pixmap1[i][j].B;
                    pixmap1[i][j].A = pixmap[i][j].A;
                }
            }
        }
    }
    printf("FiltrMax24\n");
    return pixmap1;
}

KoloryRGB** filtrMin24(KoloryRGB **pixmap,int s)
{
    KoloryRGB** pixmap1 = (KoloryRGB**)create_pixmap(Picture.biBitCount,Picture.biWidth,Picture.biHeight);
    int i, j;
    for(i = s/2; i < Picture.biHeight-s/2; i++)
    {
        for(j = s/2; j < Picture.biWidth-s/2; j++)
        {
            int a, b;
            for (a=0; a<s; a++)
            {
                for (b=0; b<s; b++)
                {
                    pixmap1[i][j].R = ((pixmap1[i][j].R > pixmap[i+a-s/2][j+b-s/2].R))||(pixmap1[i][j].R==0)? pixmap[i+a-s/2][j+b-s/2].R : pixmap1[i][j].R;
                    pixmap1[i][j].G = ((pixmap1[i][j].G > pixmap[i+a-s/2][j+b-s/2].G))||(pixmap1[i][j].G==0)? pixmap[i+a-s/2][j+b-s/2].G : pixmap1[i][j].G;
                    pixmap1[i][j].B = ((pixmap1[i][j].B > pixmap[i+a-s/2][j+b-s/2].B))||(pixmap1[i][j].B==0)? pixmap[i+a-s/2][j+b-s/2].B : pixmap1[i][j].B;
                    pixmap1[i][j].A = pixmap[i][j].A;
                }
            }
        }
    }
    printf("FiltrMin24\n");
    return pixmap1;
}

KoloryRGB** filtrUs24(KoloryRGB **pixmap,int s)
{
    KoloryRGB** pixmap1 = (KoloryRGB**)create_pixmap(Picture.biBitCount,Picture.biWidth,Picture.biHeight);
    int i, j;
    for(i = s/2; i < Picture.biHeight-s/2; i++)
    {
        for(j = s/2; j < Picture.biWidth-s/2; j++)
        {
            int a;
            int b;
            for (a=0; a<s; a++)
            {
                for (b=0; b<s; b++)
                {
                    pixmap1[i][j].R = pixmap1[i][j].R+pixmap[i+a-s/2][j+b-s/2].R;
                    pixmap1[i][j].G = pixmap1[i][j].G+pixmap[i+a-s/2][j+b-s/2].G;
                    pixmap1[i][j].B = pixmap1[i][j].B+pixmap[i+a-s/2][j+b-s/2].B;
                }
            }
            pixmap1[i][j].R=pixmap1[i][j].R/(s*s);
            pixmap1[i][j].B=pixmap1[i][j].B/(s*s);
            pixmap1[i][j].G=pixmap1[i][j].G/(s*s);
            pixmap1[i][j].A = pixmap[i][j].A;
        }
    }
    printf("FiltrUs24\n");
    return pixmap1;
}

KoloryRGB** filtrMed24(KoloryRGB **pixmap,int s)
{
    KoloryRGB** pixmap1 = (KoloryRGB**)create_pixmap(Picture.biBitCount,Picture.biWidth,Picture.biHeight);
    int i, j;
    for(i = s/2; i < Picture.biHeight-s/2; i++)
    {
        for(j = s/2; j < Picture.biWidth-s/2; j++)
        {
            int a;
            int b;
            int c=0;
            int tabR[s*s],tabB[s*s],tabG[s*s];
            for (a=0; a<s; a++)
            {
                for (b=0; b<s; b++)
                {
                    tabR[c]=pixmap[i+a-s/2][j+b-s/2].R;
                    tabG[c]=pixmap[i+a-s/2][j+b-s/2].G;
                    tabB[c]=pixmap[i+a-s/2][j+b-s/2].B;
                    c++;
                }
            }
            pixmap1[i][j].R=mediana(tabR,s*s);
            pixmap1[i][j].G=mediana(tabG,s*s);
            pixmap1[i][j].B=mediana(tabB,s*s);
            pixmap1[i][j].A = pixmap[i][j].A;
        }
    }
    printf("FiltrMed24\n");
    return pixmap1;
}

KoloryRGB** szary24(KoloryRGB **pixmap)
{
    KoloryRGB** pixmap1 = (KoloryRGB**)create_pixmap(Picture.biBitCount,Picture.biWidth,Picture.biHeight);
    int i, j;
    for(i = 0; i < Picture.biHeight; i++)
    {
        for(j = 0; j < Picture.biWidth; j++)
        {
            if(Picture.biBitCount==24||Picture.biBitCount==32)
            {
                pixmap1[i][j].B = pixmap1[i][j].G = pixmap1[i][j].R = 0.229*pixmap[i][j].R + 0.587*pixmap[i][j].G + 0.114*pixmap[i][j].B;
                pixmap1[i][j].A = pixmap[i][j].A;
            }
        }
    }
    printf("Szary24\n");
    return pixmap1;
}

KoloryRGB** negatyw24(KoloryRGB **pixmap)
{
    KoloryRGB** pixmap1 = (KoloryRGB**)create_pixmap(Picture.biBitCount,Picture.biWidth,Picture.biHeight);
    int i, j;
    for(i = 0; i < Picture.biHeight; i++)
    {
        for(j = 0; j < Picture.biWidth; j++)
        {
            if(Picture.biBitCount == 24 || Picture.biBitCount == 32)
            {
                pixmap1[i][j].B = 255 - pixmap[i][j].B;
                pixmap1[i][j].G = 255 - pixmap[i][j].G;
                pixmap1[i][j].R = 255 - pixmap[i][j].R;
                pixmap1[i][j].A = pixmap[i][j].A;
            }
        }
    }
    printf("Negatyw24\n");
    return pixmap1;
}




