#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll f[20][2550][50];
ll n,a,b,ub[20],id[2550];
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
ll lcm(ll a,ll b){
	if (a==0) return b;
	if (b==0) return a;
	return a*b/gcd(a,b);
}
void ini(){
	int tmp=0;
	for (int i=1;i<=2520;i++){ if (2520%i==0) id[i]=++tmp; }
//	cout<<tmp<<endl;
}
ll dp(ll n,ll r,ll c,bool flag){
	if (!n) return r%c==0;
	if (!flag&&f[n][r][id[c]]!=-1) return f[n][r][id[c]];
	ll ret=0,u=flag?ub[n]:9;
	for (int i=0;i<=u;i++){
		ret+=dp(n-1,(10*r+i)%2520,lcm(c,i),flag&&i==u);
	}
	if (!flag) f[n][r][id[c]]=ret;
	return ret;
}
ll solve(ll x){
	memset(ub,0,sizeof(ub));
	n=0;
	while (x>0) ub[++n]=x%10,x/=10;
	return dp(n,0,1,true);
}	
int main(){
	memset(f,-1,sizeof(f));
	int T=1;
	while (T--){
	ini();
	scanf("%lld%lld",&a,&b);
//	cout<<solve(a-1)<<" "<<solve(a-1)<<endl;
	cout<<solve(b)-solve(a-1)<<endl;
	}
	return 0;
}
