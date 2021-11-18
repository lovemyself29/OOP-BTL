#include <iostream>
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
    void insertAfter(NodeL *p, Animal *v);
    NodeL *previous(NodeL *p);
    NodeL *searchName(NodeL *p, string name);
    void sort();
    void removeFirst();
    void removeLast();
    void removeName();
    void traverse() const;
};