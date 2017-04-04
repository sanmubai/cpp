#include <iostream>
using namespace std;

class complex
{
private:
	float real;
	float imag;
public:
	complex():real(0.0),imag(0.0){}
	complex(float a,float b):real(a),imag(b){}
	complex operator+(const complex & A) const;
	void display()const;
};

complex complex::operator+(const complex & A)const{
	complex B;

	B.real=A.real+real;
	B.imag=A.imag+imag;

	return B;
}

void complex::display()const{
	cout<<real<<" + "<<imag<<"i"<<endl;
}

int main(){

	complex c1(4.3,5.8);
	complex c2(2.4,3.7);

	complex c3;

	c3=c1+c2;

	c3.display();

	return 0;
}