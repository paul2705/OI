#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define rep2(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long ll;
const int maxn=1e2+5,mod=1e9+7;
int n,m,k,ans;
int binom[maxn][maxn],a[18][maxn],v[maxn],vv[1<<18];
int main(){
	cin>>n>>m>>k;
	rep(i,0,n)rep(j,0,i)binom[i][j]=!j?1:(binom[i-1][j-1]+binom[i-1][j])%mod;
	rep2(i,0,m){
		int c;cin>>c;
		rep(j,1,c){
			int x;cin>>x;
			a[i][x]=1;
		}
	}
	rep2(s,1,1<<m){
		int flag=mod-1;
		rep(i,1,n)v[i]=0;
		int cnt=0;
		rep2(i,0,m)if(s>>i&1){
			flag=mod-flag;
			rep(j,1,n)if(a[i][j])v[j]|=1<<cnt;
			cnt++;
		}
		sort(v+1,v+n+1);
		rep(i,1,n)vv[v[i]]++;
		rep(i,1,n)if((i==1)||(v[i]!=v[i-1])){
			int v1=v[i],v2=((1<<cnt)-1)^v1;
			ans=(ans+1ll*flag*binom[vv[v1]][k]%mod*binom[vv[v2]][k]%mod)%mod;
		}
		rep(i,1,n)vv[v[i]]--;
	}
	cout<<ans<<endl;
	return 0;
}
