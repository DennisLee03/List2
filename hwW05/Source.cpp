#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct sData {
	int x, y;
	struct sData *next;
};
void fillin(struct sData *L);
void output(struct sData *L);
void letfree(struct sData *L);
void main(){
	struct sData *list;
	if ((list = (struct sData *)malloc(10 * sizeof(struct sData))) == NULL) {
		printf("Failed in allocating memory\n");
		exit(0);
	}
	//else printf("Succeeded in allocating memory\n");
	for (int i = 0;i < 9;i++) list[i].next = &list[i + 1];
	list[9].next = NULL;//±µ¦a
	//printf("Succeeded in linking\n");
	fillin(list);
	output(list);
	letfree(list);
	//output(list);
}
void fillin(struct sData *L) {
	int i = 0;
	while (L != NULL) {
		L->x = i;
		L->y = i + 100;
		i++;
		L = L->next;
	}
}
void output(struct sData *L) {
	while (L != NULL) {
		printf("%d.%d\n", L->x, L->y);
		L = L->next;
	}
	//for (int i = 0;i < 10;i++) printf("%d.%d\n", L[i].x, L[i].y);
	//printf("Succeeded in printing linked list\n");
}
void letfree(struct sData *L) {
	free(L);
	//printf("Succeeded in freeing memory\n");
}