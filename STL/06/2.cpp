#include <iostream>
#include <queue>

using namespace std;

int main(){

    //2. Во еден систем пристигнуваат процеси кои треба да бидат опслужени. Секој процес има идентификационен број и приоритет. Напиши прграма која за внесена листа на процеси и приоритети ќе прикаже по кој редослед тие ќе бидат опслужени.

    priority_queue<pair<int, int>> pq;

    int n, id, prioritet;
    cout << "Broj na procesi: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Vnesi id na proces " << i + 1 << ": ";
        cin >> id;
        cout << "Prioritet: ";
        cin >> prioritet;
        pq.push(make_pair(prioritet, id));
    }
    cout << "Redosled na opsluzuvanje: ";
    while (!pq.empty()) {
        cout << pq.top().second << " ";
        pq.pop();
    }

    return 0;
}