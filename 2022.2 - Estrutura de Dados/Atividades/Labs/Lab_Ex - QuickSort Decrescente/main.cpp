#include <iostream>

using namespace std;


int Quick(int *list, int lengh, int lower = 0){
    cout <<"Tamanho do vetor: " <<  lengh << endl;
    
    if(lower-1 <= 1 || lower+1 >= lengh){   ///Condicao de parada;
        return 0;
    } 
       // COMECA A PERCORRER O VERTOR;
    for(int i=lower; i<lengh; i++){
        cout << list[i] << " < " << list[lengh] << '?';
        if(list[i] < list[lengh]){       // Caso o pivo for menor
        cout << " Sim, ";   
            if(lower != i){
                cout << "Troca: " << list[lower] << " - " << list[i] <<"\n";
               swap(list[lower], list[i]);
            }
            lower++;
            cout << "Lower ++\n-------------\n";
        }else
        cout << " Nao\n-----------\n";
    } //    TERMINA DE PERCORRER

    cout <<"Termino do loop.Variavel Lower: "<< lower << endl;
    
    // Posiciona o ultimo elemento
    swap(list[lower], list[lengh]);

        // CHAMA A FUNCAO PARA O VETOR DIVIDIDO.
    Quick(list, lower-1);
    Quick(list, lengh, lower+1);
        
}

int main(){
    int list[] = {8,7,6,2,3,4,2,5,1,2,3,5,4,5,6,6,8,0,7,5,8,9};//{1,4,3,2,7,1,8,3,20,4};
    int length = 21;

    for(int i=0; i<length; i++)
        cout << list[i] << " ";
        cout <<endl;
    Quick(list, length-1);


    for(int i=0; i<length; i++)
        cout << list[i] << " ";

}
