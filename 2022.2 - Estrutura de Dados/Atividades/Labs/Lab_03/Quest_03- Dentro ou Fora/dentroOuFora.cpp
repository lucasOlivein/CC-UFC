#include <iostream>

using namespace std;


struct Ponto{
    float x;
    float y;
};




void retangulo(Ponto a, Ponto b,Ponto coord){
    if((a.y >= coord.y) && (b.y <= (coord.x))){
        if((b.x>= coord.x) && (a.x<=coord.y))
            cout << "Ponto dentro do retângulo" << endl;
}   else
            cout << "Ponto fora do retângulo" << endl;
    }  

int main(){
    Ponto a; // Ponto Superior Esquerdo
    Ponto b;   // Ponto Inferior Direito
    Ponto cood;

    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> cood.x >> cood.y;

    retangulo(a, b, cood);
        
    
        

    return 0;
}