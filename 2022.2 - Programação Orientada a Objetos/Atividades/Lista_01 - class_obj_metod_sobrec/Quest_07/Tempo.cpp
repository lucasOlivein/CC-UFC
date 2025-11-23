#include "Tempo.h"
#include <iostream>
using namespace std;

Tempo::Tempo(){
    hora = 0;
    min = 0;
    sec = 0;
}

Tempo::Tempo(int h, int m, int s){
    hora = h;
    min = m;
    sec = s;
}

void Tempo::print(){
    cout <<  hora << "/" << min << "/" << sec  ;
}

void Tempo::subtrair(Tempo a, Tempo b){
    a.print(); cout << " - "; b.print(); cout << '\n';
    if(a.sec < b.sec){
        sec = (60 + a.sec) - b.sec;
        b.min++;
    }else{
        sec = a.sec - b.sec;
    }
    if(a.min < b.min){
        min = (60 + a.min) - b.min;
        b.hora++;
    }else{
        min = a.min - b.min;
    }
    if(a.hora < b.hora ){
        cout << "Erro!!" << '\n';
    }else{    
        hora = (a.hora - b.hora);
    }
}

void Tempo::somar(Tempo a, Tempo b){
    a.print(); cout << " + "; b.print(); cout << '\n';
    if(a.sec + b.sec > 59){
        sec = (a.sec + b.sec)%60;
        a.min += int((a.sec+b.sec)/60);
    }else{
        sec = a.sec + b.sec;
    }
    if(a.min + b.min > 59){
        min = (a.min+b.min)%60;
        a.hora += int((a.min+b.min)/60);
    }

    hora = a.hora + b.hora;

}

 /* Tempo Tempo::somar(Tempo a, Tempo b, Tempo *c = new Tempo){
    int h,m,s;
    if(a.sec + b.sec > 59){
        s = (a.sec + b.sec)%60;
        b.min += int((a.sec+b.sec)/60);
    }else{
        s = a.sec + b.sec;
    }
    if(a.min + b.min > 59){
        m = (a.min+b.min)%60;
        b.hora += int((a.min+b.min)/60);
    }

    h = a.hora + b.hora;
    Tempo c(h,m,s);
    return c;
}  */

