#include <iostream>

using namespace std;

int fatoracao_quadrupla(int n, int j=1){
    if(j > 2*n)
        return 1;
    else if(j > n){
        return (j * fatoracao_quadrupla(n, j+1));
    }else {
        fatoracao_quadrupla(n, j+1);
    }

    

    
}


int main(){
    int n;
    cin >> n;

    cout << "Numero = " << fatoracao_quadrupla(n) << '\n';
}