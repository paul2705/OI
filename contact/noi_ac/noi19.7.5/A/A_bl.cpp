#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
ll f[MAXN],a[MAXN],x[MAXN],y[MAXN];
int n;
ll calc(int l,int r){
	return abs(a[r]-x[l])*abs(a[r]-x[l])*abs(a[r]-x[l])+y[l]*y[l]*y[l];
}
void solve1(){
	for (int i=0;i<=n;i++) f[i]=1e18;
	f[0]=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<i;j++){
			f[i]=min(f[i],f[j]+calc(j+1,i));
		}
	}
	printf("%lld\n",f[n]);
}
void solve2(){
	
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&x[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&y[i]);
	if (n<=1000) solve1();
	else solve2();
	return 0;
}
