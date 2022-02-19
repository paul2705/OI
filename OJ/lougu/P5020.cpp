#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
const int MAXS=5e4+5;
int T,n,a[MAXN];
int f[MAXS],ans;
int main(){
	scanf("%d",&T);
	while (T--){
		int mx=0; ans=0;
		scanf("%d",&n);
		for (int i=0;i<MAXS;i++) f[i]=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
		sort(a+1,a+n+1);
		f[0]=1;
		for (int i=1;i<=n;i++){
			if (!f[a[i]]) ans++;
			for (int j=0;j<=mx;j++) f[j+a[i]]|=f[j];
		}
		printf("%d\n",ans);
	}
	return 0;
}
