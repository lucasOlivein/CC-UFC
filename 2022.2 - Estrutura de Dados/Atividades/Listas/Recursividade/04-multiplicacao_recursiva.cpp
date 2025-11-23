#include <iostream>
using namespace std;


int multiplicacao_recursiva(int x, int y){
    int acumulador = {};
    if(y ==0 )
        return 0;
    else {
        acumulador = x + multiplicacao_recursiva(x , y-1);
        return acumulador;
    }
}


int main(){
    int x, y;
    cin >> x;
    cin >> y;

    cout << "resultado ----> " << multiplicacao_recursiva(x, y) << "\n\n";
}