#include <iostream>
using namespace std;

int mdc_recursivo(int x, int y, int j=1){
    int aux = {};
    if( (j > x) || (j > y)){
        return 0;
    } else 
        if((x%j != 0) || (y%j !=0))
            return mdc_recursivo(x, y, j+1);
        else{
            aux = mdc_recursivo(x, y, j+1);
            if(j > aux)
                return j;
            else    
                return aux;

}}   

int main(){
    int x, y;
    cin >> x; 
    cin >> y;

    cout << mdc_recursivo(x, y);
}