#include<bits/stdc++.h>
//#define double long double
using namespace std;

const int M = 10001;

map<int,double>mp[M];
map<int,bool> md[M];
struct P
{
	int x,y;
	P(int X,int Y): x(X), y(Y) {}
	P(){}
} a[M];
bitset<10001>bt[M],B;
int n,m,k,b[M],d[M];
double len;
vector<int> v[M];
P polar(double a,double r) 
{ 
	double x=r*cos(a), y=r*sin(a);
	if(x<0) x-=0.5;
	else x+=0.5;
	if(y<0) y-=0.5;
	else y+=0.5;
	return{ (int)x, (int)y }; 
}

double dis(P a,P b)
{
	return ((double)b.x-a.x)*((double)b.x-a.x) + ((double)b.y-a.y)*((double)b.y-a.y);
}

double acr(P a,P b)
{
	return (double)a.x*b.y-(double)a.y*b.x;
}

double angleA(P O1,double r1,P O2,double r2)
{
	return acos((r1*r1+dis(O1,O2)-r2*r2)/(2*r1*sqrt(dis(O1,O2))));  
}
double angleT(P O1,P O2)                      
{
	P O1O2 = P(O2.x-O1.x,O2.y-O1.y);
	return atan2((double)O1O2.y, (double)O1O2.x);  
}

P ask(P O1,double r1,P O2,double r2)
{
	double t=angleT(O1, O2);
	double a=angleA(O1, r1, O2, r2);
	P Polar=polar(t+a,r1);
	P x=P(O1.x+Polar.x,O1.y+Polar.y);
	return x;
}
P sub(P a,P b){return P(a.x-b.x,a.y-b.y);}

void dfs(int x,int y)
{
	int X=0;
	double SZ=1e16;
	int g=x, h=y;
	if(d[g]>d[h]) swap(h,g);
	for(int i=0;i<v[g].size();i++)
	{
		int t=v[g][i];
		if(!bt[t][h]) continue;
		if(b[t] && acr(sub(a[y],a[x]),sub(a[t],a[x]))<0) continue;
		double W=mp[x][t]+mp[y][t];
		if(W<SZ) SZ=W, X=t;
	}
	
	if(!X) return;  if(!b[X]) a[X]=ask(a[x],mp[x][X],a[y],mp[y][X]); b[X]=1;
	if(md[x].find(X)==md[x].end()) 
	{
		md[x][X]=1;
		dfs(x,X);
	}
	if(md[X].find(y)==md[X].end())
	{
		md[X][y]=1;
		dfs(X,y);
	}
	
}
int gi()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9') x=x*10+c-'0', c=getchar();
	return x;
}
int main()
{
	int T;
	T=gi();
	for(;T;T--)
	{
		n=gi(),m=gi();
		memset(b,0,sizeof(b)); memset(d,0,sizeof(d));
		double Len;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			x=gi(),y=gi();
			scanf("%lf",&len);
			bt[x][y]=1; bt[y][x]=1;
			mp[x][y]=len; mp[y][x]=len;
			v[x].push_back(y);
			v[y].push_back(x);
			if(i==1) Len=len;
			d[x]++, d[y]++;
		}
		a[2].x=Len; b[1]=b[2]=1;
		dfs(1,2);		
		for(int i=1;i<=n;i++) 
		{
			printf("%d %d\n",a[i].x,a[i].y);
			bt[i].reset(); mp[i].clear(); md[i].clear(); v[i].clear();
		}puts("");
	}
} 
