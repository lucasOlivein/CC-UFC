#include "../child_circulo.h"

void Circulo::construir(){
    setNome("Circulo");
    setTipo("Bidimencional");
    apresentar();
    cout << "Digite o Raio: "; cin >> raio;

    setArea(3.14 * raio * raio);
}

