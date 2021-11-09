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
    do{
        cout <<"\t\tType: ";
        is >> type;
        if(type != 1)
            cout << "\tNegative !"<<endl;
    }   while(type != 1 );    
}

ostream& operator << (ostream& os,Microo *mi){
    Animal *al = static_cast <Animal *> (mi);
    os << al;
    os << "\t\tAmount: "<< mi->amount<<endl; 
    os << "\t\tFavorite Food: "<< mi->food<<endl; 
    cout <<"\t\tType: Microorganism" << endl;
    cout <<"\t*********************~~*********************" << endl; 
}