#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int ch[3][MAXN],c[MAXN];
int a[MAXN],n,f[MAXN],ans;
int cnt;
void dfs(int u){
	if (!ch[0][u]) dfs(ch[0][u]);
	a[++cnt]=c[u];
	if (!ch[1][u]) dfs(ch[1][u]);
}
int main(){
	memset(f,63,sizeof(f));
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=2,x,id;i<=n;i++){
		scanf("%d%d",&x,&id);
		ch[id][x]=i;
	}
	dfs(1);
	for (int i=1;i<=cnt;i++) a[i]-=i;
	f[1]=a[1]; ans=1;
	for (int i=2;i<=cnt;i++){
		if (a[i]>=f[ans]) f[++ans]=a[i];
		else{
			int l=1,r=ans;
			while (l<=r){
				int mid=(l+r)>>1;
				if (f[mid]<=a[i]) l=mid+1;
				else r=mid-1;
			}
			f[l]=a[i];
		}
	}
	printf("%d\n",n-ans);
	return 0;
}
