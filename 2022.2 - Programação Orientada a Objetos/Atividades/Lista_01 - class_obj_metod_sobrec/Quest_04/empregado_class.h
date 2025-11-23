#include <iostream>
using namespace std;

class Empregado{
  private:
    string nome;
    string sobrenome;
    float salario;

  public:
    Empregado(string, string, float);
    float salarioAnual();
    void aumentarSalario(int);
    
    void setNome(const string &nome_);
    void setSobrenome(const string &sobrenome_);
    void setSalario(float salario_); 

    string getNome() const ;
    string getSobrenome() const ;
    float getSalario() const;

    
    


  
};