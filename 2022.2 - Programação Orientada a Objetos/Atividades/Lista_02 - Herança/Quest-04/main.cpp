#include <iostream>
using namespace std;
#include "pacote_class.h"
#include "pacote_over_night.h"
#include "pacote_dois_dias_class.h"



int main(){
    PacoteDoisDias d = PacoteDoisDias("Lucas André", "Autran Moreno", "Quixada", "Ceara", "63900-061", "Aliexpress", "---", "---", "----", "----", -500, 100);
cout << d.calcularCusto() << "\n";
}