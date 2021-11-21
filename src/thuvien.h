#include <iostream>
#include <conio.h>
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
        void setName(string name);
        void setID(int id); 
        string getName();
        int getID();       
};


//Dv An Co 
typedef class Graminivore:public Animal{

        string food;
        int amount;
    public: 
        virtual void toStream(istream& is);
        friend ostream& operator << (ostream& os,Graminivore *gn);
        
}Grami;


// Dv An Thit
typedef class Hypercarnivore:public Animal{
        string food;
        int amount;
    public: 
        virtual void toStream(istream& is);
        friend ostream& operator << (ostream& os,Hypercarnivore *hy);
        
}Hyper;

// Vi Sinh Vat
typedef class Microorganism:public Animal{
		string food; 
        int amount;
    public: 
        virtual void toStream(istream& is);
        friend ostream& operator << (ostream& os,Microorganism *mi);
}Microo;


// Cay Tim Kiem Nhi Phan
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
        Node* Insert(Node* &root, Animal* al1);
        Node* SearchID(Node* root,Animal* al1);
        void PostOrder(Node* root);
        void InOrder(Node* root);
        Node* Delete(Node* &root, Animal *al1);
        Node* LeftMostAnimal(Node* root);
};

//Linked List
struct NodeL{
    Animal *data;
    NodeL *next;
};

struct SList{
	NodeL *head;
	NodeL *tail;
	long size;
	SList();
    ~SList();
	NodeL* CreateNodeL(Animal *v);
    void addLast(Animal *v);
    NodeL *previous(NodeL *p);
    NodeL *searchName(string name);
    void sort();
    void removeFirst();
    void removeLast();
    void removeName();
    void traverse() const;
};