#include <iostream>
using namespace std;
class NotaFiscal{
  private:
    string numeroPecas;
    string descriPecas;
    int quantComprada;
    float preco;

  public:
    NotaFiscal();
    NotaFiscal(string, string, int, float);

    void setNumeroPecas(const string &numeroPecas_);
    void setDescriPecas(const string &descriPecas_);
    void setQuantComprada(int quantComprada_);
    void setPreco(float preco_);


    string getNumeroPecas() const;
    string getDescriPecas() const; 
    int getQuantComprada() const; 
    float getPreco() const; 

    static float getTotalNota(NotaFiscal[], int);
    

    
};