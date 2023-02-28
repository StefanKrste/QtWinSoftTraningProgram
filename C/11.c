#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void morzeVoGovoren(char fraza[]){
    char *bukvi[37] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", " "};

    const char *morze[37] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", " "};

    char *bukva;
    bukva = strtok(fraza, "\n");
    bukva = strtok(fraza, " ");
    for (int i = 0; i < 1000 ; i++) {
        for (int j = 0; j < 37 ; j++) {
            if(strcmp(bukva, morze[j]) == 0){
                printf("%s",bukvi[j]);
                break;
            }
        }
        bukva = strtok(NULL, " ");
    }
}

int main(){

    //1. Напиши програм кој внесува телефонски број како стринг во облик (333) 333-3333. Програмот треба со користење на наредбата strtok да го извлече кодот на државата како едно делче, а потоа да го спои целиот телефонски број во друг стринг без -. Програмот треба да го конвертира бројот на државата во int, а седмоцифрениот телефонски број во long. Двата бројат треба да бидат испечатени.

//    char *brojDrzava;
//    char *telpom;
//    char *tel;
//
//    char celtel[20];
//    printf("Vnesete broj vo forma (333) 333-3333: ");
//    gets(celtel);
//
//    brojDrzava = strtok((celtel+1), ")");
//    int brDrzava = atoi(brojDrzava);
//    telpom = strtok((celtel+5), "-");
//    tel=telpom;
//    telpom = strtok(NULL, "-");
//    strcat(tel,telpom);
//    long telefon = atol(tel);
//
//    printf("\nBrojot na drzavata e - %d",brDrzava);
//    printf("\nTelefonskiot broj e - %ld",telefon);

    //2. Напиши програм кој чита датум во обликот 14/06/2005 и враќа датум во обликот 14 juni 2005. Корисникот да има можност да внесува колку што сака датуми кои треба да бидат конвертирани во другиот излез.

//    int brojDatumi,mesec,den,godina;
//    char *mesecChar;
//    char imput[12];
//
//    printf("\nVnesi broj na datumi koj sakate da gi transformirate: ");
//    gets(imput);
//    brojDatumi= atoi(imput);
//
//    while(brojDatumi>0){
//        printf("\nVnesi datum vo forma 14/06/2005: ");
//        gets(imput);
//
//        mesecChar = strtok(imput, "/");
//        den = atoi(mesecChar);
//        godina = atoi(mesecChar+1);
//        mesecChar = strtok(NULL, "/");
//        mesec = atoi(mesecChar);
//        mesecChar = strtok(NULL, "/");
//        godina = atoi(mesecChar);
//
//
//        printf("%d ",den);
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
//        printf(" %d\n",godina);
//        brojDatumi--;
//    }

    //3. Да се пронајдат на Интернет кодовите за бројки и букви во Морзеовата азбука. Да се напише програм кој чита текст фраза и ја дава нејзината вредност во Морзеовата азбука. Да се направи и друга функција на која и се предава Морзеов текст, а треба како резултат да се добие текст фраза во говорен јазик.

//    const char karakteri[37]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' '};
//
//    const char *morze[37] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", " "};
//
//    char fraza[1000]={0};
//
//    printf("Vnesete fraza koja sakate da se pretvori vo morzeov kod: ");
//    fgets(fraza, sizeof fraza, stdin);
//
//    for (int i = 0; i < 1000 ; i++) {
//        for (int j = 0; j < 37 ; j++) {
//            if(toupper(fraza[i])==karakteri[j]){
//                printf("%s ",morze[j]);
//                break;
//            }
//        }
//    }
//
//    printf("\nVnesete go morzeoviot kod koj sakate da se pretvori vo govoren jazik: ");
//    fgets(fraza, sizeof fraza, stdin);
//    morzeVoGovoren(fraza);

    return 0;
}