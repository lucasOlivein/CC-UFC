#include "class.h"
void Empregado::print()
{
    cout << "Nome: " << name << endl;
}

void Empregado::setNome(string nome_)
{
    name = nome_;
}

EmpregadoAsslariado::EmpregadoAsslariado(string nome, float salario_)
{
    setNome(nome);
    salario = salario_;
}

float EmpregadoAsslariado::calcularSalario()
{
    cout << "Salario: " << salario << endl;
}

void EmpregadoAsslariado::print()
{
    Empregado::print();
    cout << calcularSalario() << '\n';
}

void EmpregadoAsslariado::setSalario(float salario_)
{
    salario = salario_;
}

EmpregadoHorista::EmpregadoHorista(string nome, int horas_, float valorHora_)
{
    setNome(nome);
    horas = horas_;
    valorHora = valorHora_;
}

float EmpregadoHorista::calcularSalario()
{
    if (horas <= 40)
    {
        cout << "Salario: " << horas * valorHora << "\n";
    }
    else
    {
        cout << "Salario: " << (40 / valorHora) + ((horas - 40) * valorHora * 1.5) << endl;
    }
}

void EmpregadoHorista::print()
{
    Empregado::print();
    cout << "Horas: " << horas << endl;
    cout << "Valor Hora: " << valorHora << endl;
}