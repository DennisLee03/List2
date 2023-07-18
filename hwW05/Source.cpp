#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct sData {
	int x, y;
	struct sData *next;
};
void FillIn(struct sData *L);
void Output(struct sData *L);
void Free(struct sData *L);
void main(){
	struct sData* list, * head = NULL;
	for (int i = 0; i < 10; i++) {
		if ((list = (struct sData*)malloc(sizeof(struct sData))) == NULL) {
			printf("Failed in allocating memory\n");
			exit(0);
		}
		list->next = head;
		head = list;
	}
	FillIn(list);
	Output(list);
	Free(list);
	//output(list);
}
void FillIn(struct sData *L) {
	int i = 0;
	sData* buf = L;
	while (buf != NULL) {
		buf->x = i;
		buf->y = i + 100;
		i++;
		buf = buf->next;
	}
}
void Output(struct sData *L) {
	sData* buf = L;
	while (buf != NULL) {
		printf("%d.%d\n", buf->x, buf->y);
		buf = buf->next;
	}
}
void Free(struct sData *L) {
	sData* buf;
	while (L != NULL) {
		printf("Succeeded in freeing %d.%d memory\n", L->x, L->y);
		buf = L->next;
		free(L);
		L = buf;
	}
}