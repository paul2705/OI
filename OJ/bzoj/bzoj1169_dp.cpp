#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
//#include<bitset>
using namespace std;
typedef long long ll;
const int MAXN=20;
const ll inf=18*18*1e8+5;
ll f[MAXN][MAXN];
int n,m,R,S;
ll a[MAXN][MAXN];
int lis[MAXN],cnt;
int st[(1<<18)+5],tot;
ll ans=inf;
//bitset<10> t1;
ll calc(int x1,int y1,int x2,int y2){
	return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
}
int main(){
	scanf("%d%d%d%d",&n,&m,&R,&S);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%lld",&a[i][j]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	}
	for (int s=0;s<(1<<n);s++){
		int tmp=0;
		for (int i=0;i<n;i++){
			if (s&(1<<i)) tmp++;
		}
		if (tmp==R) st[++tot]=s;
	}
	for (int _=1;_<=tot;_++){
		int s=st[_],tmp=0;lis[tmp++]=0;
//		t1=s; cout<<t1<<endl;
		for (int i=0;i<n;i++){
			if (s&(1<<i)) lis[tmp++]=i+1;
		}
		lis[tmp++]=n;
		for (int i=0;i<=m;i++){
			for (int j=0;j<=S;j++) f[i][j]=inf;
		}
		f[0][0]=0;
		for (int i=1;i<=m;i++){
			ll t=0;
			for (int j=1;j<tmp;j++){
				t=max(t,calc(lis[j-1]+1,1,lis[j],i));
			}
			f[i][0]=t;
			for (int j=1;j<=S;j++){
				for (int k=0;k<i;k++){
					ll t=0;
					for (int x=1;x<tmp;x++){
						t=max(t,calc(lis[x-1]+1,k+1,lis[x],i));
					}
					f[i][j]=min(f[i][j],max(f[k][j-1],t));
				}
//				cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
			}
		}
		ans=min(ans,f[m][S]);
//		cout<<ans<<" "<<f[m][S]<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}
