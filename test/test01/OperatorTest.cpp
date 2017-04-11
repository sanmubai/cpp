#include <iostream>
using namespace std;

class complex
{
private:
	double real;
	double imag;

public:
	complex():real(0.0),imag(0.0){};
	complex(double a,double b):real(a),imag(b){};

	friend complex operator+(const complex &A,const complex &B);
	friend complex operator-(const complex &A,const complex &B);
	friend complex operator*(const complex &A,const complex &B);	
	friend complex operator/(const complex &A,const complex &B);

	friend istream & operator>>(istream & in,const complex &A);	
	friend ostream & operator<<(ostream & out,const complex &A);	
};

complex operator+(const complex &A,const complex &B){
	complex C;

	C.real=A.real+B.real;
	C.imag=A.imag+B.imag;

	return C;
}

complex operator-(const complex &A,const complex &B){
	complex C;

	C.real=A.real-B.real;
	C.imag=A.imag-B.imag;

	return C;
}

complex operator*(const complex &A,const complex &B){
	complex C;

	C.real=A.real*B.real;
	C.imag=A.imag*B.imag;

	return C;
}


complex operator/(const complex &A,const complex &B){
	complex C;

	C.real=A.real/B.real;
	C.imag=A.imag/B.imag;

	return C;
}

istream & operator>>(istream & in,const complex &A){
	in >> A.real >> A.imag;
	return in;
}


ostream & operator<<(ostream & out,const complex &B){
	out<<A.real<<"+"<<A.imag<<"i"<<endl;
	return out;
}

int main(){
	complex A,B,C;

	cin>>A>>B;

	cout<<A<<endl;
	cout<<B<<endl;

	// complex C=A+B;

	// cout<<"A+B:"<<C<<endl;


	return 0;
}
















