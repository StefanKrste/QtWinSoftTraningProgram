#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(){

    //1. Во програмот p05_02.c смести ја иницијализацијата на променливата sum во заглавието на наредбата for.

//    int number;
//
//    for ( int sum = 0, number = 2; number <= 100; number += 2 ) {
//        sum += number;
//        if(number==100) {
//            printf("Sumata e %d\n", sum);
//        }
//    }

    //2. Програмот p05_03.c преработи го така да колонската репрезентација на вредностите на депозитот за секоја година биде порамнет одлево.

//    double amount;
//    double principal = 1000.0;
//    double rate = .05;
//    int year;
//
//    printf( "%4s%25s\n", "Godina", "Vrednost na depozitot" );
//
//    for ( year = 1; year <= 10; year++ ) {
//        amount = principal * pow( 1.0 + rate, year );
//        printf( "%-4d%13.2f\n", year, amount );
//    }

    //3. Програмот p05_03.c преработи го така да колонската репрезентација на вредностите на депозитот за секоја година биде порамнет одлево.

//    int a, b;
//    float c;
//
//    for (a = 1; a <= 100; a++) {
//        for (b = a; b <= 100; b++) {
//            c = sqrt(a * a + b * b);
//            if (c <= 100) {
//                printf("%d^2 + %d^2 = %0.2f^2\n", a, b, c);
//            }
//        }
//    }

    //4. Напиши програма која за внесен цел број кој може да е најмногу  четири цифрен го испечатува неговиот еквивалент во римски броеви.

//    int broj,iljadarki,stotki,desetki,edinici;
//    bool t = true;
//    printf("Vnesete cel broj pomal od 10000: ");
//    while (t) {
//        scanf("%d", &broj);
//        if(broj<10000 && broj>0){
//            t=false;
//        }else{
//            printf("Greska, Vnesete povtorno cel broj pomal od 10000: ");
//        }
//    }
//
//    iljadarki = broj / 1000;
//    stotki = (broj / 100) % 10;
//    desetki = (broj / 10) % 10;
//    edinici = broj % 10;
//
//    for (int i = 1; i <= iljadarki; i++) {
//        printf("M");
//    }
//
//    //moze da se poednostavi so funkcija
//    if (stotki == 9) {
//        printf("CM");
//    } else if (stotki >= 5) {
//        printf("D");
//        for (int i = 6; i <= stotki; i++) {
//            printf("C");
//        }
//    } else if (stotki == 4) {
//        printf("CD");
//    } else {
//        for (int i = 1; i <= stotki; i++) {
//            printf("C");
//        }
//    }
//
//    if (desetki == 9) {
//        printf("XC");
//    } else if (desetki >= 5) {
//        printf("L");
//        for (int i = 6; i <= desetki; i++) {
//            printf("X");
//        }
//    } else if (desetki == 4) {
//        printf("XL");
//    } else {
//        for (int i = 1; i <= desetki; i++) {
//            printf("X");
//        }
//    }
//
//    if (edinici == 9) {
//        printf("IX");
//    } else if (edinici >= 5) {
//        printf("V");
//        for (int i = 6; i <= edinici; i++) {
//            printf("I");
//        }
//    } else if (edinici == 4) {
//        printf("IV");
//    } else {
//        for (int i = 1; i <= edinici; i++) {
//            printf("I");
//        }
//    }

    //5. Напиши програм во кој контролата на циклусот на броево од 1 до 100 го прави for наредба. Во рамките на наредбата for треба да се испечати коментар дека бројот не е делив со три. Доколку бројот е делив со три, не е печати никаков коментар. Задачата да се реши со користење на наредбата continue. Пример, задачата треба да печати:
    //1 ne e deliv so 3
    //2 ne e deliv so 3
    //4 ne e deliv so 3
    //...
    //100 ne e deliv so 3

//    for (int i = 1; i <= 100; i++) {
//         if (i%3==0){
//             continue;
//         } else{
//             printf("%d ne e deliv so 3\n", i);
//         }
//    }

    return 0;
}