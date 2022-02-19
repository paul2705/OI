#include<iostream>
#include<cstdio>
using namespace std;

void rightrot(int x,int y){
	int z=p[y];
	if (z>0) if (l[x]==y) l[z]=x;
		 else r[z]=x;
	if (r[x]>0) r[r[x]]=y;
	l[y]=r[x]; r[x]=y;
	p[x]=z; p[y]=x;
}

void splay(int x,int b){
	while (p[x]!=b){
		int y=p[x]; int z=p[y];
		if (z==0){
			if (l[y]==x) rightrot(x,y);
			else leftrot(x,y);
		}
		else{ 
			if (l[z]==y&&l[y]==x){ rightrot(y,z); rightrot(x,y); }
			else if (r[x]==y&&r[y]==x){ leftrot(y,z); leftrot(x,y); }
			else if (r[x]==y){ roghtrot(x,y); leftrot(x,z); }
			else { leftrot(x,y); rightrot(x,z); }
		}
	}
}

int prev(int x){
	splay(x,0);
	int a=l[x];
	while (r[x]>0) a=r[a];
	return a;
}

void add(int x){
	int a=prev(x);
	if (a==0){
		int root=r[x];
		p[root]=a;
	}
	else {
		splay(a,0);
		if (p[x]!=a){
			l[p[x]]=r[x];
			p[r[x]]=p[x];
		}
	}
}

void del(int x,int y){
	splay(y,0);
	int rx=prev(x);
	splay(rx,y);
	r[rx]=0;
}
void delsingle(int x){
	del(x,next(x));
}

	
