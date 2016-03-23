#include <iostream>

using namespace std;

class FunctionPointer
{
public:
	void (FunctionPointer::*sayhi)();	
	
};

class Test:public FunctionPointer
{
public:
	Test(){
		sayhi=(void(FunctionPointer::*)())(&Test::sayHi);
		(this->*sayhi)();
	}	
	void sayHi(){
		printf("%s\n","hello world!" );
	}
};

int main (){
	Test *fp=new Test();
	delete fp;

	return 0;
}