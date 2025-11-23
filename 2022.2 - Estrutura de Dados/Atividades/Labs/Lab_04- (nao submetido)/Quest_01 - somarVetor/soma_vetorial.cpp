#include <iostream>
#include <stdio.h>

using namespace std;

int soma_recursiva(int *x, int i){  // recebe um vetor e o lenth desse vetor
    int acumulador = {};

    if(i <= 0)
        return 0; // condicao de parada
    else if(x[i-1] > 0) // para os numeros maiores que zero
        {
            acumulador = x[i-1] + soma_recursiva(x, i-1); // o acumulador recebe o valor da ultima posicao do vetor
            return acumulador;                              // mais a recursao com o lenth do vetor decrecido em 1
        } else {
            return soma_recursiva(x, i-1); // para os numeros menor ou igual a zero pula; passa o vetor com leth menos 1.
        }
}


int main(){
    int n[] = {1,0, 1, 1, 0, -6, -6 ,-7, -9, -2, 1}; // Vetor
    int i = sizeof(n)/sizeof(n[0]); // calcula o numero de posicoes do vetor


    cout << soma_recursiva(n, i) << " -> resultado \n"; // printa o resultado
}