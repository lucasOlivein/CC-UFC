#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

struct Index
{
    int inicio;
      int fim;
    int pivot;
};



class Quick{
private:
    int *list;
    int lenght;
    Index *i;
    int num_comp;
public:
    Quick(int *list_, int lenght_){
        list = list_;
        lenght = lenght_;
        i = new Index[924370];
        num_comp = 0;
    }
    ~Quick(){
        delete i;
    }
 int _partition(int inicio, int fim)
{
    int pivot = fim--;
    while(inicio < fim)
    {   
        if(list[fim] > list[pivot]){
            num_comp+=2;
            if(list[fim] > list[inicio])
            swap(list[fim], list[inicio]);
            inicio++;
        }else
            fim--;
    } 
    num_comp++;   
    if(list[inicio] < list[pivot])
        swap(list[inicio], list[pivot]);
    return inicio;
}
void _interativo(){
    _interativo(0,lenght);
}
 void _interativo( int inicio, int lenght){
    int inter_atual = 0;
    int inter_final = 0;
    

    i[0].inicio = inicio;
    i[0].fim = lenght-1;

    while(inter_atual <= inter_final){
           
       if(i[inter_atual].inicio < i[inter_atual].fim){
    
            i[inter_atual].pivot = _partition( i[inter_atual].inicio, i[inter_atual].fim);
        
        inter_final++;        
            i[inter_final].inicio = i[inter_atual].inicio;
            i[inter_final].fim = i[inter_atual].pivot-1;
        
        inter_final++;
            i[inter_final].inicio = i[inter_atual].pivot +1 ;
            i[inter_final].fim = i[inter_atual].fim;
       }
       inter_atual ++;
       
    }
    cout << "Numero de Interacoes: " << inter_final << "\n";
}

 int partition(int inicio, int fim)
    {
        int index = inicio;

        while (inicio < fim)
        {   
            num_comp++;
            if (list[inicio] < list[fim])
                swap(list[inicio], list[index++]);
        
        inicio++;
    }
    swap(list[fim], list[index]);
    return index;
}

void interativo(){
    interativo(0,lenght);
}
 void interativo(int inicio, int lenght){
    int inter_atual = 0;
    int inter_final = 0;
    

    i[0].inicio = inicio;
    i[0].fim = lenght-1;

    while(inter_atual <= inter_final){
           
       if(i[inter_atual].inicio < i[inter_atual].fim){
    
            i[inter_atual].pivot = partition( i[inter_atual].inicio, i[inter_atual].fim);
        
        inter_final++;        
            i[inter_final].inicio = i[inter_atual].inicio;
            i[inter_final].fim = i[inter_atual].pivot-1;
        
        inter_final++;
            i[inter_final].inicio = i[inter_atual].pivot +1 ;
            i[inter_final].fim = i[inter_atual].fim;
       }
       inter_atual ++;
       
    }
    cout << "Numero de Interacoes: " << inter_final << "\n";
}



int partition_impar_par()
{
    int index = 0;
    int inicio = 0;

    while (inicio < lenght)
    {   
        num_comp++;
        if (list[inicio] % 2 == 1)
            swap(list[inicio], list[index++]);

        inicio++;
    }
    return index;
}

 void interativo_op2(){
    int p = partition_impar_par();
    interativo( 0, p);
    _interativo( p, lenght);

}

    void recursivo()
    {
        recursivo(0, lenght - 1);
    }
    void recursivo(int inicio, int fim)
    {
        if (inicio >= fim)
            return;

        int p = partition(inicio, fim);
        recursivo(inicio, p - 1);
        recursivo(p + 1, fim);
    }
    void _recursivo(int inicio, int fim)
    {
        if (inicio >= fim)
            return;
        int p = _partition(inicio, fim);
        _recursivo(inicio, p - 1);
        _recursivo(p + 1, fim);
    }

    void recursivo_op2()
    {
        int p = partition_impar_par();
        recursivo(0, p - 1);
        _recursivo(p, lenght - 1);
    }

};

int main(){
 unsigned long int tam =pow(2,18);
  int *list = new int[tam];

  for ( unsigned long int i = 0; i < tam; i++)
    list[i] = rand() %10;
    Quick q(list,tam);
 for (int i = 0; i < 100; i++)
      cout << list[i] << " "; cout << '\n';
  clock_t begin = clock();
  q.recursivo_op2();
  clock_t end = clock();

  for (int i = 0; i < 100; i++)
      cout << list[i] << " "; cout << '\n';

  cout << double(end - begin) / CLOCKS_PER_SEC << " segundos" << endl;

  delete list;
}