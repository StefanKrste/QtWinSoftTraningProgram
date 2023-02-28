#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int mnoziSoStepenOdDva(int broj, int stepen) {
    return broj << stepen;
}

unsigned prevrtiBitovi(unsigned broj) {
    unsigned int prevrtenBroj = 0;

    for (int i = 0; i < sizeof(broj) * 8; i++) {
        prevrtenBroj <<= 1;
        prevrtenBroj |= broj & 1;
        broj >>= 1;
    }

    return prevrtenBroj;
}

void ispecatiBitovi(unsigned broj){
    for(int i = sizeof(broj) * 8 - 1; i >= 0; i--) {
        printf("%d", (broj >> i) & 1);
    }
    printf("\n");
}

int misterija( unsigned bitovi )
{
    unsigned i;
    unsigned maska = 1 << 31;
    unsigned total = 0;

    for ( i = 1; i <= 32; i++, bitovi <<= 1 ) {
        if ( ( bitovi & maska ) == maska ) {
            total++;
        }
    }
    return !( total % 2 ) ? 1 : 0;
}

int main(){

    //1 Само со користење на операторот за шифтирање да се напише функција mnoziSoStepenOdDva која зема два целобројни аргументи: broj и stepen и ја пресметува следната вредност:
    //broj * 2^stepen;

//    int broj, stepen;
//    printf("Vnesete go brojot koj go mnozi 2^stepen: ");
//    scanf("%d", &broj);
//    printf("Vnesete go stepenot: ");
//    scanf("%d", &stepen);
//    printf("Rezultatot e: %d",mnoziSoStepenOdDva(broj,stepen));

    //2 Напиши програм кој го превртува редоследот на битовите на целобројна unsigned вредност. Програмот треба да вчита вредност од корисникот и да ја повика функцијата prevtriBitovi за да се испечатат битовите во обратен редослед. Вредностите на битовите да се испечатат и пред и после превртувањето.

//    unsigned broj;
//    printf("Vnesete broj: ");
//    scanf("%u", &broj);
//
//    ispecatiBitovi(broj);
//    ispecatiBitovi(prevrtiBitovi(broj));

    //3 Да се открие и опише што работи следниот програм?

//    unsigned x;
//    printf( "Vnesi cel broj: " );
//    scanf( "%u", &x );
//    printf( "Rezultatot e %d\n", misterija( x ) );

    //Broj kolku pati maskata i bitovite&maskata ke bidat ednakvi, dokolku e paren broj rezultatot e 1 vo sprotivno 0

    return 0;
}
