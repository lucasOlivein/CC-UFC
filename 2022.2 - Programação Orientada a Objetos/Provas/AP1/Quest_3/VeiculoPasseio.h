#include "Veiculo.h"
class VeiculoPasseio: virtual public Veiculo{
  private:
    float volumeInterno;
  public:
    
    float getVolumeInterno(){ return volumeInterno; }
    void setVolumeInterno(float volumeInterno_) { volumeInterno = volumeInterno_; }
    
    float pesoPotencia();
    void print();
    

};