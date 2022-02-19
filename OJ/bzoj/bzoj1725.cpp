#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=13;
const int MAXS=1<<MAXN;
const int mod=1e9;
int mp[MAXN];
int n,m,f[MAXN][MAXS];
int st[MAXS],cnt;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int x; scanf("%d",&x);
			mp[i]=mp[i]*2+x;
		}
	}
	for (int s=0;s<(1<<m);s++){
		bool flag=1;
		for (int i=0;i<m-1;i++){
			if ((s&(1<<i))&&(s&(1<<(i+1)))) flag=0;
		}
		if (flag) st[cnt++]=s;
	}
	f[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<cnt;j++){
			int s=st[j];
			if ((s|mp[i])!=mp[i]) continue;
			for (int k=0;k<cnt;k++){
				int s1=st[k];
				if ((s&s1)!=0) continue;
				f[i][s]=(f[i][s]+f[i-1][s1])%mod;
			}
		}
	}
	int ans=0;
	for (int s=0;s<(1<<m);s++) ans=(ans+f[n][s])%mod;
	printf("%d\n",ans);
	return 0;
}
