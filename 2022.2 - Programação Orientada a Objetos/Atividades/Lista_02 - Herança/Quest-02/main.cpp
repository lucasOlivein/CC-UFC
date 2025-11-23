#include <iostream>
using namespace std;


#include "carro_passeio_class.h"


int main(){
    CarroPasseio c = CarroPasseio(1000, 180, 40000, 8, 400, "azul", "esportivo");
    Veiculo v = Veiculo(1000, 180, 40000);
    c.print();

    v.print();
}