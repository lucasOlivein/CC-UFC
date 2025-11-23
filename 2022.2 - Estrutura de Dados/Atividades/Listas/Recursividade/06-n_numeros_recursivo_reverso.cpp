#include <iostream>

using namespace std;

void n_nemeros_recursivo_reverso(int n){
    if(n < 0)
        cout << "----------FIM-----------\n\n";
    else{
        cout << "Numero = " << n << '\n';
        n_nemeros_recursivo_reverso(n-1);
    }
}

int main(){
    int n;
    cin >> n;
    n_nemeros_recursivo_reverso(n);
}