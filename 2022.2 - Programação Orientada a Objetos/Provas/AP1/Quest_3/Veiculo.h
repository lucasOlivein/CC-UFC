#include <iostream>
using namespace std;

class Veiculo{
  private:
    string nome;
    float peso;
    float potencia;

  public:
    string getNome();
    void setNome( string nome_);

    float getPeso();
    void setPeso(float peso_);

    float getPotencia() ;
    void setPotencia(float potencia_);

    void print();  
      
};