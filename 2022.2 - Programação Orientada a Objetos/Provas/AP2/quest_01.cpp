#include <iostream>
using namespace std;

class Empregado
{
private:
    string nome;

public:

    virtual float calcularSalario(){
        return 0;
    }
    virtual void print(){
        cout << "Nome:: " << nome;
        cout << "Salario:: " <<  calcularSalario() << '\n';
    }
    string getNome(){
        return nome;
    }

};

class EmpregadoAsslariado: Empregado{
    private:
        float salario;
    public:
       float calcularSalario(){
            return salario;
       }
       void print(){
            cout << "Nome:: " << getNome();
            cout << "\nSalario:: "<< calcularSalario()<< endl; 
       } 
};

class EmpregadoHorista: Empregado{
    private:
        int horas;
        float valorHora;
    public:
        float calcularSalario(){
            if(horas <= 40){
                return horas*valorHora;
            }
            if(horas > 40){
                float aux;

                aux = (40/valorHora);
                aux += (horas-40)*(valorHora*1.5);

                // aux == (40/valorHora)+((horas-40)*(valorHora*1.5));
                return aux;
            }

        }
        void print(){
            cout << "Nome:: "<< getNome();
            cout << "Horas:: " << horas<< '\n';
            cout << "ValorHora:: " << valorHora << '\n';
            cout << "Salario:: " << calcularSalario();
        }
};

