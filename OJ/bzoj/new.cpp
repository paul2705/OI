#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1e5+5;
struct Tnode{
	int l,r,lc,rc,cnt;
	bool tur,cle,altu;
} t[MAXN*20];
int M,a,b;
int newnode(int l,int r,int lc,int rc){ t[++M]=(Tnode){l,r,lc,rc,0,0,0,0}; return M; }
void make_T(int l,int r){     // [ , )
	
void work(int op,int l,int r){
	r++;
	switch (op){
		case 0: cle(l,r); return;
		case 1: altu(l,r); return;
		case 2: tur(l,r); return;
		case 3: query(l,r); return;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	make_T(0,n);
	for (int i=0,op,l,r;i<m;i++){
		scanf("%d%d%d",&op,&l,&r);
		work(op,l,r);
	}
	return 0;
}

