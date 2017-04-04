#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int a[5] = { 2,3,3, 4,6};

	printf("%x %x\n", a, a + 1);
	printf("%d %d\n",&a,&a+1);

	system("pause");
	return 0;
}

//struct Teacher {
//	char name[64];
//	int age;
//	char title[32];
//};
//
//void sortStruct(struct Teacher *p,int num) {
//	if (p==NULL) {
//		return;
//	}
//
//	struct Teacher *pt = p;
//	struct Teacher temp;
//
//	for (int i = 0; i < num; i++) {
//		for (int j = i; j < num;j++) {
//			if (pt[i].age>pt[j].age) {
//				temp = pt[i];
//				pt[i] = pt[j];
//				pt[j] = temp;
//			}
//		}
//	}
//}
//void printStruct(struct Teacher *p,int num) {
//	if (p==NULL) {
//		return;
//	}
//	for (int i = 0; i < num;i++) {
//		printf("arr[%d].age=%d;\n", i,p[i].age);
//	}
//}
//
//int main3() {
//
//	struct Teacher t1 = {"ZhangSan",28,"PE"};
//	struct Teacher t2 = {"LiuLiu",32,"PE"};
//
//	struct Teacher Arr[10];
//
//	int num = 6;
//	int i = 0;
//	int t_age = 0;
//
//	for (; i < num;i++) {
//		printf("ÇëÊäÈëÄêÁä£º\n");	 
//		scanf("%d", &t_age);
//
//		Arr[i].age = t_age;
//	}
//	printf("ÅÅÐòÇ°£º\n");
//	printStruct(Arr,num);
//	printf("ÅÅÐòºó£º\n");
//	sortStruct(Arr,num);
//	printStruct(Arr,num);
//
//	system("pause");
//
//
//}