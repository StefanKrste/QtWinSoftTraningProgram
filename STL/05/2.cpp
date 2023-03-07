#include <iostream>
#include <list>

using namespace std;

int main(){

    //2. Дадени се три листи од e-mail адреси. Некои адреси се појавуваат само во една од листите, а некои се повторуваат и во другите листи. Напиши програма со која ќе се состави една листа во која ќе се содржат сите адреси по еднаш.

    list<string> l1 = {"email1@gmail.com","email2@gmail.com","email2@gmail.com","email3@gmail.com"};
    list<string> l2 = {"email4@gmail.com","email5@gmail.com","email2@gmail.com","email3@gmail.com"};
    list<string> l3 = {"email1@gmail.com","email2@gmail.com","email6@gmail.com","email7@gmail.com"};

    list<string> Site;
    Site.merge(l1);
    Site.merge(l2);
    Site.merge(l3);
    Site.sort();
    Site.unique();

    for (auto& x : Site) {
        cout << x << endl;
    }
    return 0;
}
