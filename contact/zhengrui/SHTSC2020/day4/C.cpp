#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
#include<map>
#include<bitset>
#include<set>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;
inline LL read()
{
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
template<typename T>inline void write(T x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
template<typename T>inline void pr1(T x){write(x);putchar(' ');}
template<typename T>inline void pr2(T x){write(x);putchar('\n');}
const int MAXN=40005;
const int MAXM=10;
const int MAXMASK=(1<<9);
int f[2][MAXM][MAXMASK],n,K;
int trans[MAXMASK][MAXN],nx[MAXM][MAXN];
int bin[25];char ch[15];
int lowbit(int x){return x&-x;}
void clear(int o){for(int i=0;i<=K;i++)for(int j=0;j<bin[K+1];j++)f[o][i][j]=n+1;}
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	bin[1]=1;for(int i=2;i<=20;i++)bin[i]=bin[i-1]<<1;
	n=read();K=read();
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=K;j++)
		{
			scanf("%s",ch+1);
			for(int k=1;k<=K;k++)nx[j][i]|=bin[k]*(ch[k]-'0');
		}
		for(int j=1;j<bin[K+1];j++)
			trans[j][i]=trans[j-lowbit(j)][i]|nx[__builtin_ctz(j)+1][i];
	}LL ans=0;clear(0);
	for(int j=0;j<bin[K+1];j++)for(int k=__builtin_popcount(j);k<=K;k++)f[0][k][j]=n;
	for(int i=n-1,now=0;i>=1;i--)
	{
		now^=1;
		for(int j=0;j<=K;j++)for(int k=0;k<bin[K+1];k++)
		{
			f[now][j][k]=f[now^1][j][trans[k][i]];
			if(__builtin_popcount(trans[k][i])<=j)f[now][j][k]=i+1;
		}
		for(int j=0;j<K;j++)for(int k=0;k<bin[K+1];k++)
			if(f[now][j][k]!=n+1)
			{
				int msk=(bin[K+1]-1)^k;
				for(int t=msk;t;t-=lowbit(t))
				{
					int u=__builtin_ctz(t)+1;
					f[now][j+1][k|bin[u]]=min(f[now][j+1][k|bin[u]],f[now][j][k]);
				}
			}
		int sum=0;
		for(int j=K;j>=1;j--)sum+=(f[now][j-1][bin[K+1]-1]-f[now][j][bin[K+1]-1])*j;
		ans+=sum;//pr2(sum);
	}pr2(ans);
	return 0;
}
