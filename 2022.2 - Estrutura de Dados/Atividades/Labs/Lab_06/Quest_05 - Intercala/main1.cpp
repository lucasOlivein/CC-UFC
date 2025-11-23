#include <iostream>

using namespace std;

void Quick(int list[], int lenght, int index = 0){
  
  for(int j = index; j<lenght-1; j++){       //PERCORRE A LISTA
    if(list[j] < list[lenght-1]){
      if( j != index)
        swap(list[index], list[j]);
      index++;
    }
  }                                         // TERMINA DE PERCORRER

  swap(list[index], list[lenght-1]);        //POSICIONA O PIVO

  
  //CHAMA A FUNCAO PARA A PARTE DO VETOR QUE NAO ESTA ORDENADO.
  if(lenght-1 > 1)        
    Quick(list, lenght-1);                    
  if(index+1 < lenght-1)  
    Quick(list, lenght, index+1);

}

void mergeAB(int *vet_result, int *vet_a, int a_len, int *vet_b, int b_len){
int j = 0;
int aux = 0;

if(a_len<=b_len){
  for(int i=0; i<a_len; i++)
    while(j<b_len){
      if(vet_a[i] > vet_b[j]){
        vet_result[aux] = vet_b[j];
        j++;
        aux++;
      }else if(vet_a[i] < vet_b[j]){
        vet_result[aux] = vet_a[i];
        aux++;
        break;
      }else{
        vet_result[aux] = vet_b[j];
        aux++;
      }
    }
    while(a_len <= b_len){
      vet_result[aux] = vet_b[a_len-1];
       a_len++;
       aux++;
    }

    for(int i = 0; i< j+a_len; i++){
      cout << vet_result[i] << " ";
   }
}else{
  mergeAB(vet_result, vet_b, b_len, vet_a, a_len);
  abort; 
}

}

int main(){
    int vet_a[] = {123, 146, 454, 78123, 413, 6456, 1231, 52342, 643, 252, 634};
    int a_len = sizeof(vet_a)/sizeof(int);

    int vet_b[] ={100, 200, 248, 328, 689, 53453, 234,1123, 123,5,1,3,12,5,6,7,2,36,98};
    int b_len = sizeof(vet_b)/sizeof(int);

    Quick(vet_a, a_len);
    Quick(vet_b, b_len);


    int vet_result[(a_len+b_len)] = {};

    mergeAB(vet_result, vet_a, a_len, vet_b,b_len);

}

