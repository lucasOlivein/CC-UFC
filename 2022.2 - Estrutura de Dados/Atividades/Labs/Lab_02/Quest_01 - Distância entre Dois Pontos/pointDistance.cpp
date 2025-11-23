#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void dist(float x, float y){
    float dis = sqrt((x*x) + (y*y));
    cout << fixed << setprecision(2);
    cout <<"A distancia é: " << dis << endl;
}

int main(){
    float x,y;
    cin >> x;
    cin >> y;

    dist(x,y);

}