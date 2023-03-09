#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main(){

    //2. Напиши програма за играње на едноставна игра со карти која ги има следните правила: шпилот од 52 карти се меша и се делат картите на сите играчи подеднакво. Добива оној играч што има најголем збир.
    //а) Вредностите на картите се од 1 до 14 соодветно, без разлика на бојата, А има вредност 1.
    //б) Вредностите на картите се од 1 до 14 соодветно, А има вредност 1. Картите срце се бројат двојно.
    //На почетокот на играта да се внесе бројот на играчи. Во излезот да се прикажат картите и збирот што ги добил секој играч.
    //Со среќа!.

    vector<pair<string, char>> karte_vec = {
            {"srce", 'A'}, {"srce", '2'}, {"srce", '3'}, {"srce", '4'}, {"srce", '5'}, {"srce", '6'}, {"srce", '7'}, {"srce", '8'}, {"srce", '9'}, {"srce", 'T'}, {"srce", 'J'}, {"srce", 'Q'}, {"srce", 'K'},
            {"detelina", 'A'}, {"detelina", '2'}, {"detelina", '3'}, {"detelina", '4'}, {"detelina", '5'}, {"detelina", '6'}, {"detelina", '7'}, {"detelina", '8'}, {"detelina", '9'}, {"detelina", 'T'}, {"detelina", 'J'}, {"detelina", 'Q'}, {"detelina", 'K'},
            {"list", 'A'}, {"list", '2'}, {"list", '3'}, {"list", '4'}, {"list", '5'}, {"list", '6'}, {"list", '7'}, {"list", '8'}, {"list", '9'}, {"list", 'T'}, {"list", 'J'}, {"list", 'Q'}, {"list", 'K'},
            {"baklava", 'A'}, {"baklava", '2'}, {"baklava", '3'}, {"baklava", '4'}, {"baklava", '5'}, {"baklava", '6'}, {"baklava", '7'}, {"baklava", '8'}, {"baklava", '9'}, {"baklava", 'T'}, {"baklava", 'J'}, {"baklava", 'Q'}, {"baklava", 'K'}
    };

    random_device rd;
    default_random_engine rng(rd());

    shuffle(karte_vec.begin(), karte_vec.end(), rng);

    int igraci,brojKarti,igrac=1,vkupnoA=0,vkupnoB=0,pom=0,vrednostNaKarta;
    cout<<"Vnesi broj na igraci: ";
    cin>>igraci;
    brojKarti=52/igraci;
    if(igraci<2 || igraci>52){
        cout<<"Potrebno e da ima povekje od 1 igrac i pomalce od 52 za da moze da se realizira igrata"<<endl;
        return 0;
    }
    cout<<"\nIgracot "<<igrac<<" gi ima slednive karti: "<<endl;
    for (auto x : karte_vec){
        if(pom==brojKarti){
            if(igrac==igraci){
                break;
            }
            cout<<endl;
            pom=0;
            cout<<"Vkupno A za igracot "<<igrac<<" : "<<vkupnoA<<endl;
            cout<<"Vkupno B za igracot "<<igrac<<" : "<<vkupnoB<<endl;
            ++igrac;
            vkupnoA=0;
            vkupnoB=0;
            cout<<"\nIgracot "<<igrac<<" gi ima slednive karti: "<<endl;
        }
        cout <<x.second<<"-"<<x.first<<" ";
        if(x.second=='K'){
            vrednostNaKarta=13;
        }else if(x.second=='Q'){
            vrednostNaKarta=12;
        }else if(x.second=='J'){
            vrednostNaKarta=11;
        }else if(x.second=='T'){
            vrednostNaKarta=10;
        }else if(x.second=='A'){
            vrednostNaKarta=1;
        }else {
            vrednostNaKarta=(x.second-'0');
        }
        vkupnoA+=vrednostNaKarta;
        if(x.first=="srce"){
            vkupnoB+=(2*vrednostNaKarta);
        }else{
            vkupnoB+=vrednostNaKarta;
        }
        pom++;
    }
    cout<<endl;
    cout<<"Vkupno A za igracot "<<igrac<<" : "<<vkupnoA<<endl;
    cout<<"Vkupno B za igracot "<<igrac<<" : "<<vkupnoB<<endl;
    return 0;
}