#include <iostream>
#include <thuvien.h>
using namespace std;

//Class Cơ Sở Động Vật
istream& operator >> (istream& is,Animal *al){
    al->toStream(is);
    return is;
}

ostream& operator << (ostream& os,Animal *al){
    os << "\t*********************--*********************\n";
    os << "\t\tName: " << al->name << endl;
    os << "\tHeight: " << al->height << " cm" << "|| Weight: " << al->weight << " cm" <<endl;
    return os;
}

void Animal::toStream(istream& is){
    fflush(stdin);
    cout <<"\t\tName Of The Animal: ";
    getline  (is,name);
    cout <<"\t\tHeight: ";
    is >> height;
    cout <<"\t\tWeight: ";
    is >> weight;
}

Animal Animal::operator = (Animal* al){
	this->name = al->name;
	this->height = al->height;
	this->weight = al->weight;
	this->type = al->type; 
}
//Khợi Tạo Hàm
Animal::Animal(){
    this->name = "None";
	this->height = 0 ;
	this->weight = 0 ;
	this->type = 0 ;
}

Animal::Animal(string name,float height, float weight, int type){
    this->name = name;
    this->height = height;
    this->weight = weight;
    this->type =  0 ; 
}

Animal::Animal(Animal* al){
    this->name = al->name;
	this->height = al->height;
    this->weight = al->weight;
    this->type =  al->type; 
}

Animal::~Animal(){
}

//Lấy Dữ Liệu
string Animal::getName(){
    return name; 
}

float Animal::getHeight(){
    return height; 
}

float Animal::getWeight(){
    return weight; 
}

int Animal::getType(){
    return type; 
}