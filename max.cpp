#include <iostream>

using namespace std;

int max(int a,int b,int c);

int main(){
	int a=3,b=-15,c=12,d;

	d=max(a,b,c);

	cout <<"max value is " <<d<<endl;

	return 0;
}

inline int max(int a,int b,int c){
	if(a>c) c=a;
	if(b>c) c=b;

	return c;
}