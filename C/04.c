#include <stdio.h>

int main(){
    //1. Модифицирај го програмот p04_01.c така да ги испуштиш break наредбите. Што се случува? Покажи пример.

//    int mesec;
//
//    printf("Vnesi go mesecot so negoviot reden broj: ");
//    scanf("%d", &mesec);
//
//    switch (mesec) {
//        case 1:
//        case 3:
//        case 5:
//        case 7:
//        case 8:
//        case 10:
//        case 12:
//            printf("Ima 31 den\n");
//        case 4:
//        case 6:
//        case 9:
//        case 11:
//            printf("Ima 30 dena\n");
//        case 2:
//            printf("Vo prestapni godini ima 29, a vo obichni 28 dena\n");
//        default:
//            printf("Greshen broj na mesec!\n");
//    }

// Gi izvrsuva site case pod izbraniot vo sluchaj koga nemame break;

    //2. Модифицирај го програмот p04_02.c така да наместо да е предефинирана вредноста на променливата counter, треба на корисникот да му се овозможи тој да внесе колку ученици има во класот.
    //3. Модифицирај го претходниот програм (вежба 2) така да просекот се пресметува како децимален број со точност од 3 децимали.

//    int counter;
//    int grade;
//    int total;
//    float average;
//
//    total = 0;
//    scanf( "%d", &counter );
//    int pom=counter;
//    while ( pom >= 1) {
//        printf( "Vnesi ocena: ");
//        scanf( "%d", &grade );
//        total = total + grade;
//       pom = pom - 1;
//    }
//
//    if(counter>0) {
//       average = (float)total / counter;
//    }
//
//    printf( "Srednata vrednost na klasot e %.3f\n", average );

    //4. Напиши програма која ја пресметува сумата на броевите од 1 до десет.

//    int tot = 0;
//
//    for (int i=1 ; i <= 10; i++){
//        tot+=i;
//    }
//
//    printf("%d", tot);

    //5. Напиши програма која за внесени десет броја, го пресметува нивниот производ.

//    float tot = 0;
//    float pom = 0;
//
//    for (int i=1 ; i <= 10; i++){
//        scanf("%f" , &pom);
//        tot+=pom;
//    }
//
//    printf("%.3f", tot);

    //6. Напиши програма која пресметува сума на внесени броеви од тастатура се додека не се внесе -1.

//    float tot = 0;
//    float pom = 0;
//
//    scanf("%f" , &pom);
//    while (pom!=-1){
//        tot+=pom;
//        scanf("%f" , &pom);
//    }
//
//    printf("%.3f", tot);

    //7. Напиши програма која пресметува сума на внесени броеви од тастатура се додека не се внесе карактер ‘n’.
    //          Пример:
    //          Vnesi broj: 6
    //          Ushte? (d/n): d
    //          Vnesi broj: 7
    //          Ushte? (d/n): d
    //          Vnesi broj: 3
    //          Ushte? (d/n): n
    //          Sumata e 16

//    float tot = 0;
//    float pom = 0;
//    char d = 'd';
//
//
//    while (d != 'n') {
//        if (d == 'd'){
//            printf("Vnesi broj: ");
//        scanf("%f", &pom);
//        tot += pom;
//        }else{
//            printf("\nGreshen vlez");
//        }
//        printf("\nUshte? (d/n): ");
//        scanf(" %c", &d);
//        }
//
//    printf("\nSumata e %.3f", tot);

    //8. Една стоковна куќа продава 5 производи чии цени се дадени во долната табела
    //Производ број	Цена
    //  1	        50.5
    //  2	        45.6
    //  3	        32.8
    //  4	        65.3
    //  5	        20.0
    //Да се напише програм кој чита серија од парови броеви за:
    //а) број на производ
    //б) количина продадена во текот на денот
    //Програмот треба да ја користи switch наредбата за да ја одреди цената за секој  производ. Програмот треба да ја пресмета и испечати вкупната продадена вредност за секој од производите посебно, како и вкупната сума за сите производи продадени во текот на денот.

//    float cena,vkupno;
//    int id,kol;
//
//    for(int i=1; i<=5; i++){
//        printf("Vnesete go brojot na proizvod i kol:");
//        scanf("%d %d",&id,&kol);
//
//        switch (id){
//            case 1:
//                cena = 50.5 * kol;
//                break;
//            case 2:
//                cena = 45.6 * kol;
//                break;
//            case 3:
//                cena = 32.8 * kol;
//                break;
//            case 4:
//                cena = 65.3 * kol;
//                break;
//            case 5:
//                cena = 20.0 * kol;
//                break;
//        }
//        printf("Cenata na proizvodot so broj %d e: %.3f", id,cena);
//        vkupno+=cena;
//    }
//    printf("Vkupnata cena na site proizvodi e: %.3f", vkupno);

    //9. Една голема хемиска компанија ги плаќа своите продавачи делумно и на процент. Продавачите земаат плата од 200 евра плус 9% од вкупната нивна продажба за тој месец. На пример, ако некој продавач продал роба вредна 5000 евра, тогаш добива 200 евра плус 9% од 5000, значи вкупно 650 евра. Напиши програма која за внесен месечен промет му ја пресметува платата на вработениот. Пример:
    //Vnesi promet vo evra (-1 za kraj): 5000.00
    //Platata e: 650.00 evra
    //
    //Vnesi promet vo evra (-1 za kraj): 1234.56
    //Platata e: 311.11 evra

//    float pom=0;
//
//    while (pom != -1){
//        printf("\nVnesi promet vo evra (-1 za kraj):" );
//        scanf("%f",&pom);
//        if(pom!=-1) {
//            printf("Platata e: %.2f", 200 + (pom / 100) * 9);
//        }
//    }

   return 0;
}
