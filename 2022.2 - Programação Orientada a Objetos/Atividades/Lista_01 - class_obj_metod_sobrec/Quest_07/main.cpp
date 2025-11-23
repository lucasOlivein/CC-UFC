#include <iostream>
using namespace std;
#include "Tempo.h"

int main(){
    Tempo a(5,45,36);
    Tempo b(4,15,40);
    a.somar( a, b);

    cout << "Resultado: "; a.print(); cout <<"\n\n";

    a.subtrair(a,b);
    cout << "Resultado: "; a.print();

}


