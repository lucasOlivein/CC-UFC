#include <iostream>
using namespace std;

void ordVet(int *vec, int n){
    int aux;
    for(int i=0; i<n; i++)
        for (int j=i; j<n; j++){
            if(vec[j] < vec[i]){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;         
            }    
    }  
}


int check(int *vacinas, int * pacientas, int n){
    bool s = true;

    for(int i=0; i<n; i++){
        if(vacinas[i] < pacientas[i]){
            cout << "No";
            return 1;
        }
    }

    cout << "Yes";
    
}


int main(){
    int n;
    cin >> n;
    int vacinas[500];
    int pacientes[500];

    for(int i=0; i<n; i++)
        cin >> vacinas[i];
    for(int i=0; i<n; i++)
        cin >> pacientes[i];
    ordVet(vacinas, n);
    ordVet(pacientes, n);

    check(vacinas, pacientes, n);

}