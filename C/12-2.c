#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct del{
    int kod;
    char ime[100];
    int kol;
    float cena;
};

//Vnes na nov del
void novDel(FILE *datoteka) {
    struct del del = {0, "", 0, 0.0};
    int kodDel;

    printf("\nVnesete kod na delot: ");
    scanf("%d", &kodDel);

    fseek(datoteka, (kodDel - 1) * sizeof(del),SEEK_SET);
    fread(&del, sizeof(del), 1, datoteka);


    if (del.kod != 0) {
        printf("Produktot %d e veke vnesen.\n",kodDel);
    } else {
        printf("\nIme na del: ");
        getchar();
        fgets(del.ime, sizeof(del.ime), stdin);
        del.ime[strcspn(del.ime, "\n")] = '\0';
        printf("\nKolicina: ");
        scanf("%d",&del.kol);
        printf("\nCena: ");
        scanf("%f",&del.cena);
        del.kod = kodDel;

        fseek(datoteka, (kodDel - 1) * sizeof(del),SEEK_SET);
        fwrite(&del, sizeof(del), 1, datoteka);
    }
}

//Podatoci za eden del
void prikaziEdenDel(FILE *datoteka , int broj){
    struct del del = {0, "", 0, 0.0};

    fseek(datoteka, (broj - 1) * sizeof(del), SEEK_SET);
    fread(&del, sizeof(del), 1, datoteka);

    if (del.kod == 0) {
        printf("Delot so kod %d ne postoi.\n", broj);
        return;
    }
    printf("%-10s%-20s%-12s%10s\n", "KOD", "IME NA DEL", "KOLICINA", "CENA");
    printf("%-10d%-20s%-12d%10.2f\n",del.kod, del.ime,del.kol, del.cena);
}

//Podatoci za prodavnicata
void sostojbaVoProdavnica(FILE *datoteka){
    printf("%-10s%-20s%-12s%10s\n", "KOD", "IME NA DEL", "KOLICINA", "CENA");

    struct del del = {0, "", 0, 0.0};
    int maxKod = 0;

    while (fread(&del, sizeof(del), 1, datoteka) == 1) {
        if (del.kod > maxKod) {
            maxKod = del.kod;
        }
    }
    rewind(datoteka);

    for (int i = 1; i <= maxKod; i++) {
        fread(&del, sizeof(del), 1, datoteka);
        if (del.kod != 0) {
            printf("%-10d%-20s%-12d%10.2f\n",del.kod, del.ime,del.kol, del.cena);
        }
    }
}

//Izbrishi del
void izbrisiDel(FILE *datoteka , int broj){
    struct del del = {0, "", 0, 0.0};

    fseek(datoteka, (broj - 1) * sizeof(del), SEEK_SET);
    fread(&del, sizeof(del), 1, datoteka);

    if (del.kod == 0) {
        printf("Delot so kod %d ne postoi.\n", broj);
        return;
    }
    if (del.kol > 0) {
        printf("Imate kolicina od toj del.\n", broj);
        return;
    }
    struct del empty = {0, "", 0, 0.0};
    fseek(datoteka, (broj - 1) * sizeof(del), SEEK_SET);
    fwrite(&empty, sizeof(empty), 1, datoteka);
    printf("Delot so kod %d e uspesno izbrishan.\n", broj);
}

//Promena na podatoci za nekoj del
void promeniPodatociZaDel(FILE *datoteka , int broj){
    int choice;
    struct del del = {0, "", 0, 0.0};

    fseek(datoteka, (broj - 1) * sizeof(del), SEEK_SET);
    fread(&del, sizeof(del), 1, datoteka);

    if (del.kod == 0) {
        printf("Delot so kod %d ne postoi.\n", broj);
        return;
    }

    printf("Tekovni podatoci za delot so kod %d:\n", broj);
    printf("1. Ime: %s\n", del.ime);
    printf("2. Kolicina: %d\n", del.kol);
    printf("3. Cena: %.2f\n", del.cena);

    printf("Koj podatok sakate da go promenite (1-3)? ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Vnesete novo ime: ");
            scanf("%s", del.ime);
            break;
        case 2:
            printf("Vnesete nova kolicina: ");
            scanf("%d", &del.kol);
            break;
        case 3:
            printf("Vnesete nova cena: ");
            scanf("%f", &del.cena);
            break;
        default:
            printf("Nevaliden izbor.\n");
            return;
    }

    fseek(datoteka, (broj - 1) * sizeof(del), SEEK_SET);
    fwrite(&del, sizeof(del), 1, datoteka);

    printf("Podatocite za delot so kod %d se uspesno promeneti.\n", broj);
}

