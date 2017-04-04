#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _SCK_HANDLE {
	char version[16];
	char serverip[16];
	int serverport;
	char *pbuf;
	int buflen;
}SCK_HANDLE;

__declspec(dllexport)
int cltSocketInit(void **handle) {

	if (handle==NULL) {
		return -1;
	}

	SCK_HANDLE *pHandle = NULL;


	return 0;
}

__declspec(dllexport)
int cltSocketSend(void *handle,char *buf,int bufLen) {

	return 0;
}

__declspec(dllexport)
int cltSocketRecv(void *handle,char *buf, int *bufLen) {

	return 0;
}

__declspec(dllexport)
int cltSocketDestory(void *handle) {

	return 0;
}