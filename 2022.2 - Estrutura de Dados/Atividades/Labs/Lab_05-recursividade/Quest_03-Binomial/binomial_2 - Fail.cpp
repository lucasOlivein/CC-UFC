#include <iostream>
using namespace std;
int binomial(int n, int k){
int aux = {};
    if(n == k)
        return 1;
    else if(k == 1)
        return n;
    else{
        if( k != 2)
            aux = binomial( n-1, k-1);
        else
            aux = (n - k + 1) + binomial( n-1, k);
        return aux;
    }
}


int main(){
    int n;
    int k;
    cin >> n;
    cin >> k;

    cout << binomial(n,k) << '\n';
}