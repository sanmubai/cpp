#include <stdio.h>
#include <stdlib.h>

void changeP(int **p);
void changePP(int ***p);
void add(int *a,int *b);

int a=30;
int b=40;
int *p=&a;
int *p2=&b;

int **pp=&p;

int main(){

	printf("a=%d;&a=%x;\n",a,(unsigned int)p );
	printf("*p=%d;&p=%x;\n",*p,(unsigned int)&p );

	// changeP(&p);

	printf("*p=%d;&p=%x;\n",*p,(unsigned int)&p );
	printf("**pp=%d;&pp=%x;\n",**pp,(unsigned int)&pp );

	changePP(&pp);
	printf("**pp=%d;&pp=%x;\n",**pp,(unsigned int)&pp );

	add(&a,&b);

	void (*p)(int *,int*);
	p=add;

	p(&a,&b);

	return 0;
}

void changeP(int **p){
	*p=&b;
}

void changePP(int ***p){
	*p=&p2;
}

void add(int *a,int *b){

	printf("a+b=%d;\n",*a+*b );
}

