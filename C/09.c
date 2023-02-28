#include <stdio.h>
#include <math.h>
#include <stdbool.h>

float determinanta(int matrica[3][3]){
    return matrica[0][0] * (matrica[1][1] * matrica[2][2] - matrica[2][1] * matrica[1][2])
                  - matrica[0][1] * (matrica[1][0] * matrica[2][2] - matrica[1][2] * matrica[2][0])
                  + matrica[0][2] * (matrica[1][0] * matrica[2][1] - matrica[1][1] * matrica[2][0]);
}

void resiGoSistemot(int matrica[3][4]){
    int d[3][3] = {
            { matrica[0][0], matrica[0][1], matrica[0][2] },
            { matrica[1][0], matrica[1][1], matrica[1][2] },
            { matrica[2][0], matrica[2][1], matrica[2][2] },
    };

    int d1[3][3] = {
            { matrica[0][3], matrica[0][1], matrica[0][2] },
            { matrica[1][3], matrica[1][1], matrica[1][2] },
            { matrica[2][3], matrica[2][1], matrica[2][2] },
    };

    int d2[3][3] = {
            { matrica[0][0], matrica[0][3], matrica[0][2] },
            { matrica[1][0], matrica[1][3], matrica[1][2] },
            { matrica[2][0], matrica[2][3], matrica[2][2] },
    };

    int d3[3][3] = {
            { matrica[0][0], matrica[0][1], matrica[0][3] },
            { matrica[1][0], matrica[1][1], matrica[1][3] },
            { matrica[2][0], matrica[2][1], matrica[2][3] },
    };

    int D = determinanta(d);
    int D1 = determinanta(d1);
    int D2 = determinanta(d2);
    int D3 = determinanta(d3);


    if (D != 0){
        float x = D1 / D;
        float y = D2 / D;
        float z = D3 / D;
        printf("X = %.2f \n", x);
        printf("Y = %.2f \n", y);
        printf("Z = %.2f \n", z);
    }else{
        if (D1 == 0 && D2 == 0 && D3 == 0){
            printf("Beskonevno mnogu reshenija\n");
        }else if (D1 != 0 || D2 != 0 || D3 != 0){
            printf("Nema reshenie. \n");
        }
    }
}

void proizvodOdProstiBroevi(int broj) {
    for (int i = 2; i <= broj; i++) {
        while (broj % i == 0) {
            printf("%d ", i);
            broj /= i;
        }
    }
    if (broj > 2) {
        printf("%d ", broj);
    }
}

int sprotivenBroj (int broj){
    int sprotivenBroj = 0;
    while (broj != 0) {
        sprotivenBroj *= 10;
        sprotivenBroj += broj % 10;
        broj /= 10;
    }
    return sprotivenBroj;
}

bool proveriBroj(long broj) {
    int cifri[10] = {0};
    while (broj > 0) {
        cifri[broj % 10]++;
        broj /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (cifri[i] != 1) {
            return false;
        }
    }
    return true;
}

void peshati(int broj,int nazad,int pom) {
    if(nazad<=broj && nazad>=0){
        for (int i = nazad; i > 0 ; i--) {
            printf("%d ",broj-i+1);
        }
        printf("\n ");
        if(nazad==broj){
            pom=1;
        }
        if(pom==1){
            peshati(broj, nazad - 1,1);
        } else {
            peshati(broj, nazad + 1,0);
        }
    }
}

