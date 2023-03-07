#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(){

    //3. Формирај deque d од цели броеви. Потоа формирај vector v од елементите на d, но во обратен редослед.

    vector <int> v;
    deque <int> d = {1,2,3,4,5,6,7,8,9};

    v.resize(d.size());

    for ( int i = 0; i < d.size(); ++i )
        v[d.size()-(i+1)]=d[i];

    for (auto& x : v) {
        cout << x << " ";
    }
    return 0;
}
