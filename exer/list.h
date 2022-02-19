#ifndef _LIST_H_
	#define _LIST_H_
	
	#include<stdio.h>
	#include<stdlib.h>

	#define CHAR 1
	#define INT sizeof(int)
	#define DOUBLE sizeof(double)
	#define STRING 50*sizeof(char)

	typedef struct _elem{
		void *data;
		int type;
		struct _elem* nex[2];
	} elem;

	
	#define ELEM sizeof(elem)

	elem* NewList();
	int IsListEmpty(elem *head);
	elem* NewElem(int type,...);
	int DeleteList(elem *head);
	int AddElem(elem **head,int pos,elem *x);
	int DeleteElem(elem **head,int pos);
	int ListSize(elem *head);
	int AddListFirst(elem **head,elem *x);
	int AddListLast(elem **head,elem *x);
	int DeleteListFirst(elem **head);
	int DeleteListLast(elem **head);
	int PrintList(elem *head);

#endif
