#include "empresa_class.h"
class Restaurante:public Empresa{
    private:
        string comida;
        float preco;

    public:
        Restaurante(string, string, string, string, string, string);

        void print();

        void setComida(string);
        void setPreco(float);

        string getComida();
        float getPreco();

};
