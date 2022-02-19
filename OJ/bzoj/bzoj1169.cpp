#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
//#include<bitset>
using namespace std;
typedef long long ll;
const int MAXN=20;
const ll inf=18*18*1e8+5;
int n,m,R,S;
int st[(1<<18)+5],tot;
ll ans=inf;
ll a[MAXN][MAXN];
int lis[MAXN],cnt;
ll las[MAXN];
//bitset<10> t1;
ll calc(int x1,int y1,int x2,int y2){
	return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
}
bool check(ll mid){
	for (int i=1;i<=cnt;i++) las[i]=0;
	int res=0;
	for (int i=1;i<=m;i++){
		bool flag=0;
		for (int j=1;j<cnt;j++){
			las[j]+=calc(lis[j-1]+1,i,lis[j],i);
			if (las[j]>mid) flag=true;
		}
		if (flag){
			for (int j=1;j<cnt;j++){
				las[j]=calc(lis[j-1]+1,i,lis[j],i);
				if (las[j]>mid) return 0;
			}
			if (i>1) res++;
		}
	}
	return res<=S;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&R,&S);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%lld",&a[i][j]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	}
	for (int s=0;s<(1<<(n-1));s++){
		int tmp=0;
		for (int i=0;i<n-1;i++){
			if (s&(1<<i)) tmp++;
		}
		if (tmp==R) st[++tot]=s;
	}
	for (int _=1;_<=tot;_++){
		int s=st[_]; cnt=0; lis[cnt++]=0;
		for (int i=0;i<n-1;i++){
			if (s&(1<<i)) lis[cnt++]=i+1;
		}
		lis[cnt++]=n;
		ll l=0,r=a[n][m],mid;
		while (l+1<r){
			mid=(l+r)>>1;
			if (check(mid)) r=mid;
			else l=mid;
		}
//		t1=s; cout<<t1<<" "<<r<<endl;
		ans=min(ans,r);
	}
	printf("%lld\n",ans);
	return 0;
}
