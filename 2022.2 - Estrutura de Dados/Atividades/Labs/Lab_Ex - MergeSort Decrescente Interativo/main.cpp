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

void mergeSortInterativo(int *vet_result, int *vet_a, int len_a, int *vet_b, int len_b){
  int index_a = 0;
  int index_b = 0;
  int index_result = 0;

  if(len_a <= len_b){
    while(index_a < len_a){
      while(index_b < len_b){
        if(vet_a[index_a] <= vet_b[index_b]){
          vet_result[index_result] = vet_a[index_a];
          index_a++;
          index_result++;
          break;
        }else{
          vet_result[index_result] = vet_b[index_b];
          index_b++;
          index_result++;
        }
      }
      
    }



  }else
    mergeSortInterativo(vet_result, vet_b, len_b, vet_a, len_a);

}


int main(){
    int vet_a[] = {1,5,7,8,9};
    int a_len = sizeof(vet_a)/sizeof(int);

    int vet_b[] ={2,3,4,6,10};
    int b_len = sizeof(vet_b)/sizeof(int);

    /* Quick(vet_a, a_len);
    Quick(vet_b, b_len); */


    int vet_result[(a_len+b_len)] = {};

    mergeSortInterativo(vet_result, vet_a, a_len, vet_b,b_len);

    for(int i = 0; i< b_len+a_len; i++){
      cout << vet_result[i] << " ";
   }

}