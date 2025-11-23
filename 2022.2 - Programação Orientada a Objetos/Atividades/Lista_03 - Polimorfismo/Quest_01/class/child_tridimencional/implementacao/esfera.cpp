#include "../esfera.h"

#include <iostream>
using namespace std;

void Esfera::construir(){
    setNome("Esfera");
    setTipo("Tridimencional");

    apresentar();
    cout << "Digite o raio da esfera: "; cin >> raio;
    
    setArea(4 * 3.14 * raio * raio);
    setVolume(4/3 * 3.14 * raio * raio * raio);
}