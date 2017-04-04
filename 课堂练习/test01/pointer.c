#include <stdio.h>
#include <stdlib.h>

char a='A';
char b='B';

void changeP(char *p);
void changePP(char **p);

int main(){
	char *p = &a;

	printf("1:%c\n",*p);

	printf("1p地址:%x\n",(unsigned int)&p );

	// changeP(&b);

	// printf("2:%c\n",*p);

	changePP(&p);

	printf("4:%c\n",*p);

	return 0;
}

void changeP(char *p){

	p=&b;
	printf("3:%c\n",*p);
}

void changePP(char **p){

	printf("2p地址:%x\n",(unsigned int)p );
	*p=&b;
}