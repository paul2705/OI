#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct Pair{ int pos,id; };
const int MAXN=1e6+5;
int n,a[MAXN],p[MAXN],sz;
int mp[MAXN],al,ar,ln,ul,ur,nw,mn;
vector<Pair> k[MAXN];
bool cmp(Pair x,Pair y){
	return x.pos-2*x.id>y.pos-2*y.id;
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<MAXN;++i){
		if (!p[i]) p[++sz]=i,mp[i]=i;
		for(int j=1;j<=sz&&i*p[j]<MAXN;++j){
			p[i*p[j]]=1;
			mp[i*p[j]]=p[j];
			if (i%p[j]==0) break;
		}
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		for (int j=a[i];j!=1;j/=mp[j]){
			if (j/mp[j]%mp[j]){
				k[mp[j]].push_back((Pair){i,k[mp[j]].size()+1});
			}
		}
	}
	for(int i=1;i<=sz;++i){
		if(k[p[i]].size()){
			sort(k[p[i]].begin(),k[p[i]].end(),cmp),mn=1e9,nw=0;
			for(int j=0;j<k[p[i]].size();++j){
				while (nw<k[p[i]].size()&&k[p[i]][nw].pos-2*k[p[i]][nw].id+1>=k[p[i]][j].pos-2*k[p[i]][j].id){
					mn=min(mn,k[p[i]][nw].id),++nw;
				}
				ln=min(n,(k[p[i]][j].id-mn+1)<<1);
				ul=max(k[p[i]][j].pos-ln+1,1),ur=ul+ln-1;
				if (ln>ar-al+1) al=ul,ar=ur;
				else if (ln==ar-al+1&&al>ul) al=ul,ar=ur;
			}
		}
	}
	printf("%d %d",al,ar);
	return 0;
}
