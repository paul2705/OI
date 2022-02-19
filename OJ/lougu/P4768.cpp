#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
const int MAXT=MAXN*8;
const int MAXM=4e5+5;
struct tnode{
	int l,r,cl,cr,fa,dat;
} t[MAXT];
int n,m,M,rt[2*MAXM];
int newnode(int l,int r,int cl,int cr,int fa,int dat){
	t[++M]=(tnode){l,r,cl,cr,fa,dat};
	return M;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,l,dist[l]);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,0,0);
}
void modify(int a,int b,int id,int op,int val){
		
}
