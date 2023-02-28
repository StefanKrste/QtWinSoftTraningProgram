#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int paren (int broj);
int vreme (int casovi, int min, int  sek);
int obratno(int broj);
int nzd(int br1,int br2);
long fibonacci( long n );
int nzdRek(int br1,int br2, int del);
int dzvezdi(int n);


int main(){

    //1. Напиши програма која внесува 10 цели броеви и и ги доделува на функцијата paren која враќа 1 ако бројот е парен и 0 ако бројот не е парен.

//    int broj[10];
//    for(int i=0; i<10 ; i++){
//        scanf("%d",&broj[i]);
//        paren(broj[i]);
//    }

    //2. Напиши програма која на функцијата vreme и доделува три целобројни аргументи, час, минута и секунда и како резултат го враќа бројот на секунди до 12 часот. Имено, ако е 11 часот 59 минути и 58 секунди, тогаш има уште 2 секунди до 12 часот.

//    int casovi,min,sek;
//
//    scanf("%d%d%d",&casovi,&min,&sek);
//    printf("%d",vreme(casovi,min,sek));

    //3. Напиши програма која на функцијата obratno и доделува цел број. Оваа функција го враќа бројот напишан со обратни цифри, т.е. ако сме ја повикале функцијата со параметарот 1243, треба да врати 3421.

//    int broj;
//
//    scanf("%d",&broj);
//    printf("%d",obratno(broj));

    //4. Напиши програма во која дефинираш функција nzd за пресметување на најголемиот заеднички делител на два броја.

//    int br1,br2;
//
//    scanf("%d%d",&br1,&br2);
//    printf("NZD e: %d", nzd(br1,br2));

    //5. Напиши итеративна верзија на функцијата за фибоначиеви броеви.

//    long rez, broj;
//
//    printf( "Vnesi cel broj: " );
//    scanf( "%ld", &broj );
//
//    for(int i=0;i<=broj;i++)
//    {
//        rez = fibonacci( i );
//        printf( "%ld, ", rez );
//    }

    //6. Напиши рекурзивна верзија на функцијата за пресметување најголем заеднички делител.

//    int br1,br2,del;
//
//    scanf("%d%d",&br1,&br2);
//    if(br1>br2){
//        del = br1;
//    } else{
//        del = br2;
//    }
//    printf("NZD e: %d", nzdRek(br1,br2,del));

    //7. Напиши рекурзивна верзија на програма која за внесено n повикува функција dzvezdi со параметар n која во зависност од n испечатува ѕвезди на следниот начин:
    //    Vnesi broj na dzvezdi (n): 5
    //    Se dobiva:
    //    * * * * *
    //    * * * *
    //    * * *
    //    * *
    //    *

//    int n;
//    scanf("%d", &n);
//    dzvezdi(n);

    return 0;
}

int paren (int broj){
    if(broj%2==0){
        return 1;
    } else{
        return 0;
    }
}

int vreme (int casovi, int min, int  sek){
    if (casovi<12) {
        return (11 - casovi) * 3600 + (59 - min) * 60 + (60 - sek);
    } else{
        return 43200+(23 - casovi) * 3600 + (59 - min) * 60 + (60 - sek);
    }
}

int obratno(int broj){
    int invBroj;
    while (broj!=0) {
        invBroj = broj%10 + invBroj*10;
        broj/=10;
    }
    return invBroj;
}

int nzd(int br1,int br2){
    if(br1>br2){
        for(int i=br1 ; i>0 ; i--){
            if(br1%i==0 && br2%i==0){
                return i;
            }
        }
    } else{
        for(int i=br2 ; i>0 ; i--){
            if(br1%i==0 && br2%i==0){
                return i;
            }
        }
    }
}

long fibonacci( long f ){
    if ( f == 0 || f == 1 ) {
        return f;
    }
    else {
        return fibonacci( f - 1 ) + fibonacci( f - 2 );
    }
}

int nzdRek(int br1,int br2, int del){
    if(br1%del==0 && br2%del==0){
        return del;
    } else {
        nzdRek(br1,br2,del-1);
    }
}

int dzvezdi(int n){
    for(int i=n; i>0; i--){
        printf("* ");
    }
    printf("\n");
    if(n==1){
        return 0;
    } else{
        dzvezdi(n-1);
    }
}