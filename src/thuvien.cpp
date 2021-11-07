#include <iostream>
#include <thuvien.h>
using namespace std;

//Nhap dong vat
istream& operator >> (istream& is,Animal *al){
    al->toStream(is);
    return is;
}

ostream& operator << (ostream& os,Animal *al){
    os << "\t*********************--*********************\n";
    os <<"\t\tName: "<< al->name<<endl;
    os <<"\tHeight: "<< al->height<<"|| Weight: "<<al->weight<<endl;
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

//Khoi Tao Hàm
Animal::Animal(){
    Animal *al = new Animal;
    this->name = "None";
    al->left = NULL;
    al->right = NULL;
    size = 0;
}

Animal::Animal(string name){
    Animal *al = new Animal;
    this->name = name;
    al->left = NULL;
    al->right = NULL;
    size ++;
    
}

Animal::Animal(Animal* al){
    this->name = al->name;
    this->left = al->left;
    this->right = al->right;
    size++;
}

Animal::~Animal(){
    
}

// Hàm Duyệt Vi Trí Bé Nhat Hoac Lon Nhat
int Animal::LeftOf(const Animal *al,const Animal* root ){    
    return ((al->height * al->weight)/2 < (root->height * root->weight)/2 || al->type < root->type) ;
}
 
int Animal::RightOf(const Animal *al,const Animal* root){
    return ((al->height * al->weight)/2 > (root->height * root->weight)/2 || al->type > root->type);
}

// Thêm Phần Tử
Animal* Animal::Insert(Animal* al,const Animal *al1){
    if ( al == NULL){
        Animal* node = new Animal;
        node ->left = NULL;
        node ->right = NULL;
        *node = *al1;
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

// Tìm Kiếm
Animal* Animal::SearchName(Animal *al,const Animal *al1){
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

//Duyệt Left -> Right -> Node
void Animal::PreOder(Animal* al){
	if(al != NULL){
		PreOder(al->left);
		PreOder(al->right);
		cout << al;
	}
}

//Tìm Và Trả Về Phần Tử Nhỏ Nhất Bên Trái
Animal Animal::LeftMostAnimal(const Animal* al){
    while(al->left != NULL)
        al = al->left;
    return *al;
}

//Hàm Xóa Phần Tử
Animal* Animal::Delete(Animal* al, Animal *al1){
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



//Nhap dong vat an co
void Grami::toStream(istream& is){
    Animal::toStream(is);
    fflush(stdin);
    cout <<"\t\tFavorite Food: ";
    is >> food;
    cout <<"\t\tAmout: ";
    is >> amount;
    do{
        cout <<"\t\tType";
        is >> type;
        if(type < 1 || type > 3)
            cout << "\t\tNegative !"<<endl;
    }   while(type < 1 || type > 3);   
}

ostream& operator << (ostream& os,Grami *gn){
    Animal *al = static_cast <Animal*> (gn);
    os << al;
    os << "\t\tAmount: " << gn->amount <<" Individuals"<<endl;
    os << "\t\tFavorite Food: " << gn->food <<endl;
    os << "\t\tType: " << gn->type;
    return os;
}



//Nhap dong vat an thit
void Hyper::toStream(istream& is){
    Animal::toStream(is);
    fflush(stdin);
    cout <<"\t\tFavorite Food: ";
    is >> food;
    cout <<"\t\tAmout: ";
    is >> amount;
    do{
        cout <<"\t\tType";
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
    return os;
}



//Nhap dong vat vi sinh
void Microorganism::toStream(istream& is){
    Animal::toStream(is) ;
    fflush(stdin);
    cout <<"\tData: ";
    is >> special;
    do{
        cout <<"\tType";
        is >> type;
        if(type != 1)
            cout << "\tNegative !"<<endl;
    }   while(type != 1 );    
}

ostream& operator << (ostream& os,Microo *mi){
    Animal *al = static_cast <Animal *> (mi);
    os << al;
    os << "\tData: "<<mi->special;
    return os;
}