#include <iostream>
#include <conio.h>
#include <thuvien.h>
using namespace std;


void MENU(){
	Animal* al;
    long allSize[2] = {0} ;
    char k, c;
	do{
		cout << "\t-------------------------------------------------------------------" << endl;
        cout << "\t|                             +|MENU|+                            |" << endl;
        cout << "\t-------------------------------------------------------------------" <<endl;
    	cout << "\t+       MENU BUILDING PROGRAM WORKING WITH CLASS OF ANIMALS       +\n" << endl;
        cout << "\t+                CHOOSE THE FOLLOWING FUNCTIONS:                  +\n" << endl;
        cout << "\t+            1. TO WORK WITH THE CLASS OF GRAMINIVORE             +\n" << endl;
        cout << "\t+            2. TO WORK WITH THE CLASS OF HYPERCARNIVORE          +\n" << endl;
        cout << "\t+            3. TO WORK WITH THE CLASS OF MICROORGANISM           +\n" << endl;
        cout << "\t+            4. TO WORK WITH THE LINKED LIST                      +\n" << endl;
        cout << "\t+            5. TO QUANTITY STATISTICS                            +\n" << endl;
        cout << "\t+                          -ESC . EXIT-                           +\n" << endl;
        cout << "\t-------------------------------------------------------------------" <<endl;
        int panel;
        cout << "\n\n\t Please Choose A Function:  ";
        cin >> panel;
        switch (panel){
            case 1: {
                BST tree;
                tree.root = NULL;
                tree.size = 0;
                cout << "\n\t Welcome to the Graminivore class" << endl;
                cout << "\n\t Enter Number Of Animal: ";
                int n;
                cin >> n;
                for(int i = 0; i < n; i++){
                    al = new Grami;
                    cin >> al;
                    tree.root = tree.Insert(tree.root, al);
                }
                cout << "\n\t Now choose your work \n";
                int work2;
                char k, c;
                do{
                	cout << "\t\t          | THE GRAMINIVORE MENU |        " << endl;
                    cout << "\t\t-------------------------------------------" << endl;
                    cout << "\t\t+  1.  PRINT GRAMINIVORE WITH TREE LIST   +\n" << endl;
                    cout << "\t\t+  2.            SORTED LIST  	  	  +\n" << endl;
                    cout << "\t\t+  3.          ADD MORE ANIMAL		  +\n" << endl;
                    cout << "\t\t+  4.           DELETE ANIMAL 		  +\n" << endl;
                    cout << "\t\t+  5.         SEARCH FOR ANIMAL		  +\n" << endl;
                    cout << "\t\t+ 	         -ESC. EXIT-	 	  +\n" << endl;
                    cout << "\t\t-------------------------------------------" << endl;
                    cout << "\n\n\t Please choose a function:  ";
                    cin >> work2;
                    switch(work2){
                        case 1: {
                            tree.PostOrder(tree.root);
                        }break;
                        case 2: {
                            cout << "\t Here Is Sorted Tree \n" << endl;
                            tree.InOrder(tree.root);
                        }break;
                        case 3: {
                            Animal *all = new Grami;
                            cout << "\t Enter Another Animal \n";
                            cin >> all;
                            tree.Insert(tree.root, all);
                        }break;
                        case 4: {
                            cout << "\t Delete Animal - Enter Animal ID:  ";
                            int id;
                            Animal *temp1 = new Grami;
							cin >> id;
							do{
							if(id < 1){
								cout <<"\t Try Again:";
								cin >> id;
							}
							}while (id < 1);
                            temp1->setID(id);
                            tree.Delete(tree.root, temp1);
                            cout <<"\t\tDeleted Success !"<<endl;
                        }break;
                        case 5: {
                            cout << "\t Search Animal By ID: ";
                            Animal *temp2 = new Grami;
                            int id;
							cin >> id;
							do{
							if(id < 1){
								cout <<"\t Try Again:";
								cin >> id;
							}
							}while (id < 1);
                            temp2->setID(id);
                            cout << tree.SearchName(tree.root, temp2)->data;
                        }break;
                    }
                        cout << "\n\tDo You Want To Exit ?(esc)"<<endl;
                        k = c;
                        c = getch();
                        
                }while(c!=27);
                allSize[0] = tree.size;
            }break;
            case 2: {
                BST tree;
                tree.root = NULL;
                tree.size = 0;
                cout << "\n\t Welcome To The Hypercarnivore Class !" << endl;
                cout << "\n\t Enter Number Of Animal: ";
                int n;
                cin >> n;
                for(int i = 0; i < n; i++){
                    al = new Hyper;
                    cin >> al;
                    tree.root = tree.Insert(tree.root, al);
                }
                cout << "\n\t Now Choose Your Work \n";
                int work3;
                char k,c;
                do{
                    cout << "\t\t          | THE HYPERCARNIVORE MENU |        " << endl;
                    cout << "\t\t----------------------------------------------" << endl;
                    cout << "\t\t+  1.  PRINT HYPERCARNIVORE WITH TREE LIST   +\n" << endl;
                    cout << "\t\t+  2.            SORTED LIST  	  	     +\n" << endl;
                    cout << "\t\t+  3.          ADD MORE ANIMAL		     +\n" << endl;
                    cout << "\t\t+  4.           DELETE ANIMAL 		     +\n" << endl;
                    cout << "\t\t+  5.         SEARCH FOR ANIMAL		     +\n" << endl;
                    cout << "\t\t+ 	         -ESC. EXIT-	 	     +\n" << endl;
                    cout << "\t\t----------------------------------------------" << endl;
                    cout << "\n\n\t Please Choose A Function:  ";
					cin >> work3; 
                    switch(work3){
                        case 1: {
                            tree.PostOrder(tree.root);
                        }break;
                        case 2: {
                            cout << "\t Here Is Sorted Tree \n" << endl;
                            tree.InOrder(tree.root);
                        }break;
                        case 3: {
                            Animal *all = new Hyper;
                            cout << "\t\t Enter Another Animal \n";
                            cin >> all;
                            tree.Insert(tree.root, all);
                        }break;
                        case 4: {
                            cout << "\t Delete Animal - Enter Animal ID:  ";
                            int id;
                            Animal *temp1 = new Hyper;
							cin >> id;
							do{
							if(id < 1){
								cout <<"\t Try Again:";
								cin >> id;
							}
							}while (id < 1);
                            temp1->setID(id);
                            tree.Delete(tree.root, temp1);
                            cout <<"\t\tDeleted Success !"<<endl;
                        }break;
                        case 5: {
                            cout << "\t Search Animal By ID: ";
                            Animal *temp2 = new Hyper;
                            int id;
							cin >> id;
							do{
							if(id < 1){
								cout <<"\t Try Again:";
								cin >> id;
							}
							}while (id < 1);
                            temp2->setID(id);
                            cout << tree.SearchName(tree.root, temp2)->data;
                        }break;
                    }
                        cout << "\n\tDo You Want To Exit ?(esc)";
                        c = getch();
                        
                }while(c!=27); 
                allSize[1] = tree.size;
            }break;
            case 3: {
                BST tree;
                tree.root = NULL;
                tree.size = 0;
                cout << "\n\t Welcome To The Microorganism Class !" << endl;
                cout << "\n\t Enter Number Of Animal: ";
                int n;
                cin >> n;
                for(int i = 0; i < n; i++){
                    al = new Microo;
                    cin >> al;
                    tree.root = tree.Insert(tree.root, al);
                }
                cout << "\n\t Now Choose Your Work \n";
                int work4; 
                char k, c;
                do{
                    cout << "\t\t          | THE MICROORGANISM MENU |        " << endl;
                    cout << "\t\t---------------------------------------------" << endl;
                    cout << "\t\t+  1.  PRINT MICROORGANISM WITH TREE LIST   +\n" << endl;
                    cout << "\t\t+  2.            SORTED LIST  	  	    +\n" << endl;
                    cout << "\t\t+  3.          ADD MORE ANIMAL		    +\n" << endl;
                    cout << "\t\t+  4.           DELETE ANIMAL 		    +\n" << endl;
                    cout << "\t\t+  5.         SEARCH FOR ANIMAL		    +\n" << endl;
                    cout << "\t\t+ 	         -ESC. EXIT-	 	    +\n" << endl;
                    cout << "\t\t---------------------------------------------" << endl;
                    cout << "\n\n\t Please Choose A Function:  \n";
					cin >> work4;
                    switch(work4){
                        case 1: {
                            tree.PostOrder(tree.root);
                        }break;
                        case 2: {
                            cout << "\t\t Here Is Sorted Tree \n" << endl;
                            tree.InOrder(tree.root);
                        }break;
                        case 3: {
                            Animal *all = new Microo;
                            cout << "\t Enter Another Animal \n";
                            cin >> all;
                            tree.Insert(tree.root, all);
                        }break;
                        case 4: {
                            cout << "\t Delete Animal - Enter Animal ID:  ";
                            int id;
                            Animal *temp1 = new Microo;
                            cin >> id;
                            do{
							if(id < 1){
								cout <<"\t Try Again:";
								cin >> id;
								}
							}while(id < 1);
                            temp1->setID(id);
                            tree.root = tree.Delete(tree.root, temp1);
                            cout <<"\t\tDeleted Success !"<<endl;
                        }break;
                        case 5: {
                            cout << "\t Search  Animal By ID: ";
                            Animal *temp2 = new Microo;
                            int id;
                            cin >> id;
                            do{
							if(id < 1){
								cout <<"\t Try Again:";
								cin >> id;
							}
							}while (id < 1);
                            temp2->setID(id);
                            cout << tree.SearchName(tree.root, temp2)->data;
                        }break;
                    }
                    cout << "\n\tDo You Want To Exit ?(esc)"<<endl;
                    k = c;
                    c = getch();
                        
                }while(c!=27);
                allSize[2] = tree.size;
            }break;
            case 4: {
                Animal *al;
                SList list;
                cout << "\n\t\t\t Welcome To The Linked List ! \n " << endl;
                cout << "\t Now Choose Your Work \n";
                int work5;
                char k, c;
                do{ 
                	cout << "\n\t\t                | THE LINKED LIST MENU |              " << endl;
                    cout << "\t\t------------------------------------------------------" << endl;
                    cout << "\t\t+  1. INSERT THE ANIMAL CLASS WITH THE LINKED LIST  +\n" << endl;
                    cout << "\t\t+  2.   PRINT THE ANIMAL CLASS WITH LINKED LIST     +\n" << endl;
                    cout << "\t\t+  3.                 SORTED LIST		    +\n" << endl;
                    cout << "\t\t+  4.                DELETE ANIMAL 		    +\n" << endl;
                    cout << "\t\t+  5.              SEARCH FOR ANIMAL		    +\n" << endl;
                    cout << "\t\t+                     -ESC . EXIT-	 	    +" << endl;
                    cout << "\t\t------------------------------------------------------" << endl;
                    cout << "\n\n\t Please choose a function:  ";
                    cin >> work5; 
                    switch(work5){
                        case 1: {
                            Animal *al1 = new Grami;
                            cout << "\t Enter: \n" << endl;
                            cin >> al1;
                            list.addLast(al1);
                            
                            al1 = new Hyper; 
                            cout << "\t Enter: \n" << endl;
                            cin >> al1;
                            list.addLast(al1);
                            
                            al1 = new Microo; 
                            cout << "\t Enter: \n" << endl;
                            cin >> al1;
                            list.addLast(al1);
                            
                        }break;
                        case 2: {
                        	list.traverse();
                        }break;
                        case 3: {
                            list.sort();
                            list.traverse();
                        }break;
                        case 4: {
                        	list.removeName();
                            cout << "\n\tDeleted Success!"<<endl;
                        }break;
                        case 5: {
                            Animal *al1 = new Animal;
                            string name;
                            cout <<"\n\t Enter The Animal You Want To Find: "; 
                            fflush(stdin);
                            getline(cin,name);
                            al1->setName(name); 
                            cout << list.searchName(al1)->data;
                             
                        }break;
                    }
                    cout << "\n\t Do you want to exit ?(esc) \n";
                    k = c;
                    c = getch();
                }while(c!=27);
                
            }break;
            case 5: {
                cout << "\n\t\t Welcome To Quantity Statistics ! \n " << endl;
                cout << "\t There is: "<<allSize[0]<<" Graminivore \n"<<endl;
				cout << "\t There is: "<<allSize[1]<<" Hypecarrivore \n"<<endl;   
				cout << "\t There is: "<<allSize[2]<<" Microorganism \n"<<endl;
				cout << "\t Total:   "<< allSize[0] + allSize[1] + allSize[2] ;   	
            }break;
            default : {
                cout << "\n\t You have chosen to Exit the program \n" << endl;
            }break;
        }
        cout << "\n\t Do you want to exit ?(esc)"<<endl;
        k = c;
        c = getch();
        delete al;
	}while(c!=27);
}