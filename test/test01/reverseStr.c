#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverseStr(const char *str,char *buff){
	int ret=0;

	if(str == NULL || buff == NULL){
		ret =-1;
		return ret;
	}

	char *buffTemp=buff;

	strcpy(buffTemp,str);

	int i=0;
	int j=strlen(str)-1;

	while(i<j){
		char temp=buffTemp[i];
		buffTemp[i]=buffTemp[j];
		buffTemp[j]=temp;
		i++;
		j--;
	}

	return ret ;
}

int main(){

	char *str = "abcdefgsssss;";

	char buff[20]="111111111111";

	int rev=reverseStr(str,buff);

	if(rev != 0){
		printf("error: code - %d;\n", rev);
		return rev;
	}

	printf("after reverse:%s\n",buff);
}