#include <iostream>

using namespace std;

#include "Cilindro.h"

int main(){
  Cilindro c(4,8,5);  //RECEBE : BASE, ALTURA, RAIO;

  cout << "Area: " << c.Area() << '\n';
  cout <<"Volume: " << c.Volume() << '\n';

}