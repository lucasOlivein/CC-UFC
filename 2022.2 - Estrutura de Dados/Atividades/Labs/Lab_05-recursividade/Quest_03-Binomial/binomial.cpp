#include <iostream>

using namespace std;


int binomial(int n, int k, int i = 0){
    int aux = {};
    if( n == k || k == 0){
        return 1; 
    }else {
        aux = binomial(n-1, k)+binomial(n-1 , k-1);
        return aux;

    }
}

int main(){
    int n;
    int j;

    cin  >> n;
    cin >> j;

    cout << binomial(n, j);
}