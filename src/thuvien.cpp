#include<thuvien.h>
#include <iostream>
#include <string>

using namespace std;
//Nhập động vật
istream& operator >> (istream& is,Animal *al){
    al = new Animal;
    fflush(stdin);
    cout <<"Name Of The Animal: ";
    getline  (is,al->name);
    cout <<"Height: ";
    is >> al->height;
    cout <<"Weight: ";
    is >> al->weight;
    return is;
}

osstream& operator >> (ostream& is,Animal *al){
    os << "****************--*************"<<endl;
    os <<"\tName: "<< al->name<<endl;
    os <<"\tHeight: "<< al->height<<"|| Weight: "<<al->weight<<endl;
    return os;
}

Animal::Animal(){
    Animal *al;
    this->type = "None";
    this->name = "None";
    al->left = NULL;
    al->right = NULL;
    size = 0;
}

Animal::Animal(string type,string name){
    this->type = type;
    this->name = name;
    left = NULL;
    right = NULL;
    size ++;
    return *this;
}

Animal::Animal(Animal* al){
    this->type = al->type;
    this->name = al->name;
    left = NULL;
    right = NULL;
    size++;
    return *this;
}

Animal::~Animal(){
    delete Animal;
}

//Nhập động vật ăn cỏ
istream& operator >> (istream& is,Graminavore *gn){
    gn = new Graminavore;
    Animal *al = static_cast<*al> (*gn);
    is >> *al;
    fflush(stdin);
    cout <<"Favorite Food: ";
    is >> gn->food;
    cout <<"Amout: ";
    is >> gn->amount;
    return is;
}

osstream& operator << (ostream& is,Graminavore *gn){
    Animal *al = static_cast<*al>(*gn);
    os << *al;
    os << "\tAmount: " << gn->amount <<" Individuals"<<endl;
    os << "\tFavorite Food: " << gn->food <<endl;
    os << "\tType: " << gn->gtype;
    return os;
}

//Nhập động vật ăn thịt
istream& operator >> (istream& is,Hypercarnivore *hy){
    hy = new Hypercarnivore;
    Animal *al = static_cast<*al> (*hy);
    is >> *al;
    fflush(stdin);
    cout <<"Favorite Food: ";
    is >> hy->food;
    cout <<"Amout: ";
    is >> hy->amount;
    return is;
}

osstream& operator << (ostream& is,Hypercarnivore *hy){
    Animal *al = static_cast<*al>(*hy);
    os << *al;
    os << "\tAmount: " << hy->amount <<" Individuals"<<endl;
    os << "\tFavorite Food: " << hy->food <<endl;
    os << "\tType: " << hy->gtype;
    return os;
}


//Nhập động vật vi sinh
istream& operator >> (istream& is,Microorganism *mi){
    mi = new Microorganism;
    Animal *al = static_cast<*al> (*mi);
    is >> *al;
    fflush(stdin);
    cout <<"Favorite Food: ";
    is >> mi->food;
    cout <<"Amout: ";
    is >> mi->amount;
    return is;
}

osstream& operator << (ostream& is,Graminavore *gn){
    Animal *al = static_cast<*al>(*gn);
    os << *al;
    os << "\tAmount: " << gn->amount <<" Individuals"<<endl;
    os << "\tFavorite Food: " << gn->food <<endl;
    os << "\tType: " << gn->gtype;
    return os;
}

