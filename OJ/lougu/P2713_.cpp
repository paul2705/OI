#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int a[MAXN],ch[MAXN][3],dis[MAXN],root[MAXN],f[MAXN];
int n,m;
bool use[MAXN];
int find(int x){ return f[x]?f[x]=find(f[x]):x; }
int merge(int x,int y){
	if (x==0||y==0) return x+y;
	if (a[x]>a[y]) swap(x,y);
	ch[x][1]=merge(ch[x][1],y);
	if (dis[ch[x][0]]<dis[ch[x][1]]) swap(ch[x][0],ch[x][1]);
	dis[x]=dis[ch[x][1]]+1;
	return x;
}
int del(int x){ return merge(ch[x][0],ch[x][1]); }
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),root[i]=i;
	scanf("%d",&m);
	for (int i=1,x,y;i<=m;i++){
		char op=getchar(); while (op!='M'&&op!='K') op=getchar();
		if (op=='M'){
			scanf("%d%d",&x,&y);
			if (use[x]||use[y]) continue;
			int fx=find(x),fy=find(y);
			if (fx==fy) continue;
			f[fx]=fy; root[fy]=merge(root[fx],root[fy]);
		}
		else{
			scanf("%d",&x);
			if (use[x]) printf("0\n");
			else {
				int fx=find(x);
				printf("%d\n",a[root[fx]]);
				use[root[fx]]=1; root[fx]=del(root[fx]);
			}
		}
	}
	return 0;
}
