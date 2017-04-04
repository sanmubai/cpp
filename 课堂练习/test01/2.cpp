#include <iostream>

using namespace std;

int main(){

	int *p;
	
	p=new int(10);

	cout << *p << "\n";

	delete p;

	return 0;
}