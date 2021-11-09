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
    do{
        cout <<"\t\tType: ";
        is >> type;
        if(type != 3)
            cout << "\t\tNegative !"<<endl;
    }   while(type != 3 );   
}

ostream& operator << (ostream& os,Hyper *hy){
    Animal *al = static_cast <Animal *> (hy);
    os << al;
    os << "\tAmount: " << hy->amount <<" Individuals"<<endl;
    os << "\tFavorite Food: " << hy->food <<endl;
    cout <<"\t\tType: Hypercarnivore"<<endl; 
    cout <<"\t*********************~~*********************" << endl; 
}