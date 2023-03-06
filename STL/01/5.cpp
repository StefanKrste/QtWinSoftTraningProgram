#include <iostream>

using namespace std;

template< class T >
class Array{
public:
    Array( int = 10 );
    ~Array(){
        delete [] arrayPtr;
    }
    void setEl( T , int );
    T getEl( int );
    void ispecati() const;
private:
    int size;
    T *arrayPtr;
};

template< class T >

Array< T >::Array( int s ){
    size = s > 0 ? s : 10;
    arrayPtr = new T[ size ];
    for (int i = 0; i < size; i++) {
        arrayPtr[i]=0;
    }
}

template< class T >
void Array< T >::setEl(T pushValue , int pozicija){
    arrayPtr[pozicija] = pushValue;
}

template< class T >
T Array< T >::getEl(int pozicija){
    return arrayPtr[pozicija-1];
}

template<class T>
void Array<T>::ispecati() const{
    for(int i = 0; i < size; i++){
        cout << arrayPtr[i] << " ";
    }
    cout << endl;
}

using namespace std;

int main(){

    //5. Напиши програма која содржи class template Array со која може да се инстанцира поле од било кој тип. Класата треба да содржи функции членки за сместување и преземање на вредност на елемент од полето. Да се демонстрира создавање на објекти за int и double тип.

    const int aCount = 5;
    const int bCount = 7;
    int pozicija,intBroj;
    double doubleBroj;

    Array<int> a(aCount);
    Array<double> b(bCount);

    cout<<"Popolni INT nizata: ";

    for (int i = 0; i < aCount; ++i) {
        cin>>intBroj;
        a.setEl(intBroj,i);
    }

    cout<<"Pozicija na citanje vo INT nizata: ";
    cin>>pozicija;
    if(pozicija>0 && pozicija<aCount) {
        cout << "Na taa pozicija ze naoga vrednosta " << a.getEl(pozicija) << endl;
    } else{
        cout << "Vneseniot broj e pogolem od dolzinata na nizata ili e pomal od 1";
    }
    a.ispecati();

    cout<<"Popolni DOUBLE nizata: ";

    for (int i = 0; i < bCount; ++i) {
        cin>>doubleBroj;
        b.setEl(doubleBroj,i);
    }

    cout<<"Pozicija na citanje vo DOUBLE nizata: ";
    cin >> pozicija;
    if(pozicija>0 && pozicija<aCount) {
        cout<<"Na taa pozicija ze naoga vrednosta "<< b.getEl(pozicija) <<endl;
    }else{
        cout << "Vneseniot broj e pogolem od dolzinata na nizata ili e pomal od 1";
    }
    b.ispecati();

    return 0;
}