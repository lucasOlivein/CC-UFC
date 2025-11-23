#include "VeiculoCarga.h"
#include "VeiculoPasseio.h"

class VeiculoUtilitario: public VeiculoCarga, public VeiculoPasseio{
    public:
      float pesoPotencia();
      void print();
};

