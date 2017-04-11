#include <iostream>
#include <cstdio>
using namespace std;

class Student{
	public:
		char const *name;
		int age;
		float score;
		void say();
};

void Student::say(){
	cout <<"name is : "<<this->name<<";age is : "<<this->age<<"score is : "<<this->score<<";"<<endl;
}

int main2(){
	Student stu;
	stu.name="bb";
	stu.age=12;
	stu.score=99.99;

	Student p_stu=stu;

	p_stu.name="cc";

	printf("stu->%x\n,p_stu->%x\n", &stu,&p_stu);

	stu.say();
	p_stu.say();

	return 0;
}

int main(){
	Student stu;
	stu.name="bb";
	stu.age=12;
	stu.score=99.99;

	Student *p_stu=&stu;

	p_stu->name="cc";

	printf("stu->%x\n,p_stu->%x\n", &stu,p_stu);

	stu.say();
	p_stu->say();

	return 0;
}

int main4(){
    //创建对象
    Student stu;
    stu.name = "小明";
    stu.age = 15;
    stu.score = 92.5f;
    // stu.say();
    //定义指针
    Student *pt_stu = &stu;
    pt_stu->name = "李雷";
    pt_stu->age = 16;
    pt_stu->score = 80;
    stu.say();
    pt_stu->say();
    return 0;
}