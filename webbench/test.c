#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	
	int i;
	int nums=20;
	pid_t pids[nums];

	if(0){
		printf("0 is true\n");
	}else{
		printf("0 is false\n");
	}

	if(-1){
		printf("-1 is true\n");
	}else{
		printf("-1 is false\n");
	}

	for(i=0;i<nums;i++){
		pids[i]=fork();

		if(pids[i]<(pid_t) 0){
			
			printf("fork error\n");
			exit(1);
		}

		if(pids[i]==(pid_t)0){
			break;
		}

		if(pids[i]>0){
			wait(pids+i);
		}

	}


	printf("%d\n",i);

	return 0;
}