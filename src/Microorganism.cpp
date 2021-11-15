#include <iostream>
#include <thuvien.h>
using namespace std;

//Động Vật Vi Sinh
void Microorganism::toStream(istream& is){
    Animal::toStream(is) ;
    fflush(stdin);
    cout <<"\t\tFavorite Food: ";
    is >> food;
    cout <<"\t\tAmount: ";
    is >> amount;  
}

ostream& operator << (ostream& os,Microo *mi){
    Animal *al = static_cast <Animal *> (mi);
    os << al;
    os << "\t\tAmount: "<< mi->amount<<endl; 
    os << "\t\tFavorite Food: "<< mi->food<<endl; 
    cout <<"\t*********************~~*********************" << endl; 
}