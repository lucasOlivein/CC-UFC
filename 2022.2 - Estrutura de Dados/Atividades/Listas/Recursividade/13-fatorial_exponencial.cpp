#include <iostream>

using namespace std;

int expoente(int n){
    if(n==1)
        return n;
    else{
        return n * expoente(n-1);
    }
}

unsigned long long int fatorial_exponencial(int n, int j = 1, int i = {}){
    int aux = {};
    if(i == 1)
        return n;
    else if(j ==1 ){
        aux = expoente(n-1);
        cout << "o valor do expoente eh: " << aux << endl;
        return (n * fatorial_exponencial(n, 2, aux-1));
        cout << "1º Looping \n";
    }else{
        return (n * fatorial_exponencial(n, 2, i-1));
    }
}


int main(){
    int n;
    cin  >> n;

    cout << "Numero -------> " << fatorial_exponencial(n) << '\n';
}