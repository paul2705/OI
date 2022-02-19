#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
typedef long long ll;
ll f[MAXN],n,t;
void get(ll x){
	ll p=lower_bound(f+1,f+93,x)-f,q=p-1,tot=0;
	while (x){
		x=min(f[p]-x,x-f[q]);
		p=lower_bound(f+1,f+93,x)-f;
		q=p-1;
		tot++;
	}
	printf("%lld\n",tot);
}
int main(){
	scanf("%lld",&n);
	f[1]=f[2]=1;
	for (int i=3;i<=100;i++) f[i]=f[i-1]+f[i-2];
	while (n--){
		scanf("%lld",&t);
		get(t);
	}
	return 0;
}
