#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>


int main(){
	char buf[1024];
	char *cgibuf="/usr/local/bin/php -f cgi.php";
	char *path="index.php";

	if(isspace((int)(' '))){

		printf("空格是true\n");
	}else{
		printf("空格是false\n");
	}
	strcat(buf,"sdf");
	printf("%s\n",buf );

	execl("/usr/local/bin/php", "php","cgi.php", NULL);

	return 0;
}