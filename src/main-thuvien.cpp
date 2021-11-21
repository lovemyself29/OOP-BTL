#include <thuvien.h>
#include <iostream>
#include <conoi.h>
using namespace std;

int main(){
    BST list;
    Animal *a = new Animal;
    MENU(list.root, a);
    delete a; 
}