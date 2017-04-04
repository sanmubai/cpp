#include <stdio.h>
#include <stdlib.h>

int strcopy(char *from, char *to ){

	int ret=0;

	if(from == NULL || to == NULL){
		ret =-1;
		printf("error: %d;from == NULL || to == NULL\n", ret);
		return ret;
	}

	// while(*from != '\0'){
	// 	*to=*from;
	// 	to++;
	// 	from++;
	// }
	// *to='\0';

	while((*to++ = *from++) != '\0'){

	}

	return ret;
}

int main(){
	char from[20] = "abcdefg111";

	char to[20] = "aaassssss";

	int ret=strcopy(from,to);

	if(ret){
		printf("fuck;\n");
	}else{
		printf("to: %s\n", to);
	}

}