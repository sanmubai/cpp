#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

	pid_t res;
	res=fork();

	if(res==-1){
		printf("fork error;\n");
	}else if(res==0){

		//不用给出命令的完整路径
		// if(execlp("ps","ps","-ef",NULL)<0){
		// 	printf("execlp error\n");
		// }

		char *envp[]={"PATH=/tmp","USER=bb",NULL};
		//给出名令的完整路径
		// if(execle("/usr/bin/env","env",NULL,envp)<0){
		// 	printf("execle error\n");
		// }

		char *arg[]={"env",NULL};
		if(execve("/usr/bin/env",arg,envp)<0){
			printf("execve error\n");
		}

	}else{
		printf("parent process\n");
	}

	return res;
}