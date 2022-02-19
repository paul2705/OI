#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#define LL long long
using namespace std;
const int mod=1e9+7;
char s[55],t[55];
int n,m,ans;
unordered_map<LL,int> f[2];
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	f[0][1]=1;
	for(int i=0;i<n+m;i++)
	{
		int u=i&1,v=u^1,st=max(0,i-n),ed=min(i,m);
		f[v].clear();
		for(unordered_map<LL,int>::iterator it=f[u].begin();it!=f[u].end();it++)
		{
			int w=it->second;
			LL msk=it->first,x=0,y=0;
			for(int j=st;j<=ed;j++)
				if(msk>>j&1)
				{
					if(i-j<n)
					{
						if(s[i-j+1]=='0') x|=1ll<<j;
						else y|=1ll<<j;
					}
					if(j<m)
					{
						if(t[j+1]=='0') x|=1ll<<(j+1);
						else y|=1ll<<(j+1);
					}
				}
			if(x) f[v][x]=(f[v][x]+w)%mod;
			if(y) f[v][y]=(f[v][y]+w)%mod;
		}
	}
	int r=(n+m)&1;
	for(unordered_map<LL,int>::iterator it=f[r].begin();it!=f[r].end();it++) ans=(ans+it->second)%mod;
	printf("%d\n",ans);
	return 0;
}
