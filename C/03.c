#include <stdio.h>

int main(){
    int br1;
    int br2;
    char b1,b2,b3,b4,b5;

    //1. Напиши програм кој како влез зема два цели броја и ги споредува. Потоа го испечатува поголемиот број проследен со коментарот e pogolem od и го испечатува и помалиот број. Ако броевите се еднакви, програмот треба да испечати Broevite se ednakvi.

//    scanf("%d%d", &br1,&br2);
//
//   if (br1>br2){
//       printf("%d e pogolem od %d", br1,br2);
//   } else if (br1<br2){
//       printf("%d e pogolem od %d", br2,br1);
//   } else {
//       printf("Broevite se enakvi");
//   }

    //2. Напиши програм кој вчитува два цели броја и одредува дали се парни или непарни.

//    scanf("%d%d", &br1,&br2);
//
//    if (br1%2==0){
//       printf("%d e paren\n", br1);
//    } else {
//        printf("%d e neparen", br1);
//    }
//
//    if (br2%2==0){
//        printf("%d e paren\n", br2);
//    } else {
//        printf("%d e neparen", br2);
//    }

    //3. Обидете се со спецификаторот за конверзија %d да испечатите букви на следниот начин:
    //printf(“%d”, ‘A’) /* karakteri se koristat vo edinecni navodnici */
    //Што се случува кога се печатат следните карактери: b  c  0  1  2  $  *  +  / и празно место?

//    printf("%d\n", 'A');
//    printf("%d\n", 'b');
//    printf("%d\n", 'c');
//    printf("%d\n", '0');

    //Se pecatat ASCII vrednostite na tie karakteri

    //4. Во примерот p03_01.c, во наредбата printf наместо спецификаторот за конверзија  %f, поставете го спецификаторот %d. Што се случува и зошто?

//    float result = 7.0 / 22.0;
//    printf("Rezultatot e %d\n", result);
//    return (0);

    //Se dobiva random broj poradi pogresna primena na klasifikatorot

    //5. Напиши програма која внесува радиус на круг и испечатува негова плоштина и периметар. За вредност на пи да се земе 3.14.

//    scanf("%d", &br1);
//
//    printf("A = %.2f\n", 3.14*br1*br1);
//    printf("C = %.2f", 3.14*br1*2);

    //6. Напишете програма која од стандардниот влез зема 5 букви и ги испечатува по следниот редослед: прво петтата, па третата, па втората, па првата, па четвртата буква. Пример:
    //vnesi pet bukvi
    //prva bukva: e
    //vtora bukva: i
    //treta bukva: b
    //chetvrta  bukva: n
    //petta bukva: p
    //Se dobi: pbien

//    scanf("%c %c %c %c %c", &b1,&b2,&b3,&b4,&b5);
//
//    printf("%c%c%c%c%c", b5,b3,b2,b1,b4);

    //7. Да се модифицира задачата p03_04.c за да дава излез на променливите total  и average со три децимални места.

//    float data[5];
//    float total;
//    float average;
//
//    data[0] = 34.0;
//    data[1] = 27.0;
//    data[2] = 45.0;
//    data[3] = 82.0;
//    data[4] = 22.0;
//    total = data[0] + data[1] + data[2] + data[3] + data[4];
//    average = total / 5.0;
//    printf("Vkupno %.3f Sredna vrednost %.3f\n", total, average);

    //8. Напиши 4 начини за да ја зголемиш вредноста на променливата x за 1.

//    int x = 0;
//
//    x++;
//    ++x;
//    x+=1;
//    x=x+1;
//
//    printf("%d", x);

    return 0;
}
