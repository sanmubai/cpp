#include <iostream>
using namespace std;

class global_complex
{
private:
	double real;
	double imag;

public:
	global_complex():real(0.0),imag(0.0){}
	global_complex(double a,double b):real(a),imag(b){}

	void display()const;

	friend global_complex operator+(const global_complex &A,const global_complex &B);
	
};

void global_complex::display()const{
	cout<<real<<"+"<<imag<<"i"<<endl;
}

global_complex operator+(const global_complex &A,const global_complex &B){
	global_complex C;

	C.real=A.real+B.real;
	C.imag=A.imag+B.imag;

	return C;
}

int main(){

	global_complex A(3.3,2.2);

	global_complex B(1.1,1.1);

	global_complex C=A+B;

	C.display();

	return 0;
}

