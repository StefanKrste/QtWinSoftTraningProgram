#include <iostream>
#include <vector>

using namespace std;

int main(){

    //1. Креирај два вектори со случаен број на елементи кој е во интервалот [1, 1000). Потоа ископирај го вториот вектор во првиот со copy. Претходно провери дали првиот вектор има големина поголема или еднаква на големината на првиот. Ако не е, да се изврши фрлање на исклучок пред да се изврши копирањето на векторот. Постапката да се повторува во циклус во кој е сместена try-catch секвенца.
    srand(time(NULL));
    int r;

    while(true) {
        r=rand() % 999 + 1;
        vector<int> v1(r);
        r = rand() % 999 + 1;
        vector<int> v2(r);
        try {
            if (v1.size() >= v2.size()) {
                copy(v2.begin(), v2.end(), v1.begin());
                cout << "Uspesno kopiranje na v2 vo v1 " << v2.size()<<"<"<<v1.size()<<endl;
                break;
            }
            throw exception();
        } catch (exception &exception) {
            cout << "v2 e pogolem od v1 " << v2.size() << ">" << v1.size() << endl;
        }
    }

    return 0;
}