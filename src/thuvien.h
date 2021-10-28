#include <iostream>
#include <string>
using namespace std;



class Animal{   
        string name;
        float height,weight;
        Animal *left;
        Animal *right;
        long size;
    public:
        friend istream& operator >> (istream& is,Animal *al);
        friend ostream& operator << (ostream& os,Animal *al);
        Animal();
        Animal(string name);
        Animal(Animal* al);
        ~Animal();
};

//Dv ăn cỏ
typedef class Graminivore::public Animal{
        string food;
        int amount;
        string gtype = "Graminivore";
    public: 
        friend istream& operator >> (istream& is,Graminivore *gn);
        friend ostream& operator << (ostream& os,Graminivore *gn);
}Grami;

// Dv ăn thịt
typedef class Hypercarnivore::public Animal,public Graminavore{
        string htype = "Hypercarnivore";
        string special;
    public: 
        friend istream& operator >> (istream& is,Hypercarnivore *hy);
        friend ostream& operator << (ostream& os,Hypercarnivore *hy);
}Hyper;

// Vi sinh vật
typedef class Microorganism::public Animal,public Graminivore{
        string mtype = "Microorganism";
    public: 
        friend istream& operator >> (istream& is,Microorganism *mi);
        friend ostream& operator << (ostream& os,Microorganism *mi);
}Microo;