//Promena na kolicina na del
void prodazba(FILE *datoteka , int broj , int kol){
    int choice;
    struct del del = {0, "", 0, 0.0};

    fseek(datoteka, (broj - 1) * sizeof(del), SEEK_SET);
    fread(&del, sizeof(del), 1, datoteka);

    if (del.kod == 0) {
        printf("Delot so kod %d ne postoi.\n", broj);
        return;
    }

    if(del.kol>=kol) {
        del.kol=del.kol-kol;
        fseek(datoteka, (broj - 1) * sizeof(del), SEEK_SET);
        fwrite(&del, sizeof(del), 1, datoteka);
    } else{
        printf("Nemate dovolno na zaliha");
    }
}

//zad 2
void napraviZbor(char matrica[7][3], char zborovi[], int red, int dolzina) {
    if (red == 7) {
        zborovi[dolzina] = '\0';
        printf("%s\n", zborovi);
        return;
    }

    for (int i = 0; i < 3; i++) {
        if(matrica[red][i]!=0) {
            zborovi[dolzina] = matrica[red][i];
            napraviZbor(matrica, zborovi, red + 1, dolzina + 1);
        }
    }
}

//zad 2
void generate(char broj[]) {

    char matrica[7][3]={0};
    char zborovi[10000];

    for (int i = 0; i < strlen(broj); i++) {
        switch(broj[i]) {
            case '0':
                matrica[i][0]='Y';
                matrica[i][1]='Z';
                break;
            case '1':
                printf("Za edinica nemame informacii");
                exit(0);
                break;
            case '2':
                matrica[i][0]='A';
                matrica[i][1]='B';
                matrica[i][2]='C';
                break;
            case '3':
                matrica[i][0]='D';
                matrica[i][1]='F';
                matrica[i][2]='E';
                break;
            case '4':
                matrica[i][0]='G';
                matrica[i][1]='H';
                matrica[i][2]='I';
                break;
            case '5':
                matrica[i][0]='J';
                matrica[i][1]='K';
                matrica[i][2]='L';
                break;
            case '6':
                matrica[i][0]='M';
                matrica[i][1]='N';
                matrica[i][2]='O';
                break;
            case '7':
                matrica[i][0]='P';
                matrica[i][1]='Q';
                matrica[i][2]='R';
                break;
            case '8':
                matrica[i][0]='S';
                matrica[i][1]='T';
                matrica[i][2]='U';
                break;
            case '9':
                matrica[i][0]='V';
                matrica[i][1]='W';
                matrica[i][2]='X';
                break;
        }
    }

    napraviZbor(matrica, zborovi,0,0);
}




