#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int trim(const char *str,char *buff,int *len){
	int ret =0;

	if(str == NULL || buff == NULL || len == NULL){
		ret=-1;
		return ret;
	}

	const char *strTemp=str;
	int i=0;
	int j=strlen(str)-1;

	while(isspace(strTemp[i])){
		i++;
	}

	while(isspace(strTemp[j])){
		j--;
	}

	int count=j-i+1;

	memcpy(buff,&strTemp[i],count);

	*(buff+count)='\0';
	*len=count;

	return ret;
}

int main(){

	char *str="       asdfsdfs12312312;  ";

	char buff[1024];

	int len=0;

	int rev=trim(str,buff,&len);

	if(rev != 0){
		printf("fuck %d;\n",rev);

		return rev;
	}

	printf("new str:%s\n", buff );
	printf("length:%d\n", len );


}
