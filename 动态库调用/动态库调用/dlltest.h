#ifndef _INC_DllTest_H
#define _INC_DllTest_H

#ifdef  __cplusplus
extern "C" {
#endif

	int cltSocketInit(void **handle);

	int cltSocketSend(void *handle, char *buf, int bufLen);

	int cltSocketRecv(void *handle, char *buf, int *bufLen);

	int cltSocketDestory(void *handle);

#ifdef  __cplusplus
}
#endif

#endif