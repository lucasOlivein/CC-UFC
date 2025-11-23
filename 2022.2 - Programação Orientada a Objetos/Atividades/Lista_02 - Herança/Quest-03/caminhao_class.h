
#include "motor_class.h"
#include "veiculo_class.h"

class Caminhao: Veiculo, Motor{
    private:
        float toneladas;
        float altura;
        float comprimento;
    public:
        Caminhao(float, float, float, int, int, float, float);

        void print();

        void setToneladas(float);
        void setAltura(float);
        void setComprimento(float);

        float getToneldas();
        float getAltura();
        float getComprimento();
};