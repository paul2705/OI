#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=5e5;
ll f[3][MAXN];
int n,k[MAXN];
ll p[MAXN][6],sum;
void solve1(){
//	scanf("%d",&n);
	for (int i=1;i<=5e5;i++) f[0][i]=-1e15;
	for (int i=1;i<=n;i++){
		int cur=i&1; int old=cur^1;
		int x; scanf("%d",&x); sum+=x;
		for (int j=0;j<=sum;j++) f[cur][j]=-1e15;
		for (int j=1;j<=x;j++){
			ll tmp; scanf("%lld",&tmp);
			for (int k=j;k<=sum;k++){
				f[cur][k]=max(f[cur][k],f[old][k-j]+tmp);
			}
		}
	}
	for (int i=n;i<=sum;i++) printf("%lld ",f[n&1][i]);
	printf("\n");
}
struct rec{
	ll x,id,num;
	bool operator < (const rec& b) const{
		return x>b.x;
	}
} lis1[MAXN],lis2[MAXN];
struct rec1{
	ll x,id,num;
	bool operator < (const rec1& b) const{
		return x<b.x;
	}
};
priority_queue<rec1> q;
void solve2(){
	ll ans=0;
	for (int i=1;i<=n;i++){
		lis1[i]=(rec){p[i][1],i,1};
		ans+=p[i][1];
		lis2[i]=(rec){p[i][2]-p[i][1],i,2};
//		cout<<p[i][1]<<" "<<p[i][2]<<" "<<ans<<endl;
	}
	sort(lis2+1,lis2+n+1);
	for (int k=n;k<=sum;k++){
		printf("%lld ",ans);
		int pos=lis2[k-n+1].id;
		ans+=p[pos][2]-p[pos][1];
	}
//	printf("%lld ",ans);
	printf("\n");
}
void solve3(){

}
void solve4(){

}
void solve5(){
	ll ans=0;
	for (int i=1;i<=n;i++){
		ans+=p[i][1];
		q.push((rec1){p[i][2]-p[i][1],i,2});
	}
	printf("%lld ",ans);
	while (!q.empty()){
		rec1 u=q.top(); q.pop();
		int pos=u.id,num=u.num;
		ans+=u.x;
//		cout<<pos<<" "<<num<<" "<<u.x<<endl;
		printf("%lld ",ans);
		if (num+1<=k[pos]) q.push((rec1){p[pos][num+1]-p[pos][num],pos,num+1});
	}
	printf("\n");
}
int main(){
	scanf("%d",&n);
	if (n<=505) solve1();
	else{
		int mx=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&k[i]);
			mx=max(mx,k[i]);sum+=k[i];
			for (int j=1;j<=k[i];j++) scanf("%lld",&p[i][j]);
		}
		if (mx==2) solve2();
		else solve5();
	}
	return 0;
}
