#include<isotream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
const int MAXM=MAXN*2;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,m,cnt;
ll a[MAXN];
struct rec{
	int start;
	ll p[65];
	rec(){
		start=0;
		for (int i=0;i<64;i++) p[i]=0;
	}
	void clear(){
		for (int i=0;i<64;i++) p[i]=0;
	}
	ll mx(){
		ll ans=0;
		for (int i=63;i>=0;i--){
			if ((ans^p[i])>ans) ans^=p[i];
		}
		return ans;
	}
} st[65];
struct mp{
	rec a[65];
};
vector<mp> g[MAXN];
int id[MAXN],bel[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
rec ins(rec& a,ll val){
	rec c=a;
	for (int i=63;i>=0;i--){
		if (!(val>>i)&1) continue;
		if (c.p[i]) val^=c.p[i];
		else{
			c.p[i]=val;
			break;
		}
	}
	return c;
}

