#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<math.h>
#include<string.h>

#include"list.h"

elem* NewList(){
	elem* tmp=NULL;
	return tmp;
}

int IsListEmpty(elem *head){
	return head==NULL;
}

elem* NewElem(int type,...){
	va_list data; va_start(data,type);
	elem *tmp=malloc(ELEM);
	tmp->data=malloc(type); tmp->type=type;
	tmp->nex[0]=NULL; tmp->nex[1]=NULL;
	if (type==CHAR) *(char*)tmp->data=(char)va_arg(data,int);
	if (type==INT) *(int*)tmp->data=va_arg(data,int);
	if (type==DOUBLE) *(double*)tmp->data=va_arg(data,double);
	if (type==STRING) memcpy(tmp->data,va_arg(data,char*),STRING);
	va_end(data);
	return tmp;
}

int DeleteList(elem *head){
	if (IsListEmpty(head)) return 0;
	elem* tmp=head;
	while (tmp!=NULL){
		elem* del=tmp;
		tmp=tmp->nex[1];
		free(del);
	}
	return 1;
}

int AddElem(elem **head,int pos,elem *x){
	elem *tmp=*head;
	elem *lst=NULL;
	while (pos>0&&tmp!=NULL){
		pos--;
		lst=tmp;
		tmp=tmp->nex[1];
	}
	if (pos>0) return 0;
	x->nex[1]=tmp; x->nex[0]=lst;
	if (lst==NULL) *head=x;
	else lst->nex[1]=x;
	if (tmp!=NULL) tmp->nex[0]=x;
	return 1;
}

int DeleteElem(elem **head,int pos){
	elem *tmp=*head;
	elem *lst=NULL;
	while (pos>1&&tmp!=NULL){
		pos--;
		lst=tmp;
		tmp=tmp->nex[1];
	}
	if (pos>1) return 0;
	elem *x=tmp; tmp=tmp->nex[1];
	if (lst==NULL) *head=tmp;
	else lst->nex[1]=tmp; 
	if (tmp!=NULL) tmp->nex[0]=lst;
	return 1;
}

int ListSize(elem *head){
	elem *tmp=head;
	int cnt=0;
	while (tmp!=NULL){
		cnt++;
		tmp=tmp->nex[1];
	}
	return cnt;
}

int AddListFirst(elem **head,elem *x){
	return AddElem(head,0,x);
}

int AddListLast(elem **head,elem *x){
	return AddElem(head,ListSize(*head),x);
}

int DeleteListFirst(elem **head){
	return DeleteElem(head,1);
}

int DeleteListLast(elem **head){
	return DeleteElem(head,ListSize(*head));
}

int PrintList(elem *head){
	printf("--------------PRINT LIST--------------\n");
	elem *tmp=head;
	int cnt=0;
	while (tmp!=NULL){
		if (tmp->type==CHAR) printf("%c; ",*(char*)tmp->data);
		if (tmp->type==INT) printf("%d; ",*(int*)tmp->data);
		if (tmp->type==DOUBLE) printf("%.2lf; ",*(double*)tmp->data);
		if (tmp->type==STRING) printf("%s; ",(char*)tmp->data);
		cnt++; tmp=tmp->nex[1];
	}
	printf("\n\n");
	return cnt;
}

int main(){
	elem *head1=NewList();
	AddListFirst(&head1,NewElem(CHAR,'c'));
	PrintList(head1);
	AddListFirst(&head1,NewElem(DOUBLE,54.232));
	PrintList(head1);
	AddListLast(&head1,NewElem(STRING,"Hello World!"));
	PrintList(head1);
	AddElem(&head1,2,NewElem(INT,5));
	PrintList(head1);
	DeleteElem(&head1,1);
	PrintList(head1);
	DeleteElem(&head1,2);
	PrintList(head1);
	return 0;
}
