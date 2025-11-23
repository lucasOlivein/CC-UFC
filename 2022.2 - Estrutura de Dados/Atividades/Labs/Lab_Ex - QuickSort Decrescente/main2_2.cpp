#include <iostream>
using namespace std;

int inter = 0;

int Quick(int list[], int lenght, int index = 0){
  
  if(lenght <=1 || index >= lenght)
    return 0;

  for(int j = index; j<lenght-1; j++){       //PERCORRE A LISTA
    if(list[j] < list[lenght-1]){
      if( j != index)
        swap(list[index], list[j]);
      index++;
    }
  }                                         // TERMINA DE PERCORRER

  swap(list[index], list[lenght-1]);        //POSICIONA O PIVO

  
  //CHAMA A FUNCAO PARA A PARTE DO VETOR     
  Quick(list, lenght-1);                    
  Quick(list, lenght, index+1);          

  cout << "Interacao: " << inter << '\n';
inter++;
}

int main(){
  int list[] = {3,7,2,8,5,7,5,4,2,9,25,6};
  int lenght = 12;

  Quick(list, lenght);

  for(int i=0; i<lenght; i++)
    cout << list[i] << " ";

}