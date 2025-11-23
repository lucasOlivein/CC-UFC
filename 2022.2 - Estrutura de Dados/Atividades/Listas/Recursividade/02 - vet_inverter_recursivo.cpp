#include <iostream>

using namespace std;


void vet_inverter_recursivo(int vet[], int i, int j =0){
    int aux = {};
    if( i == 0){
        cout << "-----------Chegou ao final--------\n\n\n";
    } else{
        aux = vet[i-1];
        vet_inverter_recursivo(vet, (i-1), (j+1));
        vet[j] = aux; 
    }
}

int main(){
    int vet[] = {1,2,3,4,5,6,7,8};
    int i = sizeof(vet)/sizeof(vet[1]);
    vet_inverter_recursivo(vet, i);

    cout << "O vetor invertido ---> {";
    for(int k=0; k<i; k++)
        cout << vet[k] << "," ;
    cout << "}\n\n";


}