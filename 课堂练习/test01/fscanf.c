#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	char str[4][10]={"ifconfig","ls -al","pwd","top"};

	for(int i=0;i<4;i++){
		// for(int j=0;j<10;j++){
			// fprintf(stdout, "%s",str[i] );

			system(str[i]);

			sleep(3);
		// }
	}

	return 0;
}