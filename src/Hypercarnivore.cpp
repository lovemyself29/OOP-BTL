#include <iostream>
#include <thuvien.h>
using namespace std;

//Động Vật Ăn Thịt
void Hyper::toStream(istream& is){
    Animal::toStream(is);
    fflush(stdin);
    cout <<"\t\tFavorite Food: ";
    is >> food;
    cout <<"\t\tAmout: ";
    is >> amount;
}

ostream& operator << (ostream& os,Hyper *hy){
    Animal *al = static_cast <Animal *> (hy);
    os << al;
    os << "\t\tAmount: "<< hy->amount<<endl; 
    os << "\t\tFavorite Food: "<< hy->food<<endl; 
    cout <<"\t*********************~~*********************" << endl; 
}