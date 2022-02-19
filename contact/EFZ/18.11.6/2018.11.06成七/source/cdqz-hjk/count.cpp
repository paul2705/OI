#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,p;
int tmp[20];
int jc[20];
int dat[5][5];
int maxl[5],maxc[5],ans=0,tmpcnt;
inline int add(int a,int b)
{
	a+=b;
	if(a>=p)a-=p;
	return a;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	jc[0]=1;
	for(int i=0;i<n*m;i++)tmp[i]=i,jc[i+1]=jc[i]*(i+1);
	for(int i=1;i<=jc[n*m];i++)
	{
		for(int j=0;j<n*m;j++)
		{
			dat[(j/m)][j%m]=tmp[j];
		}
		memset(maxl,255,sizeof(maxl));
		memset(maxc,255,sizeof(maxc));
		tmpcnt=0;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				if(maxl[j]==-1||dat[j][k]>dat[j][maxl[j]])maxl[j]=k;
				if(maxc[k]==-1||dat[maxc[k]][k]<dat[j][k])maxc[k]=j;
			}
		}
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				if(maxl[j]==k&&maxc[k]==j)tmpcnt++;
			}
		}
		if(tmpcnt==1)ans=add(ans,1);
		next_permutation(tmp,tmp+n*m);
	}
	printf("%d\n",ans);
	return 0;
}
