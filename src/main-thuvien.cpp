#include <thuvien.h>
#include <iostream>
using namespace std;

int main(){
	Animal *al = new Animal;
	Microo *mc  = new Microo; 
    cin >> mc;
	cout << mc;
	Hyper *hy = new Hyper; 
	cin >> hy;
	cout << hy;
	Grami *gn = new Grami; 
	cin >> gn;
	cout << gn;
	delete [] al;
	return 0;
}