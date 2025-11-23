#include<iostream>

using namespace std;


void n_numeros(int n, int j = 0){
    if(j > n)
    cout << "\n-----------FIM-------------\n\n";
    else{
        cout <<"Numero = " << j << "\n";
        n_numeros(n, j+1);
    }
}


int main(){
    int n;
    cin >> n;
    n_numeros(n);
}