#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=3e6+6;
int fa[MAXN],cnt[MAXN];
int n,m;
ll ans;
int find(int x){
	return (fa[x]==x||cnt[x])?x:fa[x]=find(fa[x]); 
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int p; scanf("%d",&p);
		fa[i]=p;
	}
	for (int i=1;i<=m;i++){
		int x; scanf("%d",&x);
		cnt[x]++;
	}
	for (int i=n-1;i>=0;i--){
		int fp=find(i);
		if (cnt[fp]!=0){
			cnt[fp]--;
//			cout<<i<<" "<<fp<<endl;
			ans+=i;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
