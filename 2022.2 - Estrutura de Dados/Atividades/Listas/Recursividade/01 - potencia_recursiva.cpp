#include <iostream>

using namespace std;


int potencia_recursiva(int n, int k){
    int acc = 1;
    if(k == 0)
        return 1;
    else {
        acc = n * potencia_recursiva(n, k-1);
        return acc;
    }
}


int main(){
    int n = {}, k={};

    cin >> n;
    cin >> k;

    cout << '\n' << "Resultado ------> " <<potencia_recursiva(n, k);
}