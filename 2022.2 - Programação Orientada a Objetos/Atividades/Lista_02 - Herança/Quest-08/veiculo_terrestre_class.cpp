#include "veiculo_terrestre_class.h"

VeiculoTerrestre::VeiculoTerrestre(string marca, string modelo, string cor, float potencia, int portas, int assentos, int rodas, bool estepe, string num_placa, int ano ) :Veiculo(marca, modelo, cor, potencia, portas, assentos)
{
  
  setRodas(rodas);
  setEstepe(estepe);
  setNumPlaca(num_placa);
  setAno(ano);

}; 

VeiculoTerrestre::VeiculoTerrestre(){

};


void VeiculoTerrestre::print(){
  cout << "Numero de Rodas: " << getRodas() << '\n';
  cout << "Estepe: " << getEstepe() << '\n';
  cout << "Ano: " <<getAno() << '\n';
  cout << "Placa: " << getNumPlaca() << '\n';
}