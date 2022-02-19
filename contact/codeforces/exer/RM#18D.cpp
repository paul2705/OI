#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
const int MAXM=4e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,a[MAXN],d[MAXN],c[MAXN],fa[MAXN],res[MAXN];
bool f=1;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	d[u]=d[p]+1; fa[u]=p;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),c[i]=d[a[i]];
	for (int i=1;i<n;i++){
		if (c[i]>c[i+1]) f=0;
	}
//	int l=1,i=1;
//	while (i<=n){
//		for (;c[i]<=c[l]&&i<=n;i++);
//		cout<<i<<" "<<l<<endl;
//		for (;c[i]==c[l]+1&&i<=n;i++){
//			cout<<i<<endl;
//			if (fa[a[i]]!=a[l]){
//				if (fa[a[i+1]]==a[l]) f=0,i=n+1;
//				else l++;
//			}
//		}
//		if (c[i]==c[l]+2) l++;
//	}
	for (int i=1;i<=n;i++){
//		cout<<i<<endl;
		int j=i,cnt=0,l=i-1,r=i-1;
		for (;j<=n&&c[i]==c[j];j++);
		for (;l>=1&&c[l]==c[i-1];l--);
		j--; l++;
//		cout<<l<<" "<<r<<" "<<i<<" "<<j<<endl;
		for (int k=i;k<j-1;k++){
			if (fa[a[i]]!=fa[a[i+1]]&&
			fa[a[i+1]]!=fa[a[i+2]]&&
			fa[a[i]]==fa[a[i+2]]) f=0;
			if (fa[a[i]]!=res[cnt]) res[++cnt]=fa[a[i]];
		}
		for (int k=1;k<=cnt;k++){
			if (res[k]!=a[l++]) f=0;
		}
		i=j;
	}
	if (f) printf("Yes\n");
	else printf("No\n");
	return 0;
	cout<<"";
}
