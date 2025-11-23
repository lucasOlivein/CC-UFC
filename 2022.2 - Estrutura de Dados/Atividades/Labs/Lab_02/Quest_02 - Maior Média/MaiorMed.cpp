#define numAlu 5
#include <iostream>
using namespace std;

struct Aluno {
    int Matricula;
    string nome;
    float nota[3];
};

float Media(float m1, float m2, float m3){
    float med = ((m1+m2+m3)/3);
    return med;
}

int main(){
    Aluno alu[numAlu];
    float maiorMedia = 0;
    int indice;

    for(int i=0; i<numAlu; i++){
        cin >> alu[i].nome;
        cin >> alu[i].Matricula;

        for (int j = 0; j < 3; j++){
            cin >> alu[i].nota[j];
        }
        if(Media(alu[i].nota[0], alu[i].nota[1], alu[i].nota[2]) > maiorMedia){
            maiorMedia = Media(alu[i].nota[0], alu[i].nota[1], alu[i].nota[2]);
            indice = i;
        }

            }

    cout << "Nome: "<<alu[indice].nome << endl;
    cout << "Nota01 " <<alu[indice].nota[0] << endl;
    cout << "Nota02 " << alu[indice].nota[1] << endl;
    cout << "Nota03 " << alu[indice].nota[2] << endl;

return 0;
            
}