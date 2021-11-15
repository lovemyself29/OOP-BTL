#include <iostream>
#include <thuvien.h>
using namespace std;

//Động Vật Ăn Cỏ
void Grami::toStream(istream& is){
    Animal::toStream(is);
    fflush(stdin);
    cout <<"\t\tFavorite Food: ";
    is >> food;
    cout <<"\t\tAmout: ";
    is >> amount; 
}

ostream& operator << (ostream& os,Grami *gn){
    Animal *al = static_cast <Animal *> (gn);
    os << al;
    os << "\t\tAmount: "<< gn->amount<<endl; 
    os << "\t\tFavorite Food: "<< gn->food<<endl; 
    cout <<"\t*********************~~*********************" << endl; 
}