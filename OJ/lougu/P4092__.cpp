#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int fa[MAXN],nfa[MAXN],n,m,t[MAXN];
bool flag[MAXN];
int cnt=1;
int find(int u){
	if (flag[u]) return u;
	if(t[u]==cnt) return nfa[u];
	t[u]=cnt;
	return nfa[u]=find(fa[u]);
}
int main(){
	scanf("%d%d",&n,&m);
	flag[1]=fa[1]=1;
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		fa[v]=u;
	}
	for (int i=1;i<=n;i++) t[i]=nfa[i]=1;
	for (int i=0,u;i<m;i++){
		char op=getchar(); while(op!='C'&&op!='Q') op=getchar();
		scanf("%d",&u);
		if (op=='C') {if (!flag[u]) flag[u]=1,cnt++;}
		else printf("%d\n",find(u));
	}
	return 0;
}
