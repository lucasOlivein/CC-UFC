#include <iostream>
using namespace std;

#include "NumeroReal.h"

double operator+ (NumeroReal n1, NumeroReal n2 ){
    return n1.getNumero() + n2.getNumero();
}

double operator- (NumeroReal n1, NumeroReal n2){
    return n1.getNumero() - n2.getNumero();
}

double operator* (NumeroReal n1, NumeroReal n2){
    return n1.getNumero() * n2.getNumero();
} 

double operator/ (NumeroReal n1, NumeroReal n2){
    return n1.getNumero() / n2.getNumero();
}

bool operator> (NumeroReal n1, NumeroReal n2){
    return n1.getNumero() > n2.getNumero();
}
bool operator<(NumeroReal n1, NumeroReal n2){
    return n1.getNumero() < n2.getNumero();
}
bool operator>=(NumeroReal n1, NumeroReal n2){
    return n1.getNumero() >= n2.getNumero();
}
bool operator<=(NumeroReal n1, NumeroReal n2){
    return n1.getNumero() <= n2.getNumero();
}
bool operator!=(NumeroReal n1, NumeroReal n2){
    return n1.getNumero() != n2.getNumero();
}
bool operator==(NumeroReal n1, NumeroReal n2){
    return n1.getNumero() == n2.getNumero();
}



int main(){
    NumeroReal n1(5.6), n2(4.6);

    cout <<"/////////////////Operadores Aritimeticos////////////\nA soma entre os numeros eh: " <<  n1+n2 << '\n';
    cout <<"A diferenca entre os NumerosReais eh: " <<n1-n2 << '\n';
    cout <<"O produto entre os Reais eh: " << n1*n2 << '\n';
    cout <<"A razao entre os Reais eh: " << n1/n2 << '\n';

    cout<< "\n/////////////Relacionais/////////////\nN1 > N2: " << (n1>n2) << '\n';
    cout<< "N1 < N2: " << (n1<n2) << '\n';
    cout<< "N1 >= N2: " << (n1>=n2) << '\n';
    cout<< "N1 <= N2: " << (n1<=n2) << '\n';
    cout<< "N1 == N2: " << (n1==n2) << '\n';
    cout<< "N1 != N2: " << (n1!=n2) << '\n';



}

