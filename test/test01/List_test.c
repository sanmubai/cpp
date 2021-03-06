#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 单向链表的增删改 ，反转，打印
struct LIST{
	int data;
	struct LIST *next;
};

int createList(struct LIST **Head);
int insertList(struct LIST *Head,int x,int y);
int deleteList(struct LIST *Head,int x);
int destroyList(struct LIST *Head);
int reverseList(struct LIST *Head);
int printList(struct LIST *Head);


int createList(struct LIST **Head){

	if(Head==NULL){
		return -1;
	}

	struct LIST *pHead=NULL, *pCur=NULL,*pT=NULL;
	int data=0;

	pHead=(struct LIST*)malloc(sizeof(struct LIST));

	if(pHead==NULL){
		return -1;
	}

	pHead->data=0;
	pHead->next=NULL;

	pCur=pHead;

	while(1){
		printf("输入列表的值（－1 quit）:\n");
		scanf("%d",&data);

		if(data == -1){
			break;
		}

		//循环创建元素

		pT=(struct LIST*)malloc(sizeof(struct LIST));

		if(pT == NULL){
			destroyList(pHead);

			return -2;
		}

		pT->data=data;
		pT->next=NULL;

		pCur->next=pT;
		pCur=pT;

	}

	*Head=pHead;

	return 0;
}

int insertList(struct LIST *Head,int x,int y){

	if(Head == NULL){
		return -1;
	}

	struct LIST *pHead=NULL, *pCur=NULL, *pPre=NULL,*pM=NULL;

	pHead=Head;
	pCur=pHead->next;
	pPre=pHead;

	pM=(struct LIST *)malloc(sizeof(struct LIST));

	if(pM==NULL){
		return -2;
	}
	pM->data=y;
	pM->next=NULL;

	while(pCur != NULL){
		if(pCur->data==x){
			break;
		}
		pPre=pCur;
		pCur=pCur->next;
	}

	pPre->next=pM;
	pM->next=pCur;

	return 0;
}
int deleteList(struct LIST *Head,int x){
	if(Head==NULL){
		return -1;
	}

	struct LIST *pHead=NULL,*pCur=NULL,*pPre=NULL;

	pHead=Head;
	pCur=pHead->next;
	pPre=pHead;

	while(pCur != NULL){
		if(pCur->data == x){
			
			break;
		}
		pPre=pCur;
		pCur=pCur->next;
	}

	if(pCur == NULL){
		printf("没有找到节点：%d\n", x);
		return -2;
	}
	pPre->next=pCur->next;

	return 0;
}
int destroyList(struct LIST *Head){

	if(Head == NULL){
		return -1;
	}
	struct LIST *pHead=NULL,*pCur=NULL,*pT=NULL;
	pHead=Head;
	pCur=pHead;

	while(pCur != NULL){

		pT=pCur->next;
		free(pCur);
		pCur=pT;
	}

	return 0;
}
int reverseList(struct LIST *Head){
	if(Head == NULL) {
		return -1;
	}

	struct LIST *pHead=NULL,*pCur=NULL,*pPre=NULL,*pT=NULL;

	pHead=Head;
	pPre=pHead->next;
	pCur=pPre->next;

	pPre->next=NULL;

	if(pCur==NULL){
		return 0;
	}

	while(pCur != NULL){

		pT=pCur->next;

		pCur->next=pPre;

		pPre=pCur;

		pCur=pT;
	}

	pHead->next=pPre;


	return 0;
}

int printList(struct LIST *Head){
	if(Head==NULL){
		return -1;
	}

	struct LIST *pT=NULL;
	int i=0;

	pT=Head->next;

	while(pT != NULL){
		printf("LIST[%d] = %d ;\n",i,pT->data);
		pT=pT->next;
		i++;
	}
	return 0;
}

int main(){
	struct LIST *pHead=NULL;

	int x=20,y=999;

	printf("createList:\n");
	createList(&pHead);
	printList(pHead);

	printf("insert value y before x:\n");
	insertList(pHead,x,y);
	printList(pHead);

	printf("deleteList x:\n");
	deleteList(pHead,20);
	printList(pHead);

	printf("reverseList:\n");
	reverseList(pHead);
	printList(pHead);

	destroyList(pHead);
}