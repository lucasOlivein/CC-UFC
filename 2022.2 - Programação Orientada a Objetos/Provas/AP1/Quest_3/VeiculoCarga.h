#include "Veiculo.h"

class VeiculoCarga: virtual public Veiculo{
    private:
      float carga;

    public:
      
      float getCarga() const { return carga; }
      void setCarga(float carga_) { carga = carga_; }

      float pesoPotencia( );
      void print();

};