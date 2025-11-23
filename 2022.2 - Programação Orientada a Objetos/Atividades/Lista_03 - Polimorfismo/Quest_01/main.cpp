#include "class/child_bidimencional/child_quadrado.h"
#include "class/child_bidimencional/child_triangulo.h"
#include "class/child_bidimencional/child_circulo.h"
#include "class/child_tridimencional/esfera.h"
#include "class/child_tridimencional/cubo.h"
#include "class/child_tridimencional/tetraedro.h"



#include <iostream>
using namespace std;

int main(){

    int aux = {};
    bool lop= true;


    

    Forma *forma[10];
    forma[0] = new Quadrado();
    forma[1] = new Triangulo();
    forma[2] = new Circulo();
    forma[3] = new Esfera();
    forma[4] = new Cubo();
    forma[5] = new Tetraedro();

    for(int i=0; i<6; i++){
        forma[i]->construir();
        forma[i]->imprimir();
        delete forma[i];
    }



    /* q[0] = new Quadrado();
    q[0]->imprimir();
    delete q[0];
    t[0] = new Triangulo();
    t[0]->imprimir();
    delete t[0];

    c[0] = new Circulo();
    c[0]->imprimir();
    delete c[0];
    
    Esfera *e[2];
    e[0] = new Esfera();
    e[0]->imprimir();
    delete e[0];

    Cubo *cubo[2];
    cubo[0] = new Cubo();
    cubo[0]->imprimir();
    delete cubo[0];

    Tetraedro *te[2];
    te[0] = new Tetraedro();
    te[0]->imprimir();
    delete te[0];
*/


}

