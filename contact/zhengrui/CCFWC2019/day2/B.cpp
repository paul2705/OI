#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iomanip>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<list>
#include<deque>
#include<bitset>
#include<fstream>
#define ld double
#define ull unsigned long long
#define ll long long
#define pii pair<int,int >
#define iiii pair<int,pii >
#define mp make_pair
#define INF 1000000000
#define MOD 1000000007
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
    int x=0,p=1;char c=getchar();
    while (c<=32)c=getchar();
    if(c==45)p=-p,c=getchar();
    while (c>32)x=x*10+c-48,c=getchar();
    return x*p;
}
using namespace std;
//ruogu
const int N=2e5+10;
int n,k[N],id[N];
ll b[N];
multiset<int>S[N];
vector<pii >G[N];
//
void dfs(int x,int p,int d){
	k[x]=-1;
	b[x]=1ll*d;
	rep(i,2)S[id[x]].insert(d);
	rep(i,G[x].size()){
		int to=G[x][i].second;
		if(to==p)continue;
		dfs(to,x,G[x][i].first);
		if(S[id[x]].size()<S[id[to]].size())swap(id[x],id[to]);
		k[x]+=k[to];b[x]+=b[to];
		for(multiset<int>::iterator it=S[id[to]].begin();it!=S[id[to]].end();it++){
			S[id[x]].insert(*it);
		}
	}
	while(k[x]<0){
		int y=*S[id[x]].begin();
		b[x]-=1ll*y;
		k[x]++;
		S[id[x]].erase(S[id[x]].begin());
	}
}
void solve(){
	n=getint();
	rep(i,n){
		G[i].clear();
		S[i].clear();
		id[i]=i;
	}
	rep(i,n-1){
		int x=getint()-1,y=getint()-1,z=getint();
		G[x].push_back(mp(z,y));
		G[y].push_back(mp(z,x));
	}	
	dfs(0,-1,0);
	printf("%lld\n",b[0]);
}
int main(){
	int t=getint();
	rep(ttt,t){
		solve();
	}
	return 0;
}
