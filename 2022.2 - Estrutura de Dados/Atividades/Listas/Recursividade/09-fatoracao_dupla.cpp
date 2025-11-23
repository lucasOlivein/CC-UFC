#include <iostream>

using namespace std;

int fat_dupla(int n, int j=1){
    int aux = {};
    if(j > n)
        return 1;
    else 
        return (j * fat_dupla(n, j+2));
}


int main(){
    int n = {};

    cin >> n;
    if(n%2 == 0){
        cout << "Numero par \n\n";
        return 0;
    }
    cout << "Numero = " << fat_dupla(n) << '\n';
}