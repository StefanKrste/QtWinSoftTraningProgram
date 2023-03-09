#include <iostream>
#include <iomanip>
#include <valarray>

using namespace std;

int main(){

    //1. Табелирај ја вредноста на i, i2,  и за вредности на i=1,2,... n. Ведностите да бидат прикажани во колони со ширина m (за децималните вредности да се дефинира соодветна прецизност). Вредностите на n и m треба да се внесат на почетокот на програмата.

    int n,m;
    cout<<"Broj na elementi: "<<endl;
    cin>>n;
    cout<<"Sirina na koloni: "<<endl;
    cin>>m;

    cout.precision(3);
    for(int i=1;i<=n;++i){
        cout<<left<<setw(m)<<i;
        cout<<setw(m)<<pow(i, 2);
        cout<<setw(m)<<sqrt(i);
        cout<<setw(m)<<cbrt(i)<<endl;
    }
    return 0;
}