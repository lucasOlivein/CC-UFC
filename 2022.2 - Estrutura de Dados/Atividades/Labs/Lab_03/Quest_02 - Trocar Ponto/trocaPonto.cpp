#include <iostream>
#include <iomanip>
using namespace std;

struct Ponto{
    float x;
    float y;

};



void troca(Ponto *p1, Ponto *p2 ){
    float aux = p1->x;
    p1->x = p2->x;
    p2->x = aux;
    aux = p1->y;
    p1->y = p2->y;
    p2->y = aux;
}


int main(){
    Ponto p1;
    Ponto p2;

    cin >> p1.x;
    cin >> p1.y;
    cin >> p2.x;
    cin >> p2.y;

    troca(&p1, &p2);
    cout << fixed << setprecision(1);
    cout << p1.x << "-" << p1.y << endl;
    cout << p2.x << "-" << p2.y << endl;
    

    return 0;


}