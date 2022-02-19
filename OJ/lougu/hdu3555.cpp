#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=25;
typedef long long ll;
ll d[MAXN],f[MAXN][2];
ll dp(int l,bool num,bool jud){
	if (l==0) return 1;
	if (!jud&&f[l][num]!=-1) return f[l][num];
	ll ans=0;
	int nex=jud?d[l]:9;
	for (int i=0;i<=nex;i++){
		if (num&&i==9) continue;
		ans+=dp(l-1,i==4,jud&&i==nex);
	}
	if (!jud) f[l][num]=ans;
	return ans;
}
ll solve(ll x){
	int pos=0;
	while (x) d[++pos]=x%10,x/=10;
	return dp(pos,false,true);
}
int main(){
	int T; ll n;
	memset(f,-1,sizeof(f));
	scanf("%d",&T);
	while (T--){
		cin>>n;
		cout<<n-solve(n)+1<<endl;
	}
	return 0;
}
