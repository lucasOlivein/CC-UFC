#include <iostream>

using namespace std;

int superfatorial(int n, int j = 1){ // retorna n! * (n-1) ! * (n-2)! ... 1;
    int aux = {};
    if( n == 1)
        return 1;
    else if( j < n) { 
       return (j * superfatorial(n, j+1));
    } else{
        return n * superfatorial(n-1);
    }
}

int main()
{
    int n;
    cin >> n;

    cout << "Numero = " << superfatorial(n) << '\n';
}