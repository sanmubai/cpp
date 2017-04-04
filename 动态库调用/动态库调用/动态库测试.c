#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlltest.h"

int main() {

	void *handle = NULL;

	int ret=cltSocketInit(&handle);

	if (ret !=0) {
		printf("cltSocketInit error:code %d\n",ret);
	}

	system("pause");
}