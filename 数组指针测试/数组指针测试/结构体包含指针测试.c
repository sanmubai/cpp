#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Teacher {
	char *name;
	int age;
	char **student;
};

int createArr(struct Teacher **pArr,int num) {

	//int snum = 3;//每个老师学生的数量；
	int ret = 0;
	if (pArr == NULL) {
		ret = -1;
		printf("Error:code %d;\n",ret);
		return ret;
	}

	struct Teacher *p = NULL;

	p =(struct Teacher *) malloc(num*sizeof(struct Teacher));

	if (p == NULL) {
		ret = -2;
		printf("Error:code %d",ret);
		return ret;
	}

	for (int i = 0; i < num; i++) {
		memset(p+i,0,sizeof(struct Teacher));

		p[i].name = (char *)malloc(sizeof(64));
		memset(p[i].name,0,sizeof(64));

		p[i].student = (char **)malloc(num*sizeof(char *));
		memset(p[i].student, 0, num*sizeof(char *));

		for (int j = 0; j < num;j++) {
			p[i].student[j] = (char *)malloc(32);
			memset(p[i].student[j],0,32);
		}
	}
	*pArr = p;
	return ret;
}

void sortStruct(struct Teacher *p, int num) {
	if (p == NULL) {
		return;
	}

	struct Teacher *pt = p;
	struct Teacher temp;

	for (int i = 0; i < num; i++) {
		for (int j = i; j < num; j++) {
			if (pt[i].age>pt[j].age) {
				temp = pt[i];
				pt[i] = pt[j];
				pt[j] = temp;
			}
		}
	}
}

void printStruct(struct Teacher *p, int num) {
	if (p == NULL) {
		return;
	}
	for (int i = 0; i < num; i++) {
		printf("arr[%d].age=%d;\n", i, p[i].age);
		for (int j = 0; j < num;j++) {
			printf("arr[%d] 的学生名字：%s\n",i,p[i].student[j]);
		}
	}
}

void freeStruct(struct Teacher *p,int num) {

}

int main() {
	
	struct Teacher *arr=NULL;
	int num=3;

	createArr(&arr,num);

	for (int i=0; i < num; i++) {
		printf("请输入年龄：\n");
		scanf("%d", &arr[i].age);

		for (int j = 0; j < num;j++) {
			printf("请输入学生名字：\n");
			scanf("%s", arr[i].student[j]);
		}
	}


	printf("排序前：\n");
	printStruct(arr, num);
	printf("排序后：\n");
	sortStruct(arr, num);
	printStruct(arr, num);

	system("pause");

}
