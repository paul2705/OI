#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> par;
const ll MAXN=5e4+5;
struct rec{
	int x,y,id,tp;
} a[MAXN],b[MAXN],res[MAXN*2];
ll n,ans,cnt;
multiset<par> s;
multiset<par>::iterator it;
bool cmp(rec a,rec b){ return a.x<b.x; }
int main(){
	scanf("%lld",&n);
	for (int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		ans+=-x+y;
		res[++cnt]=(rec){x,y,i,1};
	}
	for (int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		ans+=x-y;
		res[++cnt]=(rec){x,y,i,2};
	}
	sort(res+1,res+cnt+1,cmp);
	printf("%lld\n",ans);
	for (ll i=1;i<=cnt;i++){
		if (res[i].tp==1) s.insert(make_pair(res[i].y,res[i].id));
		else {
			it=s.lower_bound(make_pair(res[i].y,0));
			printf("%d %d\n",it->second,res[i].id);
			s.erase(it);
		}
	}
	return 0;
}
