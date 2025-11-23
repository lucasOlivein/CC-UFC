#include <iostream>
using namespace std;


void mergeAB(int *v, int *a, int n, int *b, int m){
  int aux = 0;
  int j = 0;
  if(m > n){
    for(int i=0; i<n; i++)
      for(int j; j<n; j++){
        if(a[i] < b[j]){
          v[aux] = a[i];
          aux++;
          break;
        }else if(a[i] > b[j]){
        v[aux] = b[j];
          aux++;
        }else{
          v[aux] = a[i];
          v[aux+1] = b[j];
          aux +=2;
          i++;
          j ++;
          break;
        }
      }
      for(int i = n; i< m; i++){
        v[aux] = b[n];
        aux++;
      }
   }else{
      for(int i=0; i<m; i++)
        for(int j; j<m; j++){
            if(a[i] < b[j]){
              v[aux] = a[i];
                aux++;
                break;
        }   else if(a[i] > b[j]){
              v[aux] = b[j];
              aux++;
        }   else{
              v[aux] = a[i];
              v[aux+1] = b[j];
              aux +=2;
              i++;
              j = i+1;
              break;
        }
        }
      for(int i = m; i< n; i++){
        v[aux] = a[n];
        aux++;
      }
      }
   }

   int main(){
    int a[] = {1,4,5,7,8,10,11};
    int n = 7;


    int b[] ={1,3,6,7,8,9,11,12,13};
    int m = 9;

    int v[n+m] = {};

    mergeAB(v, a, n,b,m);

    for(int i = 0; i< n; i++)
      cout << v[i] << " ";
   }