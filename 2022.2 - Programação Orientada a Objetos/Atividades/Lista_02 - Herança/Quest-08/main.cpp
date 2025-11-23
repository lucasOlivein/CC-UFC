#include<iostream>
using namespace std;

#include "veiculo_anfibio.h"

int main(){


VeiculoAnfibio f = VeiculoAnfibio("Fiat", "New Anf", "White", 300, 4, 4, "Anfibio", "Lago", false, false, true, "gasolina", 4, false, "BR-41602", 2022, "Hibrido", 400, "Nao" );
 f.print();

VeiculoAnfibio *v = new VeiculoAnfibio();

 cout << "Adicionar novo veiculo?\n1: Sim\n2: Nao\n";
 int r ={};

 cin >> r;

 if(r == 1){
  VeiculoAnfibio *v = new VeiculoAnfibio();
  string aux;
  float aux1;
  bool aux2;

  //////////VEICULO//////
  cout << "Marca: "; cin >> aux; v->setMarca(aux);
  cout << "Modelo: "; cin >> aux; v->setModelo(aux);
  cout << "Cor: "; cin >> aux; v->setCor(aux);       
  cout << "Potencia: "; cin >> aux1; v->setPotencia(aux1);
  cout << "Portas: "; cin >> aux1; v->setPortas(aux1);
  cout << "Assentos: "; cin >> aux1; v->setAssentos(aux1);
  /////////VEICULO AQUATICO //////////////
  cout << "Meio: "; cin>>aux; v->setMeio(aux);
  cout << "Proa: "; cin >> aux; v->setProa(aux2);
  cout << "Mastro: "; cin >> aux; v->setMastro(aux2);
  cout << "Motor: "; cin >> aux2; v->setMotor(aux2);
  cout << "Tipo do Motor: "; cin>> aux; v->setMotorTipo(aux);
////////////VEICULO TERRESTRE////////////////
  cout << "Rodas: "; cin >> aux1; v->setRodas(aux1);
  cout << "Estepe: "; cin >> aux2; v->setEstepe(aux2);
  cout << "Numero da placa: "; cin>> aux; v->setNumPlaca(aux);
  cout << "Ano: "; cin >> aux1; v->setAno(aux1);
  ///////////////////VEICULO ANFIBIO////////////
  cout << "Classe: "; cin >> aux; v->setClass(aux);
  cout << "Velocidade Maxima: "; cin >> aux1; v->setMaxVelocidade(aux1);
  cout << "Popular: ";cin >> aux; v->setPopular(aux);

  cout << "Veiculo Registrado\nMostrar Informacoes?\n1: Sim\n2: Nao\n"; cin >> r;
  if(r == 1)
    v->print();

 } else
  delete v;
  return 0;



}