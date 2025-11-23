#include "../cubo.h"

void Cubo::construir(){
    setNome("Cubo");
    setTipo("Tridimencional");

    apresentar();
    cout << "Digite o lado do cubo: "; cin >> lado;

    setArea( lado * lado * 6);
    setVolume(lado * lado * lado);
}