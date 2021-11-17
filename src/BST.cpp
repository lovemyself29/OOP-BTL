#include <iostream>
#include <thuvien.h>
using namespace std;


//Tạo Node
Node* BST::CreateNode(Animal *al){
	Node * p= new Node; 
    Animal *al1 = new Animal(al);
	p->data = al1;
	p->left = NULL;
	p->right = NULL; 
	return p; 
} 


//Duyệt Phần Tử Bên Trái Root > Left và Right > Root
int BST::LeftOf(Animal *al,Node* root){    
    return (al->getID() < root->data->getID());
}


int BST::RightOf(Animal *al,Node* root){    
    return (al->getID() > root->data->getID());
}


//Chèn Phần Tử
Node* BST::Insert(Node* root,Animal *al1){
    if ( root == NULL){
        Node* node = CreateNode(al1);
        return node;
    }
    else{
    	if(LeftOf(al1,root))
    		root->left = Insert(root->left,al1);
    	else if(RightOf(al1,root))
    		root->right = Insert(root->right,al1);
	}
		return root;
}


//Tìm Kiếm Phần Tử
Node* BST::SearchName(Node *root,Animal *al1){
	if (root == NULL){
		return NULL;
	}
	
	if(root->data->getName() == al1->getName()){
        return root;
    }
	else if(LeftOf(al1,root))
		SearchName(root->left,al1);
	else if(RightOf(al1,root))
		SearchName(root->right,al1);
	return root;
}


//Duyệt Phần Tử Theo Left -> Right -> Node
void BST::PostOder(Node* root){
	if(root != NULL){
		PostOder(root->left);
		PostOder(root->right);
		cout << root->data;
	}
}


//Trả Về Phần Tử Bé Nhất Bên Trai
Node* BST::LeftMostAnimal(Node* root){
    while(root->left != NULL)
        root = root->left;
    return root;
}


//Xóa Phần Tử
Node* BST::Delete(Node* root, Animal *al1){
    if (root == NULL)
        return root;
    if (LeftOf(al1,root))
        root->left = Delete(root->left,al1);
    else if (RightOf(al1,root))
        root->right = Delete(root->right,al1);
    else
    {
        if (root->left == NULL)
        {
            Node* newRoot = root->right;
            delete root;
            return newRoot;
        }
        if (root->left == NULL)
        {
            Node* newRoot = root->left;
            delete root;
            return newRoot;
        }
        root = LeftMostAnimal(root->right);
        root->right = Delete(root->right,al1);
    }
    return root;
}