int main(){

    //1. Да се најде обиколката и плоштината на правилен n-аголник.

//    float n, l;
//    printf("Broj na strani: ");
//    scanf("%f", &n);
//    printf("\nDolzina na strani: ");
//    scanf("%f", &l);
//    printf("\nA: %.2f", (n*l*l)/(4*tan((180/n)*3.14/180)));
//    printf("\nP: %.2f", n*l);

    //2. Да се реши систем од три равенки со три непознати.

//    double a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3;
//
//    printf("Vnesete gi vrednostite za a, b, c i d\n");
//
//    printf("\nPrva ravenka: ");
//    scanf("%d%d%d%d", &a1, &b1, &c1, &d1);
//
//    printf("\nVtora ravenka: ");
//    scanf("%d%d%d%d", &a2, &b2, &c2, &d2);
//
//    printf("\nTreta ravenka: ");
//    scanf("%d%d%d%d", &a3, &b3, &c3, &d3);
//
//    int matrica[3][4] = {{a1, b1, c1, d1}, {a2, b2, c2, d2}, {a3, b3, c3, d3}};
//
//    resiGoSistemot(matrica);

    //3. Да се најде спротивен број на природниот број n. (Тоа е природниот број што ги има истите цифри со n, напишани во спротивен редослед.)

//    int broj;
//    printf("Vnesi cel broj: ");
//    scanf("%d", &broj);
//
//    printf("Sprotivniot broj na %d e: %d",broj, sprotivenBroj(broj));

    //4. Да се најдат совршените броеви помали од природниот број n.

//    int broj,sum=0;
//
//    printf("Vnesete pozitiven cel broj: ");
//    scanf("%d", &broj);
//
//    for(int i=2;i<=broj;i++){
//        sum=0;
//        for(int j=1;j<i;j++){
//            if(i%j==0){
//                sum+=j;
//            }
//        }
//        if(sum==i){
//            printf("%d, ", i);
//        }
//    }

    //5. Да се претстави природниот број n како производ од прости множители. (n=p1^k1*p2^k2...pr^kr , каде што p1, p2, ..., pr се прости броеви, а k1, k2, . . . , kr се природни броеви.)

//    int broj;
//
//    printf("Vnesete priroden broj: ");
//    scanf("%d", &broj);
//    printf("Proizvodot od prostite broevi ");
//    proizvodOdProstiBroevi(broj);
//    printf("se dobiva %d ",broj);
//    printf("\n");
//    return 0;

    //6. Да се најдат природните броеви помали од n, чиј збир на кубовите на цифри¬те е еднаков на самиот број.

//    int broj,sum=0,i=0;
//
//    printf("Vnesete priroden broj: ");
//    scanf("%d", &broj);
//
//    while (sum<=broj){
//        sum += (i*i*i);
//        i++;
//    }
//    i--;
//
//    printf("\nPrirodni broevi chii proizvod na kubovite e pomal od vneseniot broj se:");
//    for (int j = 1; j < i; ++j) {
//        printf(" %d ",j);
//    }

    //7. Да се најдат природните броеви во интервалот [n1,n2], кои се деливи со сво-јот спротивен број.

//    int broj1,broj2,sprotiven,pom;
//
//    printf("Vnesi dva prirodni broja n1 i n2: ");
//    scanf("%d%d", &broj1, &broj2);
//
//    if(broj1>broj2){
//        pom=broj2;
//        broj2=broj1;
//        broj1=pom;
//    }
//
//    printf("Broevi delivi so svojot sprotiven broj vo toj interal se: ");
//
//    for(int i=broj1; i<=broj2 ;i++){
//        if(i % sprotivenBroj(i) == 0){
//            printf("%d ", i);
//        }
//    }

    //8. Да се најдат природните броеви чиј квадрат и куб (заедно) ги содржат сите цифри 0,1, 2, .. , 9 по еднаш.

//    int broj;
//    printf("Vnesete broj do koj sakate da prebaruvate: ");
//    scanf("%d", &broj);
//
//    for (int i = 1 ; i <= broj; i++) {
//        long kvadrat = (long)i * i;
//        long kub = (long)i * i * i;
//        long spojuvanje = kvadrat * 1000000000LL + kub;
//        if (proveriBroj(spojuvanje)) {
//            printf("%ld\n", i);
//        }
//    }

    //9. Секоја од n бактерии се дели на две на секои i минути, додека на секои j минути изумираат x% од живите бактерии во тој момент. Колку бактерии ќе има по k минути?

//    int brBakterii,minDelba,minZivot,procentiZivot,maxMin,sumBaketerii;
//
//    printf("\nBroj na bakterii na pocetokot: ");
//    scanf("%d", &brBakterii);
//    printf("\nVnesi na kolku minuti se sluchuva delba: ");
//    scanf("%d", &minDelba);
//    printf("\nVnesi na kolku min istekuva del od zivotot na bakterijata: ");
//    scanf("%d", &minZivot);
//    printf("\nVnesi kolku %% od zivotot i istekuva za toa vreme: ");
//    scanf("%d", &procentiZivot);
//    printf("\nVnesi za kolku min sakas da doznaes kolku bakterii ke ima: ");
//    scanf("%d", &maxMin);
//
//    sumBaketerii=brBakterii;
//
//    for (int i = 1; i <= maxMin; ++i) {
//        if(i%minZivot==0 && i>=minZivot){
//            sumBaketerii=((float)sumBaketerii/100)*(procentiZivot);
//        }
//        if(i%minDelba==0 && i>=minDelba){
//            sumBaketerii *= 2;
//        }
//    }
//
//    printf("\nZa %d minuti ke ima %d bakterii",maxMin,sumBaketerii);

    //10. Да се најдат сите растечки поднизи во низата броеви [ai]n. (Растечка подни¬за е онаа во која секој елемент е поголем од претходниот.)

//    int niza[10]= {1,2,3,4,3,2,8,4,5,6};
//
//    printf("Podnizi na dadenata nzia se: \n");
//    printf("%d",niza[0]);
//    for (int i = 1; i < 10 ; i++) {
//        if(niza[i-1]<niza[i]){
//            printf("%d",niza[i]);
//        }else{
//            printf("\n%d",niza[i]);
//        }
//    }

    //11. Да се најдат сите пилести поднизи во низата броеви [ai]n. (Пилеста подни¬за е онаа во која претходниот и следниот елемент на секој елемент се по¬мали (поголеми) од него.)

//    int niza[10]= {1,2,3,4,3,2,8,4,5,6};
//    int pom;
//
//    printf("Pilesti podnizi na dadenata nzia se: \n");
//
//    printf("%d",niza[0]);
//    for (int i = 1; i < 10 ; i++) {
//        if(niza[i]>niza[i-1] && pom != '>'){
//            printf("%d",niza[i]);
//            pom = '>';
//        }else if(niza[i]<niza[i-1] && pom != '<') {
//            printf("%d",niza[i]);
//            pom = '<';
//        }else{
//            printf("\n%d",niza[i]);
//            pom = '!';
//        }
//    }

    //12. Да се внесат два полинома со степени n m соодветно. Да се внесат нивните коефициенти и да се најде нивниот збир.

//    int n,m,pogolem,pomal;
//
//    printf("\nVnesete od koj stepen e prviot polinom");
//    scanf("%d", &n);
//    n++;
//
//    printf("\nVnesete od koj stepen e vtoriot polinom");
//    scanf("%d", &m);
//    m++;
//
//    int pol1[n], pol2[m];
//
//    if(n>m){
//        pogolem=n;
//        pomal=m;
//    } else{
//        pogolem=m;
//        pomal=n;
//    }
//
//    int zbir[pogolem];
//
//    printf("\nVnesi gi koeficientite na prviot polinom od koeficientot na najgolemiot stepen i na krajot konstantata: ");
//    for (int i = 0; i < n; i++) {
//        scanf("%d",&pol1[i]);
//    }
//
//    printf("\nVnesi gi koeficientite na vtoriot polinom od koeficientot na najgolemiot stepen i na krajot konstantata: ");
//    for (int i = 0; i < m; i++) {
//        scanf("%d",&pol2[i]);
//    }
//
//    for (int i = pogolem-1; i >= 0; i--) {
//        if(i>pomal-1){
//            if(n==pogolem) {
//                zbir[i] = pol1[i];
//            } else{
//                zbir[i] = pol2[i];
//            }
//        } else{
//            zbir[i]= pol1[i]+pol2[i];
//        }
//    }
//
//    printf("\nZbirot e: ");
//
//    for (int i = pogolem-1; i >= 0; i--) {
//        if(i!=0) {
//            printf("(%dx^%d)+", zbir[i], i + 1);
//        } else{
//            printf("(%d)", zbir[i]);
//        }
//    }

    //13. Да се генерираат следниве дводимензионални полиња со m-редици и n-колони.

//    int n,m,broj=0;
//
//    printf("\nVnesete m redici");
//    scanf("%d", &m);
//
//    printf("\nVnesete n koloni");
//    scanf("%d", &n);
//
//    int matrica[m][n];
//
//    for(int i=0; i<n; i++) {
//        for(int j=0; j<m; j++) {
//            if(i%2!=0){
//                broj--;
//                matrica[j][i]=broj;
//            } else{
//                broj++;
//                matrica[j][i]=broj;
//            }
//        }
//        if(i%2!=0){
//            broj+=m-1;
//        } else{
//            broj+=m+1;
//        }
//    }
//
//    for (int i=0;i<n;i++) {
//        for (int j=0;j<m;j++)
//            printf("%d ", matrica[i][j]);
//
//        printf("\n");
//    }

    //14. За даден природен број n да се испечатат следниве фигури со користење на рекурзија.

//    int n;
//
//    printf("\nVnesete priroden broj n: ");
//    scanf("%d", &n);
//
//    peshati(n,0,0);

    return 0;
}