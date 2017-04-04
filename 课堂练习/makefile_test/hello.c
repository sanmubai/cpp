#include <stdio.h>
#include <stdlib.h>
#include "add.h"

int main(){

	int a=4;
	int b=5;
	printf("%d + %d 的值是： %d ;\n" , a , b , add(a,b) );

	return 0;
}