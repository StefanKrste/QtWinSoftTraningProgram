#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int SrednaTemp(int denovi);
void prosti (int niza[], int n);
int palindrom (char niza[], int n);
void vnesiMatrica(int r, int k, int matrica[r][k]);
void pechatiMatrica(int r, int k, int matrica[r][k]);
void selekcija (int niza[], int n);
void RekSelekcija (int niza[], int n, int pocetok);


int main(){

    //1. Напиши програм кој вчитува вредности за температури за секој ден од месецот и наоѓа средна месечна температура. Да се земе предвид дека различни месеци имаат различен број на денови.

//    int mesec;
//    printf("Vnesete go redniot broj na mesecot: ");
//    scanf("%d", &mesec);
//
//    switch (mesec)
//    {
//        case 1:
//            printf("Sredna mesecna temperatura za Januari: %d", SrednaTemp(31));
//            break;
//        case 2:
//            printf("Sredna mesecna temperatura za Fevruari: %d", SrednaTemp(28));
//            break;
//        case 3:
//            printf("Sredna mesecna temperatura za Mart: %d", SrednaTemp(31));
//            break;
//        case 4:
//            printf("Sredna mesecna temperatura za April: %d", SrednaTemp(30));
//            break;
//        case 5:
//            printf("Sredna mesecna temperatura za Maj: %d", SrednaTemp(31));
//            break;
//        case 6:
//            printf("Sredna mesecna temperatura za Juni: %d", SrednaTemp(30));
//            break;
//        case 7:
//            printf("Sredna mesecna temperatura za Juli: %d", SrednaTemp(31));
//            break;
//        case 8:
//            printf("Sredna mesecna temperatura za Avgust: %d", SrednaTemp(31));
//            break;
//        case 9:
//            printf("Sredna mesecna temperatura za Septemvri: %d", SrednaTemp(30));
//            break;
//        case 10:
//            printf("Sredna mesecna temperatura za Oktomvri: %d", SrednaTemp(31));
//            break;
//        case 11:
//            printf("Sredna mesecna temperatura za Noemvri: %d", SrednaTemp(30));
//            break;
//        case 12:
//            printf("Sredna mesecna temperatura za Dekemvri: %d", SrednaTemp(31));
//            break;
//        default:
//            printf("Vnesete broj pomegju 0-12");
//            break;
//    }

    //2. Прости броеви се броеви кои се деливи само со себе си и со бројот 1. Напиши програм кој внесува n елементи во низа. Да се овозможи функционалност да имаме променлив број на елементи во низата. Во почетокот сите елементи да се иницијализираат на 1. Потоа да се напише функција prosti која секој елемент од низата чиј индекс е прост број, го поставува на 0. На крај од така добиената низа да се најде начин да се испечатат простите броеви до n.

//    int n;
//    printf("Broj na elementi na nizata: ");
//    scanf("%d",&n);
//    int niza[n];
//    for (int i = 0; i < n; i++) {
//        niza[i] = 1;
//    }
//    prosti(niza ,n);

    //3. Палиндроми се низи од букви што се читаат исто и оддесно на лево и одлево на десно. На пример зборот “radar” е палиндром. Да се напише програм во кој внесуваме низа од карактери. Треба да имаме функција palindrom која враќа вредност 1 ако стрингот е палиндром или 0 инаку.

//    int n;
//
//    printf("Broj na elementi na nizata: ");
//    scanf("%d",&n);
//    printf("Vnes na elementi: ");
//    char niza[n];
//    for (int i = 0; i < n; i++) {
//        scanf(" %c",&niza[i]);
//    }
//    printf("Polindrom %d",palindrom(niza ,n));

    //4. Да се напише програма која во главната функција внесува број на редици и колони на дводимензионална матрица. Во функцијата vnesiMatrica внесува елементи, а преку функцијата pechatiMatrica ги печати елементите во табеларна форма.
    //а) Да се напишат итеративни верзии на двете функции.
    //б) Да се напишат рекурзивни верзии на двете функции.

//    int r,k;
//
//    printf("Broj broj na redici: ");
//    scanf("%d",&r);
//    printf("Broj broj na koloni: ");
//    scanf("%d",&k);
//    int matrica [r][k];
//
//    vnesiMatrica(r, k, matrica);
//    pechatiMatrica(r, k, matrica);

    //5. Да се напише програма која симулира селекциско сортирање. Селекциското сортирање го бара најмалиот елемент во низата и го заменува со првиот елемент. Сега, на прво место сигурно ни се наоѓа најмалиот елемент во низата. Потоа, во остатокот од низата, од вториот до n-тиот елемент, повторно го бараме новиот најмал елемент и му ја заменуваме вредноста со вториот елемент од низата итн. Ова сортирање има слични процесирачки капацитети како сортирање со методот на меурче.
    //а) Да се напише итеративна верзија на функцијата selekcija која го врши селекциското сортирање.
    //б) Да се напише рекурзивна верзија на селекциското сортирање.
    //в) Да се одговори зошто процесирачките капацитети на ова сортирање се слични како оние со методот на меурче.

//    int niza[10]={1,8,6,2,3,4,9,7,5,10};
//
//    printf("Nesortirana niza: ");
//    for (int i = 0; i < 10; i++) {
//        printf("%d ",niza[i]);
//    }
//
//    selekcija(niza, 10);
//
//    printf("\nSortirana niza A): ");
//    for (int i = 0; i < 10; i++) {
//        printf("%d ",niza[i]);
//    }
//
//    niza[0]=1;
//    niza[1]=8;
//    niza[2]=6;
//    niza[3]=2;
//    niza[4]=3;
//    niza[5]=4;
//    niza[6]=9;
//    niza[7]=7;
//    niza[8]=5;
//    niza[9]=10;
//
//    printf("\nNesortirana niza: ");
//    for (int i = 0; i < 10; i++) {
//        printf("%d ",niza[i]);
//    }
//
//    RekSelekcija(niza, 10,0);
//
//    printf("\nSortirana niza B): ");
//    for (int i = 0; i < 10; i++) {
//        printf("%d ",niza[i]);
//    }

    //5-c (zatoa sto imaat slicna kompleksnost)

    return 0;
}

