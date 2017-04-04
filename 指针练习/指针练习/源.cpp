#include _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sortArr(char **a,int numA,char (*b)[10],int numB,char ***arr) {
	if (a == NULL || b == NULL || arr == NULL) {
		return -1;
	}
	int i, j;
	char **arrp = NULL;
	arrp = (char **)malloc((numA+numB)*sizeof(char *));

	if (arrp==NULL) {
		return -2;
	}

	for (i = 0; i < (numA + numB); i++) {
		arrp[i] = NULL;
		arrp[i] = (char *)malloc(20);

		if (arrp[i] == NULL) {
			return -2;
		}
	}

	//copy a;
	for (i = 0; i < numA;i++) {
		strcpy(arrp[i],a[i]);
	}

	//copy b;
	for (j = 0; j < numB; j++) {
		strcpy(arrp[i+j],b[j]);
	}

	*arr = arrp;
	return 0;
}

int printArr(char **arr,int len) {
	if (arr == NULL) {
		return -1;
	}
	int i = 0;
	for (; i < len; i++) {
		printf("arr[%d]:%s\n",i,arr[i]);
	}

	return 0;
}

void freeArr(char *arr) {

}

int main() {

	char *a[] = {"abcd","bbb","ccc","2222","eeee"};
	char b[4][10] = {"3333","34444","hhhhh","qqqqq"};

	char **arr = NULL;

	//printf("%d", sizeof(a) / sizeof(char *));
	//printf("%d",sizeof(*b));

	sortArr(a,sizeof(a)/sizeof(char *),b,sizeof(b)/sizeof(*b),&arr);

	printArr(arr,9);

	system("pause");
}
