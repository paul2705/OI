#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a>b?a:b)
const int MAXN=(int)1e5+5;
typedef struct _Node{
	int val,l,r;
	struct _Node *cl,*cr;
} Node;
int a[10005],n;
Node *newnode(int val,int l,int r,Node *cl,Node *cr){
	Node *tmp=malloc(sizeof(Node));
	tmp->val=val; tmp->l=l; tmp->r=r;
	tmp->cl=cl; tmp->cr=cr;
	return tmp;
}
Node* build(int l,int r){
	int mid=(l+r)>>1;
	if (l==r) return newnode(a[l],l,r,NULL,NULL);
	Node *cl=build(l,mid),*cr=build(mid+1,r);
	return newnode(max(cl->val,cr->val),l,r,cl,cr);
}
void prt(Node *now){
	if (now==NULL) return;
	printf("l:%d r:%d mx:%d\n",now->l,now->r,now->val);
	prt(now->cl); prt(now->cr);
}
void del(Node *now){
	if (now==NULL) return;
	del(now->cl); del(now->cr);
	free(now);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	Node *rt=build(1,n);
	prt(rt);
	del(rt);
	return 0;
}
