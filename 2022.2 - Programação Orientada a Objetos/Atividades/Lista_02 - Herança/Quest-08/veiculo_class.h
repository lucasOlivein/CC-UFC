#pragma once
#include <iostream>
using namespace std;
class Veiculo{
    private:
        string marca;
        string modelo;
        string cor;
        float potencia;
        int portas;
        int assentos;

    public:
        Veiculo();
        Veiculo(string, string, string, float, int, int);
       
        void print();

            ////////////////getters-setters/////////////
        string getMarca() const { return marca; }
        void setMarca(const string &marca_) { marca = marca_; }

        string getModelo() const { return modelo; }
        void setModelo(const string &modelo_) { modelo = modelo_; }

        string getCor() const { return cor; }
        void setCor(const string &cor_) { cor = cor_; }

        float getPotencia() const { return potencia; }
        void setPotencia(float potencia_) { potencia = potencia_; }

        int getPortas() const { return portas; }
        void setPortas(int portas_) { portas = portas_; }

        int getAssentos() const { return assentos; }
        void setAssentos(int assentos_) { assentos = assentos_; }      

};