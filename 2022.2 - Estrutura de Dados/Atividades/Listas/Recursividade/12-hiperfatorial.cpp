#include<iostream>

using namespace std;

unsigned long long int hiperfatorial(int n, int j = 1){
    unsigned long long int aux = {};
    if(n == 1)
        return 1;
    else if(j < n){
        return n * hiperfatorial(n, j+1);

    } else 
        return n * hiperfatorial(n-1);
}



int main(){
    int n;
    cin  >> n;

    cout << "Numero ----> " << hiperfatorial(n) << "\n\n";
}