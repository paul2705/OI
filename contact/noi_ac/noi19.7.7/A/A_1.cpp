#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
const int MAXM=3e6+6;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int n,m,a[MAXN],b[MAXN];
ll ans1,ans2,se,sv;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i]; sv+=a[i];
	}
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w); se+=w;
	}
	if (sv-se==0) return printf("NIE\n"),0;
	ans1=sv-se;
	for (int i=1;i<=n;i++){
		int mn=1e6+5;
		for (int e=head[i];e;e=nex[e]){
			int v=tail[e];
			if (w[e]<mn) mn=w[e];
		}
		ans2+=a[i]-mn;
		cout<<i<<" "<<a[i]-mn<<endl;
		for (int e=head[i];e;e=nex[e]){
			w[e]-=mn; w[e^1]-=mn;
		}
	}
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}
