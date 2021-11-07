#include <iostream>
#include <vector>
using namespace std;

class Animal{
    private:   
        string name;
        float height,weight;
        Animal *left;
        Animal *right;
        int type;
        long size;
    public:
        friend istream& operator >> (istream& is,Animal *al);
        friend ostream& operator << (ostream& os,Animal *al);
        virtual void toStream (istream& is);
        Animal();
        Animal(string name);
        Animal(Animal* al);
        ~Animal();
        //Work With Tree
        int LeftOf(const Animal *al,const Animal* root );
        int RightOf(const Animal *al,const Animal* root );
        Animal* Insert(Animal* al,const Animal* al1);
        Animal* SearchName(Animal* al,const Animal* al1);
        void PreOder(Animal* al);
        Animal* Delete(Animal* al, Animal *al1);
        Animal LeftMostAnimal(const Animal* al);
        
};



//Dv an co
typedef class Graminivore:public Animal{
        string food;
        int amount;
        int type;
    public: 
        virtual void toStream(istream& is);
        friend ostream& operator << (ostream& os,Graminivore *gn);
        
}Grami;

// Dv an thit
typedef class Hypercarnivore:public Animal{
        string food;
        int amount;
        int type;
    public: 
        virtual void toStream(istream& is);
        friend ostream& operator << (ostream& os,Hypercarnivore *hy);
        
}Hyper;

// Vi sinh vat
typedef class Microorganism:public Animal{
        int type;
        string special;
    public: 
        virtual void toStream(istream& is);
        friend ostream& operator << (ostream& os,Microorganism *mi);
        
}Microo;


// Vector
class ListAnimal{
    private:
        vector<Animal *> AL;
    public:
        void SortList();
        void StatistSpec(); 
        void SearchList();
};