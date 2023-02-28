#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(){

    //1. Напиши програм кој конвертира целобројни фарантхајтови температури од 0-212 степени во децимални цезлиусови температури со 3 цифри прецизност. Да се користи формулата:
    //celsius = 5.0 /9.0 * (fahrenheit - 32).
    //Излезот да се испечати во две десно порамнети колони од по 10 карактери, а целзиусовите вредности треба да се предводени од знак и за позитивни и за негативни вредности.

//    int fahrenheit;
//    float celsius;
//    printf("Vnesete temperatura vo fahrenheit: ");
//    scanf("%d", &fahrenheit);
//    if(fahrenheit>=0 && fahrenheit<=212){
//        celsius = 5.0 /9.0 * (fahrenheit - 32);
//        printf("\n%+*.*f", 10, 3, celsius);
//    }else {
//        printf("Pogreshen vlez");
//    }

    //2. Напиши програма која вчитува датуми во облик gg/mm/dd, gg-mm-dd и gg+mm+dd и ги испечаува така да наместо бројот на месецот се испечати имато на месецот.
    //Пример:
    //Vnesi datum: 2005+06+01
    //Vneseniot datum e 1 juni 2005 godina.

//    int god, mesec, den;
//    printf( "Vnesi datum: " );
//    scanf( "%d%*c%d%*c%d", &god, &mesec, &den );
//    printf("Vneseniot datum e %d ",den);
//    switch (mesec) {
//        case 1:
//            printf("januari");
//            break;
//        case 2:
//            printf("fevruari");
//            break;
//        case 3:
//            printf("mart");
//            break;
//        case 4:
//            printf("april");
//            break;
//        case 5:
//            printf("maj");
//            break;
//        case 6:
//            printf("juni");
//            break;
//        case 7:
//            printf("juli");
//            break;
//        case 8:
//            printf("avgust");
//            break;
//        case 9:
//            printf("septemvri");
//            break;
//        case 10:
//            printf("oktomvri");
//            break;
//        case 11:
//            printf("noembvri");
//            break;
//        case 12:
//            printf("dekemvri");
//            break;
//    }
//    printf(" %d godina.",god);

    return 0;
}