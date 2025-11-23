#include <iostream>
using namespace std;

void ordVet(int *vec, int *res, int n){
    int aux;
    for(int i=0; i<n; i++)
        for (int j=i; j<n; j++){
            if(vec[j] < vec[i]){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;   
                aux = res[i];
                res[i] = res[j];
                res[j] = aux;           
            }    
    }  
}


int main(){
    int n;
    cin >> n;

    int vec[106];
    int res[106];

    for(int i=0; i<n; i++){
        res[i] = i;
        cin >> vec[i];
    }

    ordVet(vec, res, n);

    for(int i=0; i<n-1; i++)
        cout << res[i] << " ";
    cout << res[n-1];
}