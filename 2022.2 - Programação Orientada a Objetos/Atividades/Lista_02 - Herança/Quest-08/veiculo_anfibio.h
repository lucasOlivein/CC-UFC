#include"veiculo_aquatico_class.h"
#include "veiculo_terrestre_class.h"
#include "veiculo_class.h"

class VeiculoAnfibio: public VeiculoTerrestre, public VeiculoAquatico{
  private:
    string classe;
    float max_velocidade;
    string popular;

  public:
    VeiculoAnfibio(){};
    VeiculoAnfibio(string, string, string, float, int, int, string, string, bool, bool, bool, string, int, bool, string, int, string, int, string);

    void print();

    void setClass(string classe_){
      classe = classe_;
    }
    float maxVelocidade(){ return max_velocidade; }
    void setMaxVelocidade(float max){
      max_velocidade = max;
    }
    void setPopular(string pop){
      popular = pop;
    }


    string getClass(){
      return classe;
    }
    float getMaxVelocidade(){
      return max_velocidade;
    }
    string getPopular(){
      return popular;
    }

    void Construir();


  
};