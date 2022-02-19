#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=20;
const int MAXS=1<<16;
ll f[MAXS][MAXN];
int n,m;
int a[MAXN],bin[MAXN];
int un[MAXN],cntu;
int ex[MAXN],cnte;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	bin[0]=1;
	for (int i=0;i<n;i++) f[(1<<i)][i]=1,bin[i+1]=bin[i]*2;
	for (int s=1;s<bin[n];s++){
		cntu=cnte=0;
		for (int i=0;i<n;i++){
			if (s&bin[i]) ex[cnte++]=i;
			else un[cntu++]=i;
		}
		for (int i=0;i<cntu;i++){
			int u=un[i];
			for (int j=0;j<cnte;j++){
				int v=ex[j];
				if (abs(a[v+1]-a[u+1])<=m) continue;
				f[s|bin[u]][u]+=f[s][v];
			}
		}
	}
	ll ans=0;
	for (int i=0;i<n;i++){
//		cout<<i+1<<" "<<f[bin[n]-1][i]<<endl;
		ans+=f[bin[n]-1][i];
	}
	printf("%lld\n",ans);
	return 0;
}
