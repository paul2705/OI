#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=200100;
vector<int>g[N];
int n,sm[N],sz,m;
long long ans;
void add(int x,int y){for(sz+=y;x<=n;x+=x&-x)sm[x]+=y;}
int qry(int x){int ans=0;for(;x;x-=x&-x)ans+=sm[x];return ans;}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		int x;cin>>x;m=max(m,x);
		g[x].push_back(i);
	}
	for(int i=1;i<=n;++i)sm[i]=i&-i,++sz;
	for(int i=1;i<=m;++i){
		for(int j:g[i])add(j,-1);
		for(int j:g[i]){
			int u=qry(j);
			ans+=min(u,sz-u);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
