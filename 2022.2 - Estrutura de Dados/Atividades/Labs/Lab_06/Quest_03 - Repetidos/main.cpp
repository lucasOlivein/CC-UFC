#include <iostream>
using namespace std;

int repet(int *vec, int n){
    int count =0;
    for(int i=0; i<n; i++)
        for(int j = i+1; j< n; j++){
            if(vec[i] == vec[j]){
                count ++;
                break;
            }
        }
        return count;
}

int main(){
    int n;
    cin >> n;

    int vec[500];
    for(int i=0; i<n; i++)
        cin >> vec[i];
    
    cout << repet(vec, n);
}