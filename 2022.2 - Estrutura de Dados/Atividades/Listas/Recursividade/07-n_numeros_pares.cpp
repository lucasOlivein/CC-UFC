#include <iostream>

using namespace std;

void n_numeros_pares(int n, int j=2){
    if(j>n)
        cout << "----------FIM---------\n\n";
    else{
        cout << "Numero = " << j << '\n';
        n_numeros_pares(n, j+2);
    }
}


int main(){
    int n;
    cin >> n;

    n_numeros_pares(n);
}