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

int getValue(const char *str,const char *key,char *value,int *len){
	int ret=0;

	if(str==NULL || key==NULL || value==NULL || len==NULL){
		ret=-1;
		return ret;
	}

	char *p=NULL;
	char temp[1024];
	int num=0;

	//查找key 是否存在

	p=strstr(str,key);

	if(p==NULL){
		return 0;
	}

	//取出＝ 之后的内容

	p=strstr(str,"=");

	if(p==NULL){
		return 0;
	}

	p=p+1;
	//取出value

	trim(p,temp,&num);

	strcpy(value,temp);

	*len=num;
	return ret;

}
int main(){

	char *str="   QQ  =      1sdf1111112  ";

	char *key="QQ";
	char value[1024];
	int len=0;

	int rev=getValue(str,key,value,&len);

	if(rev != 0){
		printf("fuck %d;\n",rev);
		return rev;
	}

	printf("value:%s\n", value);
	printf("length:%d\n",len );

}
