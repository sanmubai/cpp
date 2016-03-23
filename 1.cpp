#include <stdio.h>

int main(){

	class Student{

		public:
			char const * name;
			int age;
			float score;

		public:
			void say(){
				printf("%s的年龄是 %d,成绩是 %f\n",name,age,score );
			}
		
	};

	class Student stu;

	stu.name="小米";
	stu.age=23;
	stu.score=92.5f;

	stu.say();

	return 0;
}