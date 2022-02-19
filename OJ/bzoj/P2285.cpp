#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
int ans=0;
int n,m,t[MAXN],x[MAXN],y[MAXN],f[MAXN];
int dist(int i,int j){ return abs(x[i]-x[j])+abs(y[i]-y[j]); }
int main(){
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++) scanf("%d%d%d",&t[i],&x[i],&y[i]);
	for (int i=1;i<=n;i++){ f[i]=1;
		for (int j=1;j<i;j++){
			if (t[i]-t[j]>=dist(i,j)) f[i]=max(f[i],f[j]+1);
		}
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}
