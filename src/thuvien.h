#include <iostream>
#include <vector>
using namespace std;
//Class Cơ Sở Động Vật
class Animal{
    private:   
        string name;
        float height,weight;
        int id;
    public:
    	virtual void toStream (istream& is);
        friend istream& operator >> (istream& ,Animal* );
        friend ostream& operator << (ostream& os,Animal* al);
        Animal operator = (Animal* al); 
        
        Animal();
        Animal(string name,float height, float weight, int id);
        Animal(Animal* al);
        ~Animal();
        string getName();
        int getID();
        void EnterKey();            
};


//Dv Ăn Cỏ 
typedef class Graminivore:public Animal{
        string food;
        int amount;
    public: 
        virtual void toStream(istream& is);
        friend ostream& operator << (ostream& os,Graminivore *gn);
        
}Grami;


// Dv Ăn Thịt
typedef class Hypercarnivore:public Animal{
        string food;
        int amount;
    public: 
        virtual void toStream(istream& is);
        friend ostream& operator << (ostream& os,Hypercarnivore *hy);
        
}Hyper;

// Vi Sinh Vật
typedef class Microorganism:public Animal{
		string food; 
        int amount;
    public: 
        virtual void toStream(istream& is);
        friend ostream& operator << (ostream& os,Microorganism *mi);
}Microo;


// Cây Tìm Kiếm Nhị Phân
struct Node{
	Animal *data; 
	Node* left;
	Node* right; 
}; 


struct BST{
		
		Node *root; 
		long size;
		
		Node* CreateNode(Animal *al); 
		//Work With Tree
        int LeftOf(Animal *al,Node* root );
        int RightOf(Animal *al,Node* root );
        Node* Insert(Node* root, Animal* al1);
        Node* SearchName(Node* root,Animal* al1);
        void PostOder(Node* root);
        Node* Delete(Node* root, Animal *al1);
        Node* LeftMostAnimal(Node* root);
};

