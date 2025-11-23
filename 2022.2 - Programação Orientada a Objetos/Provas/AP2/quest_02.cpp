#include <iostream>
#include <stdexcept>
using namespace std;

class DivideByZeroException : public runtime_error{
    public:
        DivideByZeroException():runtime_error("tentou divir por zero"){};
    
};

double quotient(int numerator, int denominator)
{
    if(denominator == 0)
        throw DivideByZeroException();

    return static_cast <double> (numerator / (float)denominator);
}

int main(){
    int numerator;
    int denominator;

    cout << "Numerador:: ";
    cin >> numerator;
    cout << "Denominator:: ";
    cin >> denominator;

    try{
        float result;
        result = quotient(numerator, denominator);
        cout << " [ Resultado:: " << result << " ] ";
    }catch(DivideByZeroException &e){
        cout << "[ Excecao:: " << e.what() << " ]";
    }
}
