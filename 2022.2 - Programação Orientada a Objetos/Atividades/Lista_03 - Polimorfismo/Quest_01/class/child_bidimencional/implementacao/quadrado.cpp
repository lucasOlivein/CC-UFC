#include "../child_quadrado.h"


void Quadrado::construir(){
    setNome("Quadrado");
    setTipo("Bidimencional");
    apresentar();
    cout << "Digite o lado: "; cin >> lado;
    setArea(lado*lado);
    
}


