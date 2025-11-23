#include<iostream>

using namespace std;


void n_numeros_primos(int n, int j=0){
    int aux = {};
    if(j > n)
        cout << "---------FIM--------";
    else{
        int i ={};
        for(i= 1; i< j; i++)
            if(j%i == 0)
               aux = i;
            if(aux == 1 )
                cout << "Numero Primo = " << i << '\n';
        n_numeros_primos(n, j+1);
}
}

int main(){
    int n;
    cin >> n;

    n_numeros_primos(n);
}