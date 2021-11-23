#include <iostream>
#include <thuvien.h>
using namespace std;


NodeL* SList::CreateNodeL(Animal *v){
	NodeL* p = new NodeL;
    Animal *v1 = new Animal(v);
	p->data = v1;	
	p->next = NULL;	
	return p; 
}

//khoi tao
SList::SList(){
    head = NULL;
    tail = NULL;
    size =0;
}

// giai phong bo nho
SList::~SList(){
    head = NULL;
    tail = NULL;
    size = 0;
}

// them vao cuoi
void SList::addLast(Animal *v){
    NodeL *p = CreateNodeL(v);
    if(size == 0){
        head = p;
        tail = p;
    }
    else{
        tail->next = p;
        tail = p;
    }
    size = size + 1;
}

// Duyet cac ptu trong danh sach
void SList::traverse() const{
    NodeL *p = head;
    while(p != NULL){
    cout << p->data; 
        p = p->next;
    }
    cout <<endl;
    delete p;   
}

// Tim kiem 
NodeL *SList::searchName(string name){
	NodeL *p = head;
    while(p != NULL){
        if(p->data->getName() == name)
            break;
        p=p->next;
    }
    return p;
}

// Sap xep
void SList::sort(){
    for(NodeL *p = head; p->next != NULL; p=p->next){
        for(NodeL *q = p->next; q != NULL; q = q->next){
            if(p->data->getID() > q->data->getID()){
                swap(p->data,q->data);
            }
        }
    }
}

// tim 1 phan tu ngay truoc phan tu bat ky
NodeL* SList::previous(NodeL *p) {
	NodeL *t = head;
	while (t->next != p)
		t = t->next;
	return t;
}


void SList::removeFirst(){
   if(size == 0){
   	    cout <<" No Name Has Be Found ! ";
	}else{
		NodeL*t = head;
		head=head->next;
		delete t;
		size--;
    }
}


void SList::removeLast(){
	NodeL *pre = previous(tail);
	NodeL*t =tail;
	pre->next=NULL;
	tail=pre;
	delete t;
	size--;
}	

// xoa 1 ptu 
void SList::removeName(){
    string name;
    cout<<"Enter the animal that need to delete: ";
    fflush(stdin);
    getline(cin,name);
    NodeL *p = head;
    for(p;p!=NULL;p=p->next){
        if(p->data->getName()==name){
            if(p == head){
                removeFirst();
                break;
            }
            else if(p==tail){
                removeLast();
                break;
            }
            else{
                NodeL *pre = previous(p);
                pre->next = p->next;
                delete p;
                size--;
            }
        }
    }
    if(p == NULL){
        cout <<" No Name Has Be Found ! " <<endl;
    }
}