#include <iostream>
#include <thuvien.h>
using namespace std;

//Nh?p d?ng v?t
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
//Kh?i T?o Hàm
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

// Hàm Tr? V? V? Trí Bé Nh?t Ho?c L?n Nh?t
int BST::LeftOf(Animal *al,Animal* root){    
    return ((al->getHeight() * al->getWeight())/2 < (root->getHeight() * root->getWeight())/2 || al->getType() < root->getType());
}
 
int BST::RightOf(Animal *al,Animal* root){    
    return ((al->getHeight() * al->getWeight())/2 > (root->getHeight() * root->getWeight())/2 || al->getType() > root->getType());
}


Animal* BST::Insert(Animal* al,const Animal *al1){
    if ( al == NULL){
        BST* node = new BST;
        node ->left = NULL;
        node ->right = NULL;
        node = al1;
        return node;
    }
    else{
    	if(LeftOf(al1,al))
    		al->left = al->Insert(al->left,al1);
    	else if(RightOf(al1,al))
    		al->right = al->Insert(al->right,al1);
	}
		return al;
}

Animal* BST::SearchName(Animal *al,const Animal *al1){
	if (al == NULL){
		return NULL;
	}
	if(al->name == al1->name){
		return al;
	}
	else if(LeftOf(al1,al))
		al->SearchName(al->left,al1);
	else if(RightOf(al1,al))
		al->SearchName(al->right,al1);
	return al;
}


void BST::PreOder(Animal* al){
	if(al != NULL){
		PreOder(al->left);
		PreOder(al->right);
		cout << al;
	}
}


Animal BST::LeftMostAnimal(const Animal* al){
    while(al->left != NULL)
        al = al->left;
    return *al;
}


Animal* BST::Delete(Animal* al, Animal *al1){
    if (al == NULL)
        return al;
    if (LeftOf(al1,al))
        al->left = al->Delete(al->left,al1);
    else if (RightOf(al1,al))
        al->right = al->Delete(al->right,al1);
    else
    {
        if (al->left == NULL)
        {
            Animal* newAl = al->right;
            delete al;
            return newAl;
        }
        if (al->left == NULL)
        {
            Animal* newAl = al->left;
            delete al;
            return newAl;
        }
        *al = al->LeftMostAnimal(al->right);
        al->right = al->Delete(al->right,al);
    }
    return al;
}





//Nh?p d?ng v?t an c?
void Grami::toStream(istream& is){
    Animal::toStream(is);
    fflush(stdin);
    cout <<"\t\tFavorite Food: ";
    is >> food;
    cout <<"\t\tAmout: ";
    is >> amount;
    do{
        cout <<"\t\tType: ";
        is >> type;
        if(type != 2)
            cout << "\t\tNegative !"<<endl;
    }   while(type != 2);   
}

ostream& operator << (ostream& os,Grami *gn){
    Animal *al = static_cast <Animal*> (gn);
    os << al;
    os << "\t\tAmount: " << gn->amount <<" Individuals"<<endl;
    os << "\t\tFavorite Food: " << gn->food <<endl;
    cout <<"\t\tType: Graminivore"<< endl; 
    cout <<"\t*********************~~*********************" << endl; 
}



//Nh?p d?ng v?t an th?t
void Hyper::toStream(istream& is){
    Animal::toStream(is);
    fflush(stdin);
    cout <<"\t\tFavorite Food: ";
    is >> food;
    cout <<"\t\tAmout: ";
    is >> amount;
    do{
        cout <<"\t\tType: ";
        is >> type;
        if(type != 3)
            cout << "\t\tNegative !"<<endl;
    }   while(type != 3 );   
}

ostream& operator << (ostream& os,Hyper *hy){
    Animal *al = static_cast <Animal *> (hy);
    os << al;
    os << "\tAmount: " << hy->amount <<" Individuals"<<endl;
    os << "\tFavorite Food: " << hy->food <<endl;
    cout <<"\t\tType: Hypercarnivore"<<endl; 
    cout <<"\t*********************~~*********************" << endl; 
}



//Nh?p d?ng v?t vi sinh
void Microorganism::toStream(istream& is){
    Animal::toStream(is) ;
    fflush(stdin);
    cout <<"\t\tFavorite Food: ";
    is >> food;
    cout <<"\t\tAmount: ";
    is >> amount;
    do{
        cout <<"\t\tType: ";
        is >> type;
        if(type != 1)
            cout << "\tNegative !"<<endl;
    }   while(type != 1 );    
}

ostream& operator << (ostream& os,Microo *mi){
    Animal *al = static_cast <Animal *> (mi);
    os << al;
    os << "\t\tAmount: "<< mi->amount<<endl; 
    os << "\t\tFavorite Food: "<< mi->food<<endl; 
    cout <<"\t\tType: Microorganism" << endl;
    cout <<"\t*********************~~*********************" << endl; 
}
