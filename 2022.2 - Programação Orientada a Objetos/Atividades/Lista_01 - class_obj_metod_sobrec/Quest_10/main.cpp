#include <iostream>
using namespace std;

#include "NumeroReal.h"

double operator+ (NumeroReal n1, int n2 ){
    return n1.getNumero() + n2;
}

double operator- (NumeroReal n1, int n2){
    return n1.getNumero() - n2;
}

double operator* (NumeroReal n1, int n2){
    return n1.getNumero() * n2;
} 

double operator/ (NumeroReal n1, int n2){
    return n1.getNumero() / n2;
}

bool operator> (NumeroReal n1, int n2){
    return n1.getNumero() > n2;
}
bool operator<(NumeroReal n1, int n2){
    return n1.getNumero() < n2;
}
bool operator>=(NumeroReal n1, int n2){
    return n1.getNumero() >= n2;
}
bool operator<=(NumeroReal n1, int n2){
    return n1.getNumero() <= n2;
}
bool operator!=(NumeroReal n1, int n2){
    return n1.getNumero() != n2;
}
bool operator==(NumeroReal n1, int n2){
    return n1.getNumero() == n2;
}



int main(){
    NumeroReal n1(5.6);
    int n2 = 3;
    cout << "Para Numero Real n1 = " << n1.getNumero() << " e inteiro n2 = " << n2 << "\n\n";
    cout <<"/////////////////Operadores Aritimeticos////////////\nA noma entre os numeros eh: " <<  n1+n2 << '\n';
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

