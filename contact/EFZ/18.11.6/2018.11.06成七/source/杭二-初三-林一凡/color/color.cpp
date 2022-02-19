#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],s[100005];
bool used[100005];
vector <int> v[100005];
queue <int> q;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) x=(x+(x<<2)<<1)+(ch^48);
	return x*f;
}
void dfs(int x)
{
	used[x]=1;
	for (int i=v[x].size()-1;i>=0;i--)
	{
		int y=v[x][i];
		if (!used[y]&&a[x]==a[y]) dfs(y);
	}
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
		if (!used[i]) dfs(i),s[a[i]]++;
	for (int i=1;i<=m;i++)
		if (s[i]==1) q.push(i);
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