int SrednaTemp(int denovi){
    int temp,sum = 0;

    for(int i=1; i<=denovi; ++i)
    {
        printf("Temperatura za den %d: ", i);
        scanf("%d", &temp);
        sum += temp;
    }

    return sum / denovi;
}

void prosti (int niza[], int n){
    for (int i=2; i<n ; i++) {
        for (int j=2; j<=i ; j++) {
            if(j==i){
                niza[i]=0;
            }
            if(i%j==0){
                break;
            }
        }
    }
    for (int i=0; i<n ; i++) {
        if(niza[i]==0){
            printf("%d, ", i);
        }
    }
}

int palindrom (char niza[], int n){
    for (int i = 0; i <n/2 ; i++){
        printf(" %c %c", niza[i],niza[n-1-i] );
        if(niza[i]!=niza[n-1-i]) {
            return 0;
        }
    }
    return 1;
}

void vnesiMatrica(int r, int k, int matrica[r][k]){
    for(int i=0;i<r;i++){
        for(int j=0;j<k;j++){
            scanf("%d", &matrica[i][j]);
        }
    }
}

void pechatiMatrica(int r, int k, int matrica[r][k]){
    for(int i=0;i<r;i++){
        for(int j=0;j<k;j++){
            printf("%d ", matrica[i][j]);
        }
        printf("\n");
    }
}

void selekcija (int niza[], int n){
    int momentalnoNajmal,pozicija,pom;
    for(int i=0;i<n;i++){
        momentalnoNajmal=niza[i];
        for(int j=i;j<n;j++){
            if(momentalnoNajmal>=niza[j]){
                momentalnoNajmal=niza[j];
                pozicija=j;
            }
        }
        pom = niza[i];
        niza[i]=momentalnoNajmal;
        niza[pozicija]=pom;
    }
}

void RekSelekcija (int niza[], int n, int pocetok){
    int Najmal,pozicija,pom;
    Najmal=niza[pocetok];
    for(int i=pocetok;i<n;i++){
        if(Najmal>=niza[i]){
            Najmal=niza[i];
            pozicija=i;

        }
    }

    pom = niza[pocetok];
    niza[pocetok]=Najmal;
    niza[pozicija]=pom;

    if(pocetok+1!=n){
        RekSelekcija(niza,n,pocetok+1);
    }
}
