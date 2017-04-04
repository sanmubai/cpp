#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getSubCount.h"

int getSubCount(char *str,char *sub,int *count){

	int ret=0;
	if(str == NULL || sub == NULL || count == NULL){
		ret =-1;
		printf("error: %d ;str == NULL || sub == NULL || count == NULL\n",ret);
		return ret;
	}

	int num=0;

	while(*str != '\0'){
		str=strstr(str,sub);

		if(str==NULL){
			break;
		}

		str=str+strlen(sub);
		num++;
	}

	*count=num;
	return ret;
}

int main(){

	char str[30]="abcd123abcd234ssssabcdabc";

	char sub[5]="abc";

	int count;

	int res=getSubCount(str,sub,&count);

	if(res){
		printf("fuck\n");

	}else{
		printf("find: %d;\n", count );
	}

}