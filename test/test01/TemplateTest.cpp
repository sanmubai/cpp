#include <iostream>
using namespace std;

template<typename T,int N> class TemplateTest
{
public:
	TemplateTest();
	// ~TemplateTest();

	T & operator[](int);
	int length(){return len;}

private:
	T *p;
	int len;
	
};

template<typename T,int N> TemplateTest<T,N>::TemplateTest(){
	p=new T[N];
	len=N;
}

template<typename T,int N> T & TemplateTest<T,N>::operator[](int i){
	if(i<0||i>len){
		cout<<"Exception:TemplateTest range out of bounds!"<<endl;
	}
	return p[i];
}

int main(){
	TemplateTest<float,10> arr;

	int i,len=arr.length();

	for(i=0;i<len;i++){
		arr[i]=i*3.02;
	}

	for(i=0;i<len;i++){
		cout<<"arr["<<i<<"]="<<arr[i]<<endl;
	}

	return 0;
}