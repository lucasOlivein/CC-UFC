#include "../child_triangulo.h"


void Triangulo::construir(){
    
    setNome("Triangulo");
    setTipo("Bidimencional");
    apresentar();
    cout << "Digite a base: "; cin >> base;
    cout << "Digite a altura: "; cin >> altura;
    setArea((base*altura)/2);
}

void Triangulo::setAltura(float altura_){
    altura = altura_;
}

float Triangulo::getAltura(){
    return altura;
}

void Triangulo::setBase(float base_){
    base = base_;
}

float Triangulo::getBase(){
    return base;
}