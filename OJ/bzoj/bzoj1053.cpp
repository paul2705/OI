#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=15;
int a[MAXN];
ll n,ans;
struct rec{
	int dat,id;
};
map<ll,ll> use;
int p[15]={0,2,3,5,7,11,13,17,19,23,29,31,37};
void dfs(int d){
	if (d==13) return;
	ll res=1,nt=1;
	for (int i=1;i<d;i++){
		nt=nt*(a[i]+1);
		for (int j=1;j<=a[i];j++) res*=p[i];
	}
	ll tm=use[nt];
//	if (tm<res&&tm!=0) return;
	if (tm==0||tm>res) use[nt]=res;
	ll rcn=1;
	for (int i=1;i<=a[d-1];i++){
		rcn=rcn*p[d];
		if (res*rcn>n) break;
		a[d]=i;
		dfs(d+1);
	}
}
int main(){
	scanf("%lld",&n);
	a[0]=40;
	dfs(1);
	for (map<ll,ll>::iterator it=use.begin();it!=use.end();it++){
		pair<ll,ll> tmp=(*it);
//		if (tmp.second) cout<<tmp.first<<" "<<tmp.second<<endl;
		ans=tmp.second;
	}
	printf("%lld\n",ans);
	return 0;
}
