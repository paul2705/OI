#include <bits/stdc++.h>

using namespace std;

long long n,m,p;
long long a[1005][1005];
long long rl[1005],cl[1005];
long long ch[2][1005];

long long go(long long x)//begin 0
{
	if(x==n*m)
		return 1;
	long long ret;
	map<long long,long long> st;
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<m;j++)
		{
			if(a[i][j]==0||a[i][j]==-1)
				continue;
			if(st.count(rl[i]*1000+cl[j]))
			{
				ret+=st[rl[i]*1000+cl[j]];
				continue;
			}
			
			memset(ch,0,sizeof(ch));
			long long cntr=0,cntc=0;
			a[i][j]=-1;
			for(long long k=0;k<m;k++)
				if(a[i][k]==0)
				{
					a[i][k]=1;
					ch[0][cntr++]=k;
				}
			for(long long k=0;k<n;k++)
				if(a[j][k]==0)
				{
					a[k][j]=1;
					ch[1][cntc++]=k;
				}
			rl[i]-=cntr;
			cl[i]-=cntc;
			long long tmp=go(x+1)%p;
			rl[i]+=cntr;
			cl[i]+=cntc;
			st[rl[i]*1000+cl[j]]=tmp;
			ret+=tmp;
			for(long long k=0;k<cntr;k++)
				a[i][k]=0;
			for(long long k=0;k<cntc;k++)
				a[k][j]=0;
			a[i][j]=1;
		}
	}
	return ret;
}

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&p);
	for(long long i=0;i<n;i++)
	{
		rl[i]=m;
		cl[i]=n;
	}
	
	for(long long k=0;k<m;k++)
		a[0][k]=1;
	for(long long k=0;k<n;k++)
		a[k][0]=1;
	a[0][0]=-1;
	printf("%d",((n*m)%p*go(1))%p);
	
	
	
	return 0;
}