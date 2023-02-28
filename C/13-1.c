#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct listNode {
    int broj;
    char karakter;
    struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void vnesi( ListNodePtr *sPtr, char karakter, int broj ){
    ListNodePtr newPtr;
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;

    newPtr = malloc( sizeof( ListNode ) );

    if ( newPtr != NULL ) {
        newPtr->karakter = karakter;
        newPtr->broj = broj;
        newPtr->nextPtr = NULL;

        previousPtr = NULL;
        currentPtr = *sPtr;

        while ( currentPtr != NULL) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if ( previousPtr == NULL ) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }

    }else {
        printf( "Nema dovolno memorija.\n");
    }
}

void printList(ListNodePtr currentPtr){
    if ( currentPtr == NULL ) {
        printf( "Listata e prazna.\n\n" );
    }else {
        printf( "\nListata e:\n" );
        while ( currentPtr != NULL ) {
            printf( "%c%d --> ", currentPtr->karakter , currentPtr->broj);
            currentPtr = currentPtr->nextPtr;
        }
        printf( "NULL\n\n" );
    }

}

void pecatiListaNanazad( ListNodePtr currentPtr,int prv){
    if (currentPtr == NULL){
        return;
    }

    pecatiListaNanazad(currentPtr->nextPtr,0);
    if(prv){
    printf( "%c%d ", currentPtr->karakter , currentPtr->broj);
    } else{
        printf( "%c%d --> ", currentPtr->karakter , currentPtr->broj);
    }

}

void brisi( ListNodePtr *sPtr, char karakter, int broj ){
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    ListNodePtr tempPtr;

    if ( karakter == ( *sPtr )-> karakter &&  broj == ( *sPtr )-> broj) {
        tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextPtr;
        free(tempPtr);
    }else {
        previousPtr = *sPtr;
        currentPtr = ( *sPtr )->nextPtr;
        while ( currentPtr != NULL && currentPtr-> karakter != karakter && currentPtr-> broj != broj) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if ( currentPtr != NULL ) {
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free( tempPtr );
        }
    }
}

void sortOpagjanje( ListNodePtr currentPtr )
{
    if(currentPtr == NULL){
        return;
    }
    ListNodePtr nextPtr;
    int pom;
    while(currentPtr!=NULL){
        nextPtr = currentPtr->nextPtr;
        while(nextPtr!=NULL){
            if(currentPtr->broj < nextPtr->broj){
                pom=currentPtr->broj;
                currentPtr->broj=nextPtr->broj;
                nextPtr->broj=pom;
            }
            nextPtr=nextPtr->nextPtr;
        }
        currentPtr=currentPtr->nextPtr;
    }
}

void sortRastenje( ListNodePtr currentPtr )
{
    if(currentPtr == NULL){
        return;
    }
    ListNodePtr nextPtr;
    int pom;
    while(currentPtr!=NULL){
        nextPtr = currentPtr->nextPtr;
        while(nextPtr!=NULL){
            if(currentPtr->broj > nextPtr->broj){
                pom=currentPtr->broj;
                currentPtr->broj=nextPtr->broj;
                nextPtr->broj=pom;
            }
            nextPtr=nextPtr->nextPtr;
        }
        currentPtr=currentPtr->nextPtr;
    }
}


void instructions(void){
    printf( "\nVnesi izbor:\n"
            "   1 - za vnesuvanje element vo lista\n"
            "   2 - prevrti listata\n"
            "   3 - izbrishi element\n"
            "   4 - sortiraj elementi opagacki (spored promenlivata broj)\n"
            "   5 - sortiraj elementi rastecki (spored promenlivata broj)\n"
            "   6 - kraj\n" );
}

int main(){

    //1. Напиши функција pecatiListaNanazad која рекурзивно ги печати елементите од листа наназад. Елементите на листата се состојат од едно целоборјно поле broj и еден карактер кој се вика karakter.
    //2. Напиши програма која внесува елементи со функцијата vnesi несортирано, на крајот на листата, ја користи функцијата sortOpagjanje која сортира елементи во опаѓачки редослед, функцијата sortRastenje која ги сортира елемнтите во растечки редослед, brisi која брише елемент со дадена содржина. Елементите на листата се целобројни елементи.
    //Za vtorata zadaca sortiranjeto ke se izvrsuva spored brojot (dvete zadaci se reseni vo edna)

    struct listNode *startPtr = NULL;
    int choice;
    char karakter;
    int broj;

    while ( choice != 6 ) {
        instructions();
        scanf( "%d", &choice );

        switch ( choice ) {

            case 1:
                printf( "Vnesi karakter: " );
                scanf( "\n%c", &karakter );
                printf( "Vnesi broj: " );
                scanf( "\n%d", &broj );
                vnesi( &startPtr,karakter, broj);
                printList( startPtr );
                break;
            case 2:
                pecatiListaNanazad( startPtr, 1 );
                break;
            case 3:
                printf( "Vnesi karakter za brisenje: " );
                scanf( "\n%c", &karakter );
                printf( "Vnesi broj za brisenje: " );
                scanf( "\n%d", &broj );
                brisi( &startPtr,karakter, broj );
                printList( startPtr );
                break;
            case 4:
                sortOpagjanje( startPtr );
                printList( startPtr );
                break;
            case 5:
                sortRastenje( startPtr );
                printList( startPtr );
                break;
            default:
                printf( "Greshen izbor.\n\n" );
                instructions();
                break;
        }
    }

    return 0;
}
