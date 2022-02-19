#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e2+5;
const int MAXK=1e4+5;
typedef long long ll;
const ll inf=1e9;
ll f[MAXN][MAXK];
ll n,m,e,v[MAXK];
ll q[MAXK],l,r;
int main(){
	scanf("%lld%lld%lld",&n,&m,&e);
	memset(f,63,sizeof(f));
	f[0][0]=f[1][0]=0;
	ll las=0,b=0;
	for (ll i=1,x,c,w;i<=n;i++){
		scanf("%lld%lld%lld",&x,&c,&w);
		b=min(m,b+c); l=1,r=0;
		for (ll j=0;j<=b;j++){
			ll res=f[i-1][j]-j*w+j*j*(x-las);
			while (l<=r&&v[r]>=res) r--;
			q[++r]=j; v[r]=res;
			while (l<=r&&q[l]<j-c) l++;
			f[i][j]=v[l]+j*w;
		}
//		cout<<f[i][m]<<" ";
		las=x;
	}
//	cout<<endl;
	printf("%lld\n",f[n][m]+(e-las)*m*m);
	return 0;
}
