#include "class.h"
using namespace std;

double quotient(int numerator, int denominator)
{
    if (denominator == 0)
        throw DivideByZeroException();

    return static_cast<double>(numerator) / denominator;
}

int main()
{   
    Empregado *emp_a = new EmpregadoAsslariado("Teste 1", 1);
    Empregado *emp_hor = new EmpregadoHorista("Teste 1 2", 1, 2);
    try
    {
        emp_a->print();
        cout << '\n';
        emp_hor->print();
        cout << '\n';

        cout <<"O quociente eh: " << quotient(10, 2);

    }
    catch (DivideByZeroException &a)
    {
        cout << a.what();
    }
}