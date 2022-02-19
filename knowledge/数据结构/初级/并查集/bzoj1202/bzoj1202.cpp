#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
int n,m,fa[MAXN],s[MAXN];
int T;
int find(int x){
	if (fa[x]==x) return x;
	int f=find(fa[x]);
	s[x]+=s[fa[x]];
	fa[x]=f;
	return f;
}
int main(){
	scanf("%d",&T);
	while (T--){
		bool flag=1;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n+1;i++) s[i]=0,fa[i]=i;
		for (int i=1;i<=m;i++){
			int u,v,w; scanf("%d%d%d",&u,&v,&w); u++; v++;
			int fu=find(u-1),fv=find(v);
//			printf("u:(%d,%d)->(%d,%d)\n",u-1,s[u-1],fu,s[fu]);
//			printf("v:(%d,%d)->(%d,%d)\n",v,s[v],fv,s[fv]);
			if (fu!=fv){
				fa[fu]=fv;
				s[fu]=s[v]+w-s[u-1];
			}
			else if (s[u-1]-s[v]!=w) flag=false;
		}
		if (flag) printf("true\n");
		else printf("false\n");
	}
	return 0;
}
