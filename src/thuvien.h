#include <iostream>
#include <vector>
using namespace std;

class Animal{
    private:   
        string name;
        float height,weight;
        int type;
    public:
    	virtual void toStream (istream& is);
        friend istream& operator >> (istream& ,Animal* );
        friend ostream& operator << (ostream& os,Animal* al);
        Animal operator = (Animal* al); 
        
        Animal();
        Animal(string name,float height, float weight, int type);
        Animal(Animal* al);
        ~Animal();
        
        float getHeight(){
        	return height; 
		}
        float getWeight(){
        	return weight; 
		} 
        int getType(){
        	return type; 
		}
               
};



//Dv an c?
typedef class Graminivore:public Animal{
        string food;
        int amount;
        int type;
    public: 
        virtual void toStream(istream& is);
        friend ostream& operator << (ostream& os,Graminivore *gn);
        
}Grami;

// Dv an th?t
typedef class Hypercarnivore:public Animal{
        string food;
        int amount;
        int type;
    public: 
        virtual void toStream(istream& is);
        friend ostream& operator << (ostream& os,Hypercarnivore *hy);
        
}Hyper;

// Vi sinh v?t
typedef class Microorganism:public Animal{
		string food; 
        int type;
        int amount;
    public: 
        virtual void toStream(istream& is);
        friend ostream& operator << (ostream& os,Microorganism *mi);
        
}Microo;

// Làm việc với cây
class BST{
	private:
		Animal data; 
		BST *left;
		BST *right;
		long size;
	public:
		//Work With Tree
        int LeftOf(Animal *al,Animal* root );
        int RightOf(Animal *al,Animal* root );
        Animal* Insert(Animal* al,const Animal* al1);
        Animal* SearchName(Animal* al,const Animal* al1);
        void PreOder(Animal* al);
        Animal* Delete(Animal* al, Animal *al1);
        Animal LeftMostAnimal(const Animal* al);
}; 

// Vector
class ListAnimal{
    private:
        vector<Animal *> AL;
    public:
        void SortList();
        void StatistSpec(); 
        void SearchList();
};