int main(){

    //1.2 Вие сте сопственик на продавница за компјутерска опрема. Треба да си направите апликација која ќе се грижи за хардверот што го имате на располагање, количината на секој од деловите во продавницата и цените на деловите. Напишете програма која иницијализира датотека “hardware.dat”, ви овозможува да внесете податоци за секој дел, да ги излистате податоците за специфичен дел, да дадете комплетен листинг на состојбата во вашата продавница, да избришете податоци за даден дел ако тој веќе го немате на лагер, да ажурирате податоци за даден дел и да правите продажба. Под продажба се подразбира намалување на бројот на потребни делови од датотеката, доколку има толку делови, колку што бара купецот. Да претпоставиме дека имаме оптички читач на касата и дека секој дел се вчитува со негов код.

//    int opcioja,kraj=1,broj,kol;
//    FILE *datoteka;
//
//    if((datoteka = fopen("hardware.dat", "rb+")) == NULL) {
//        printf("Problem pri otvaranje na datotekata");
//        exit(0);
//    }
//
//    while(kraj) {
//        fseek(datoteka, 0, SEEK_SET);
//        printf("\n1 - Vnesete nov del");
//        printf("\n2 - Prikazi podatoci za del");
//        printf("\n3 - Prikazi sostojba vo prodavnica");
//        printf("\n4 - Promeni podatoci za nekoj del");
//        printf("\n5 - Prodazba");
//        printf("\n6 - Izbrisi del");
//        printf("\n7 - Kraj");
//
//        printf("\n\nIzberete opcija od 1-7: ");
//        scanf("%d",&opcioja);
//
//        switch (opcioja) {
//            case 1:
//                novDel(datoteka);
//                break;
//            case 2:
//                printf("\nVnesete kod na delot: ");
//                scanf("%d",&broj);
//                prikaziEdenDel(datoteka,broj);
//                break;
//            case 3:
//                sostojbaVoProdavnica(datoteka);
//                break;
//            case 4:
//                printf("\nVnesete kod na delot: ");
//                scanf("%d",&broj);
//                promeniPodatociZaDel(datoteka,broj);
//                break;
//            case 5:
//                printf("\nVnesete kod na delot: ");
//                scanf("%d",&broj);
//                printf("\nVnesete kolku kolicina prodavate: ");
//                scanf("%d",&kol);
//                prodazba(datoteka,broj,kol);
//                break;
//            case 6:
//                printf("\nVnesete kod na delot: ");
//                scanf("%d",&broj);
//                izbrisiDel(datoteka,broj);
//                break;
//            case 7:
//                kraj=0;
//                break;
//            default:
//                printf("Greshen vlez (vnesete broj od 1-7)\n");
//                break;
//        }
//    }
//
//    fclose(datoteka);

    //2.2 Да се напише програма која служи како генератор на телефонски броеви. Знаеме дека полесно се паметат поими од броеви, па така некои од компаниите имаат телефонски броеви кои ја означуваат дејноста или името на компанијата.
    //Нека ни се подредени буквите на следниот начин:
    //    Цифра	Буква
    //    2	    ABC
    //    3	    DEF
    //    4	    GHI
    //    5	    JKL
    //    6	    MNO
    //    7	    PQR
    //    8	    STU
    //    9	    VWX
    //    0	    YZ
    //а) За даден седумбуквен стринг да се изгенерира бројот на телефон. Пример: “TELEKOM” = 8353566
    //б) За даден седмоцифрен број да се изгенерираат што поголем број на стрингови. Да се внимава дека 0 има само две букви.

//    char vlez[8];
//
//    printf("Vnesete sedumbukven string: ");
//    scanf("%s", vlez);
//
//    if(strlen(vlez)!=7){
//        printf("Gresen vlez");
//        return 0;
//    }
//
//    for (int i = 0; i < strlen(vlez); i++) {
//        switch(toupper(vlez[i])) {
//            case 'A':
//            case 'B':
//            case 'C':
//                printf("2");
//                break;
//            case 'D':
//            case 'E':
//            case 'F':
//                printf("3");
//                break;
//            case 'G':
//            case 'H':
//            case 'I':
//                printf("4");
//                break;
//            case 'J':
//            case 'K':
//            case 'L':
//                printf("5");
//                break;
//            case 'M':
//            case 'N':
//            case 'O':
//                printf("6");
//                break;
//            case 'P':
//            case 'Q':
//            case 'R':
//                printf("7");
//                break;
//            case 'S':
//            case 'T':
//            case 'U':
//                printf("8");
//                break;
//            case 'V':
//            case 'W':
//            case 'X':
//                printf("9");
//                break;
//            case 'Y':
//            case 'Z':
//                printf("0");
//                break;
//        }
//    }
//
//    printf("\nVnesete sedumcifren broj: ");
//    scanf("%s", vlez);
//
//    if(strlen(vlez)!=7){
//        printf("Gresen vlez");
//        return 0;
//    }
//
//    generate(vlez);

    return 0;
}