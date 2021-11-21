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
    os << "\tHeight: " << al->height << " kg" << "|| Weight: " << al->weight << " cm" <<endl;
    os << "\t\tID: " << al->id<<endl;
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
    do{
        cout <<"\t\tID: ";
        is >> id;
        if(id < 1 || id > 299)
            cout << "\t\tNegative !"<<endl;
    }   while(id < 1 || id > 299);  
}


Animal Animal::operator = (Animal* al){
	this->name = al->name;
	this->height = al->height;
	this->weight = al->weight;
	this->id = al->id; 
}


//Khởi Tạo Hàm
Animal::Animal(){
    this->name = "None";
	this->height = 0;
	this->weight = 0;
	this->id = 0;
}


Animal::Animal(string name,float height, float weight, int id){
    this->name = name;
    this->height = height;
    this->weight = weight;
    this->id =  0; 
}


Animal::Animal(Animal* al){
    this->name = al->name;
	this->height = al->height;
    this->weight = al->weight;
    this->id =  al->id; 
}


Animal::~Animal(){
}

//Lấy Dữ Liệu
string Animal::getName(){
    return name; 
}

int Animal::getID(){
	return id;
}

void Animal::EnterID(int &id){
	cout << "Enter Id Key: ";
    cin >> id;
	do{
		if(id < 1 ||  id>299){ 
        	cout << "Enter Id Again: ";
        	cin >> id; 
		}
	}while(id < 1 || id > 299);
}

void Animal::setID(int id){
	this->id = id;	
}

void Animal::setName(string name){
    this->name = name;
}
