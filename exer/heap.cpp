#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int t[MAXN];
int n,M;
void push(int x){
	t[++M]=x; int u=M;
	while (u!=1){
		int f=u/2;
		if (t[f]<=x) break;
		else swap(t[u],t[f]);
		u>>=1;
	}
}
int top(){ return t[1]; }
void pop(){
//	cout<<__func__<<t[1]<<" "<<t[M]<<" "<<M<<endl;
	swap(t[1],t[M]); M--;
	int u=1;
	while (u*2<=M){
		int nxt=u<<1;
		if (nxt+1<=M&&t[nxt+1]<=t[nxt]) nxt++;
		if (t[nxt]<t[u]) swap(t[nxt],t[u]);
		else break;
		u=nxt;
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int op; scanf("%d",&op);
		if (op==1){
			int x; scanf("%d",&x);
			push(x);
		}
		else if (op==2) printf("%d\n",top());
		else pop();
	}
	return 0;
}
