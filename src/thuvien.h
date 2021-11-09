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
        
        
        string getName(){
        	return name; 
		} 
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


struct Node{
	Animal data; 
	Node* left;
	Node* right; 
}; 


struct BST{
		
		Node *root; 
		long size;
		
		Node* CreateNode(Animal al); 
		//Work With Tree
        int LeftOf(Animal *al,Node* root );
        int RightOf(Animal *al,Node* root );
        Node* Insert(Node* root, Animal* al1);
        Node* SearchName(Node* root,Animal* al1);
        void PreOder(Node* root);
        Node* Delete(Node* root, Animal *al1);
        Node* LeftMostAnimal(Node* root);
}; 


class ListAnimal{
    private:
        vector<Animal *> AL;
    public:
        void SortList(); 
        void StatistSpec(); 
        void SearchList();
};