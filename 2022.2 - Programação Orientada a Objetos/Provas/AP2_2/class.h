#include <iostream>
#include <stdexcept>
using namespace std;


class Empregado
{
private:
    string name;

public:
    virtual float calcularSalario() = 0;
    virtual void print();
    void setNome(string nome_);
};


class EmpregadoAsslariado : public Empregado
{
private:
    float salario;

public:
    EmpregadoAsslariado(string nome, float salario_);
    virtual float calcularSalario();
    virtual void print();
    void setSalario(float salario_);
};


class EmpregadoHorista : public Empregado
{
private:
    int horas;
    float valorHora;

public: 
    EmpregadoHorista(string nome, int horas_, float valorHora_);
    virtual float calcularSalario();
    virtual void print();
};



class DivideByZeroException : public runtime_error
{
public:
    DivideByZeroException() : runtime_error("tentou dividir por zero") {

    }
};
