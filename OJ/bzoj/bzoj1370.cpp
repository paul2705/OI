#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e3+5;
int n,m,fa[MAXN];
int a[MAXN];
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*2;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		char c=getchar(); while (c!='E'&&c!='F') c=getchar();
		int x,y; scanf("%d%d",&x,&y);
		if (c=='E') uion(x,y+n),uion(x+n,y);
		else uion(x,y);
	}
	for (int i=1;i<=n;i++) a[i]=find(i);
	sort(a+1,a+n+1);
	int ans=0;
	for (int i=1;i<=n;i++){
		if (a[i-1]!=a[i]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
