#include <iostream>

using namespace std;



int soma_de_digito_recursiva(int n){ //soma os cada numero de um numero.
    int acumulador = {};
    cout << "Exec ---> " << n%10 << "\n\n";
    if(int (n/10) < 1)
        return n%10;
    else {
        acumulador =  ((n%10) +  soma_de_digito_recursiva( int (n/10)));
        return acumulador;
    }

}

int main(){
    int n = {};

    cin >> n;

    cout << soma_de_digito_recursiva(n) << " ---> Resultado \n\n";


}