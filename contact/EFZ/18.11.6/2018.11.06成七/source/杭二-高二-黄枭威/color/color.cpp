#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int l,r,n,m,T,x,y;
int res[110][2],cnt[110],b[110],bo[110],q[110],p[110],c[110][110],len[110];
int k,first[200],last[200],ne[200],a[200];
char ch;
void read(int &digit)
{
	int QAQ;
	digit=0;
	ch=getchar();
	while ((ch<'0'||ch>'9')&&(ch!='-')) ch=getchar();
	if (ch=='-') {QAQ=-1;ch=getchar();}
	else QAQ=1;
	while(ch>='0'&&ch<='9')
	{
		digit=digit*10+ch-'0';
		ch=getchar();
	}
	digit=digit*QAQ;
}
void write(int x)
{
	if (len[x]==1) printf("%d %d %d\n",x,res[x][0],res[x][0]);
	else printf("%d %d %d\n",x,res[x][0],res[x][1]);
}
int dfs(int x,int fa)
{
	if (x==T) return(1);
	int flag=0;
	for (int i=first[x];i;i=ne[i])
	if (a[i]!=fa)
	{
		if (dfs(a[i],x)==1)
		{
			if (p[a[i]]!=p[T]) c[p[T]][p[a[i]]]=1;
			else if (a[i]!=T) bo[a[i]]=1;
			flag=1;
		}
	}
	return(flag);
}
void add(int x,int y)
{
	k++;
	a[k]=y;
	if (first[x]==0) first[x]=k;
	else ne[last[x]]=k;
	last[x]=k;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	read(n);read(m);
	for (int i=1;i<=n;i++) read(p[i]);
	for (int i=1;i<n;i++)
	{
		read(x);read(y);
		add(x,y);add(y,x);
	}
	memset(bo,0,sizeof(bo));
	memset(c,0,sizeof(c));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if (i!=j&&p[i]==p[j])
		{
			T=j;
			dfs(i,0);
		}
	memset(b,0,sizeof(b));
	for (int i=1;i<=n;i++) b[p[i]]=1;
	for (int i=1;i<=m;i++)
	if (b[i]==0) printf("%d 1 1\n",i);
	memset(cnt,0,sizeof(cnt));
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++) cnt[j]+=c[i][j];

	for (int i=1;i<=m;i++)
	if (b[i]==1)
	{
		len[i]=0;
		for (int j=1;j<=n;j++)
		if (p[j]==i&&bo[j]==0) {res[i][len[i]]=j;len[i]++;}
	}
	l=1;r=0;
	for (int i=1;i<=m;i++)
	if (cnt[i]==0)
	{
		write(i);
		r++;
		q[r]=i;
	}
	while(l<=r)
	{
		x=q[l];
		l++;
		for (int i=1;i<=m;i++)
		if (c[x][i]==1)
		{
			cnt[i]--;
			if (cnt[i]==0)
			{
				write(i);
				r++;
				q[r]=i;
			}
		}
	}
	return 0;
}
