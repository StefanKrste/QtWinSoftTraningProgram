#include <iostream>
#include <list>

using namespace std;

int main(){

    //1. Креирај листа од 10000 случајни цели броеви co вредности од 0 до 9999. Потоа прикажи ги следните вредности:
    //-         број на парни елементи
    //-         број на елементи помали од 2000
    //-         број на елементи во интервал [2000, 4000)
    //-         број на елементи во интервал [4000, 6000)
    //-         број на елементи во интервал [6000, 8000)
    //-         број на елементи во интервал [8000, 10000)
    //-         средна вредност на елементите

    list<int> lista;
    int parni=0,pom2000=0,interval1=0,interval2=0,interval3=0,interval4=0,sum=0;

    for (int i = 0; i < 10000; i++) {
        int random = rand() % 10000;
        lista.push_back(random);
        sum+=random;
        if(random%2){
            ++parni;
        }
        if(random<2000){
            ++pom2000;
        }
        if(random>=2000 && random<4000){
            ++interval1;
        }
        if(random>=4000 && random<6000){
            ++interval2;
        }
        if(random>=6000 && random<8000){
            ++interval3;
        }
        if(random>=8000 && random<10000){
            ++interval4;
        }
    }

    for (int broj : lista) {
        cout << broj << " ";
    }
    cout << endl;

    cout<<"\nParni: "<<parni<<endl;
    cout<<"Pomali od 2000: "<<pom2000<<endl;
    cout<<"Elementi [2000, 4000): "<<interval1<<endl;
    cout<<"Elementi [4000, 6000): "<<interval2<<endl;
    cout<<"Elementi [6000, 8000): "<<interval3<<endl;
    cout<<"Elementi [8000, 10000): "<<interval4<<endl;
    return 0;
}