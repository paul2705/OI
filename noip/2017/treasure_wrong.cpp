//WRONG 计重
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
typedef long long ll;
const int MAXN=15;
const int MAXS=1<<13;
ll mp[MAXN][MAXN];
ll g[MAXN][MAXS];
ll dis[MAXS][MAXS];
ll n,m,ans=1e9;
ll cnt[MAXN][MAXS],f[MAXN][MAXS];
bitset<13> bis1,bis2;
int main(){
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) mp[i][j]=1e9;
	}
	for (int i=1;i<=n;i++){
		for (int s=0;s<(1<<n);s++) g[i][s]=1e9;
	}
	for (int i=1;i<=m;i++){
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		mp[u][v]=min(mp[u][v],w);
		mp[v][u]=min(mp[v][u],w);
	}
	for (int i=1;i<=n;i++){
		for (int s=0;s<(1<<n);s++){
			for (int j=0;j<n;j++){
				if (s&(1<<j)){
					g[i][s]=min(g[i][s],mp[i][j+1]);
				}
			}
		}
	}
	for (int s=0;s<(1<<n);s++){
		for (int t=0;t<(1<<n);t++){
			for (int i=0;i<n;i++){
				if (s&(1<<i)){
					if (g[i+1][t]==1e9) dis[s][t]=1e9;
					if (dis[s][t]>=1e9) break;
					dis[s][t]+=g[i+1][t];
				}
			}
			bis1=s,bis2=t;
			cout<<bis1<<" "<<bis2<<" "<<dis[s][t]<<endl;
		}
	}
	for (int l=1;l<=n;l++){
		for (int j=1;j<=n;j++){
			for (int s=0;s<(1<<n);s++) cnt[j][s]=s,f[j][s]=1e9;
		}
		f[1][1<<(l-1)]=0; cnt[1][1<<(l-1)]=1<<(l-1);
		for (int i=2;i<=n;i++){
			for (int s=0;s<(1<<n);s++){
				for (int s1=s;s1;s1=(s1-1)&s){
					if (f[i-1][s^s1]>=1e9||dis[s1][s^s1]>=1e9) continue;
					if ((s1&cnt[i-1][s^s1])!=0) continue;
					if (f[i][s1]>f[i-1][s^s1]+dis[s1][s^s1]*(i-1)){
						bis1=s1,bis2=s^s1;
						if (i==3)cout<<i<<" "<<bis1<<" "<<bis2<<" "<<f[i][s1]<<" "<<f[i-1][s^s1]<<" "<<dis[s1][s^s1]<<" "<<i-1<<endl;
						f[i][s1]=f[i-1][s^s1]+dis[s1][s^s1]*(i-1);
						cnt[i][s1]|=cnt[i-1][s^s1];
					}
					bis1=s1; bis2=s^s1;
					cout<<bis1<<" "<<bis2<<" "<<i<<" "<<f[i][s1]<<endl;
					if (cnt[i][s1]==(1<<n)-1) ans=min(ans,f[i][s1]);
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
