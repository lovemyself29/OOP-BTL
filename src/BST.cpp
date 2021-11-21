#include <iostream>
#include <thuvien.h>
using namespace std;

Node* BST::CreateNode(Animal *al){
	Node * p= new Node; 
    Animal *al1 = new Animal(al);
	p->data = al1;
	p->left = NULL;
	p->right = NULL; 
	return p; 
} 

//Duyet Phan Tu Ben Trai Root > Left va Right > Root
int BST::LeftOf(Animal *al,Node* root){    
    return (al->getID() < root->data->getID());
}

int BST::RightOf(Animal *al,Node* root){    
    return (al->getID() > root->data->getID());
}

//Chen Phan Tu
Node* BST::Insert(Node* &root,Animal *al1){
    if ( root == NULL){
        Node* node = CreateNode(al1);
        size++;
        return node;
    }
    else{
    	if(LeftOf(al1,root))
    		root->left = Insert(root->left,al1);
    	else if(RightOf(al1,root))
    		root->right = Insert(root->right,al1);
	}
        // size ++;
		return root;
}

//Tim Kiem Phan Tu
Node* BST::SearchID(Node *root,Animal *al1){
	if (root == NULL){
		return NULL;
	}
	
	if(root->data->getID() == al1->getID()){
        return root;
    }
	else if(LeftOf(al1,root))
		SearchID(root->left,al1);
	else if(RightOf(al1,root))
		SearchID(root->right,al1);
	return root;
}

//Tra Ve Phan Tu Bu Nhat Ben Trai
Node* BST::LeftMostAnimal(Node* root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

//Duyet Phan Tu Theo Left -> Right -> Node
void BST::PostOrder(Node* root){
	if(root != NULL){
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->data;
	}
}

void BST::InOrder(Node* root){
	if(root != NULL){
		InOrder(root->left);
		cout << root->data;
		InOrder(root->right);
	}
}

//Xoa Phan Tu
Node* BST::Delete(Node* &root, Animal *al1){
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
    size --;
    return root;
}