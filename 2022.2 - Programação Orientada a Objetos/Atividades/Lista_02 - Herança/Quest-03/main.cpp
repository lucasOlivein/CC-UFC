#include <iostream>
using namespace std;


#include "caminhao_class.h"


int main(){
    Caminhao c = Caminhao(1000, 180, 40000, 8, 400, 3, 27);
    Veiculo v = Veiculo(1000, 180, 40000);
    c.print();

    //v.print();
}