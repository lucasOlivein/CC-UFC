#include <iostream>
#include <vector>
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

void mergeAB(int *vet_result,int *vet_a, int a_len, int *vet_b,int b_len){
  int index_result =0;
  int index_aux = 0; 

  if(a_len<=b_len){                                 
    for(int i=0; i<a_len; i++){                          //LOOPING PERCORRENDO O MENOR VETOR
      while(index_aux < b_len){         //
        if(vet_a[i] <= vet_b[index_aux]){
          vet_result[index_result] = vet_a[i];
          index_result++;
          break;
        }else{
          vet_result[index_result] = vet_b[index_aux];
          index_aux++;
          index_result++;
        }
      }
    }                                             //TERMINA NO FIM DO VETOR A.

    while(a_len < b_len){                         // COPIA OS ELEMENTOS RESTANTE DE B PARA O VETOR RESULTE.
      vet_result[index_result] = vet_b[a_len];
      index_result++;
      a_len++;
    }
  }else
    mergeAB(vet_result, vet_b, b_len, vet_a, a_len); // CASO O MENOR VETOR SEJA B.
   
}



int main(){
    int vet_a[] = {123, 146, 454, 78123, 413, 6456, 1231, 52342, 643, 252, 634};
    int a_len = sizeof(vet_a)/sizeof(int);

    int vet_b[] ={100, 200, 248, 328, 689, 53453, 234,1123, 123,5,1,3,12,5,6,7,2,36,98,100,2};
    int b_len = sizeof(vet_b)/sizeof(int);

    Quick(vet_a, a_len);
    Quick(vet_b, b_len);


    int vet_result[(a_len+b_len)] = {};

    mergeAB(vet_result, vet_a, a_len, vet_b,b_len);

    for(int i = 0; i< b_len+a_len; i++){
      cout << vet_result[i] << " ";
   }

}