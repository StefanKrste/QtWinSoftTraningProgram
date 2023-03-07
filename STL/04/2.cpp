#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    //2. Напиши програма што определува дали два збора се анаграми. Два збора се нарекуваат анаграми ако се состојат од исти букви (Пр. стакло и слатко). Притоа користи vector. За споредба  на еднаквост на два вектори може да се користи:
    //   std::equal( v1.begin(), v1.end(), v2.begin() );
    //   која враќа bool вредност.

    string s1,s2;

    cout<<"Vnesi go PRV zbor: "<<endl;
    cin>>s1;

    cout<<"Vnesi go VTOR zbor: "<<endl;
    cin>>s2;

    vector<char> v1(s1.size());
    copy(s1.begin(), s1.end(), v1.begin());

    vector<char> v2(s2.size());
    copy(s2.begin(), s2.end(), v2.begin());

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    if(equal( v1.begin(), v1.end(), v2.begin())){
        cout<<"Zborovite se anagrami";
    } else{
        cout<<"Zborovite ne se anagrami";
    }
    return 0;
}