#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll a[505][505],tree[10005],TREE[10005];
const int N=10001;
inline ll lowbit(ll x){
	return x&(-x);
}
inline void ADD(ll x,ll y){
	if(x>N) return ;
	TREE[x]+=y;
	ADD(x+lowbit(x),y);
}
inline ll ASK(ll x){
	if(!x) return x;
	return TREE[x]+ASK(x-lowbit(x));
}
inline void add(ll x,ll y){
	if(x>N) return ;
	tree[x]+=y;
	add(x+lowbit(x),y);
}
inline ll ask(ll x){
	if(!x) return x;
	return tree[x]+ask(x-lowbit(x));
}
int main(){
	ll n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){ 
			scanf("%lld",&a[i][j]);
			++a[i][j];
		}
	}
	ll ans=0,sum=0,now=0,cnt=0;
	for(int l=1;l<=n-k+1;l++){
		memset(tree,0,sizeof tree);
		memset(TREE,0,sizeof TREE);
		sum=now=cnt=0;
		for(int i=l;i<=k+l-1;i++){
			for(int j=1;j<=k;j++){
				now-=ask(a[i][j])*2;
				now+=sum;
				now+=ASK(a[i][j])*a[i][j]*2;
				now-=cnt*a[i][j];
				add(a[i][j],a[i][j]);
				ADD(a[i][j],1);
				++cnt;
				sum+=a[i][j];
			}
		}
		ans+=now;
		for(int j=2;j<=n-k+1;j++){
			for(int i=l;i<=k+l-1;i++){
				now+=ask(a[i][j-1])*2;
				now-=sum;
				now-=ASK(a[i][j-1])*a[i][j-1]*2;
				now+=cnt*a[i][j-1];
				add(a[i][j-1],-a[i][j-1]);
				ADD(a[i][j-1],-1);
				--cnt;
				sum-=a[i][j-1];
			}
			for(int i=l;i<=k+l-1;i++){
				now-=ask(a[i][j+k-1])*2;
				now+=sum;
				now+=ASK(a[i][j+k-1])*a[i][j+k-1]*2;
				now-=cnt*a[i][j+k-1];
				add(a[i][j+k-1],a[i][j+k-1]);
				ADD(a[i][j+k-1],1);
				++cnt;
				sum+=a[i][j+k-1];
			}
			//cout << sum << " " << now << " " << cnt << endl << endl;
			ans+=now;
		}
	}
	cout << ans*2%10007<<endl;
	return 0;
}
