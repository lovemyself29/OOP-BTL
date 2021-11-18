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


// thêm vào cuối
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
void SList::insertAfter(NodeL *p, Animal *v){
    NodeL *q = CreateNodeL(v);
    if(p == NULL){
        addLast(v);
    }
    else{
        q->next = p->next;
        p->next = q;
    }
}


// Duyet cac ptu trong danh sach
void SList::traverse() const{
    NodeL *p = head;
    while(p != NULL){
        cout << p->data <<"\t"; 
        p = p->next;
    }
    cout <<endl;
    delete p;
}


// Tìm kiếm 
NodeL *SList::searchName(NodeL *p, string name){
    while(p != NULL){
        if(p->data->getName() == name)
            break;
        p=p->next;
    }
    return p;
}


// Sắp xếp
void SList::sort(){
    for(NodeL *p = head; p != tail; p=p->next){
        for(NodeL *q = p->next; q != NULL; q = q->next){
            if(p->data->getID() > q->data->getID()){
                swap(p->data,q->data);
            }
        }
    }
}


// tìm 1 phần tử ngay trước phần tử bất kì
NodeL* SList::previous(NodeL *p) {
	NodeL *t = head;
	while (t->next != p)
		t = t->next;
	return t;
}


void SList::removeFirst(){
   if(size == 0){
   	    cout <<"Khong tim thay ten can xoa";
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
    cout<<"Nhap ten dong vat can xoa:";
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
                break;
            }
        }
    }
    if(p == NULL){
        cout <<"Khong tim thay ten dong vat can xoa"<<endl;
    }
}