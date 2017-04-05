#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	pid_t pr;
	pid_t res=fork();

	if(res < 0){
		printf("fork error\n");
	}else if(res >0){
		//1. waitpid WNOHANG 不阻塞父进程
		// do{
		// 	pr=waitpid(res,NULL,WNOHANG);
		// 	printf("child process not exit\n");
		// 	sleep(1);

		// }while(pr==0);

		// if(pr==res){
		// 	printf("father process exit\n");
		// }else if(pr<0){
		// 	printf("waitpid error\n");
		// }


		//2. wait 阻塞父进程
		pr=wait(NULL);

		if(pr<0){
			printf("wait error\n");
		}else{
			printf("father process exit\n");
		}
		

	}else {

		printf("child process start\n");
		sleep(5);
		printf("child process end\n");
		exit(0);

	}


}