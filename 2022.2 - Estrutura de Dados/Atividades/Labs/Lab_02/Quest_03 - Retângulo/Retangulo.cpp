#include <iostream> 
#include <iomanip>
#include <cmath>
using namespace std;

struct Retangulo{

    float supEsqX;
    float supEsqY;
    float infDirX;
    float infDirY;

};


void Exibir(float supEsq, float infDir){
    float area = supEsq * infDir;
    float diagonal = sqrt((infDir*infDir)+(supEsq*supEsq));
    float perimetro = 2*(supEsq) + 2*(infDir);

    cout << fixed << setprecision(2);
    cout << "Área do Retângulo: " << area << endl;
    cout << "Diagonal do Retângulo: " << diagonal << endl;
    cout << "Perimetro do Retângulo: " << perimetro << endl;
}


int main(){
    Retangulo ret;

    cin >> ret.supEsqX;
    cin >> ret.supEsqY;
    cin >> ret.infDirX;
    cin >> ret.infDirY;

    Exibir(((ret.infDirX - ret.supEsqX)), (ret.supEsqY - ret.infDirY));
    return 0;
}