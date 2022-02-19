#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
vector<int>Va[1000005],Vb[1000005];
int na,nb,ma,mb,ng,mg;
long long ans;
char st[1000005];
int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}
int count(int xa,int xb,int ya,int yb,int num)
{
//	cout<<xa<<" "<<xb<<" "<<ya<<" "<<yb<<" "<<num<<endl;
	if (num==1) return Vb[xb][yb]-Vb[xa-1][yb]-Vb[xb][ya-1]+Vb[xa-1][ya-1];
	else return (xb-xa+1)*(yb-ya+1)-(Vb[xb][yb]-Vb[xa-1][yb]-Vb[xb][ya-1]+Vb[xa-1][ya-1]);
}
void calc(long long xa,long long xb,long long ya,long long yb,int num)
{
//	cout<<xa<<" "<<xb<<" "<<ya<<" "<<yb<<" "<<num<<endl;
	
	long long x=na/ng,y=ma/mg;
	long long a=((xa==1)?1:((xa-2)/x+2)),b=xb/x,c=((ya==1)?1:((ya-2)/y+2)),d=yb/y;
//	long long ans=0;
//	cout<<"       "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	if (a-b==2 && c-d==2)
	{
		ans+=(long long)count(a-1,a-1,c-1,c-1,num)*(xb-xa+1)*(yb-ya+1);
		return;
	}
	if (a-b==2)
	{
		if (c<=d) ans+=(long long)count(a-1,a-1,c,d,num)*(xb-xa+1)*y;
		if (c-1>=1) ans+=(long long)count(a-1,a-1,c-1,c-1,num)*(xb-xa+1)*(((c-1)*y)+1-ya);
		if (d+1<=mb) ans+=(long long)count(a-1,a-1,d+1,d+1,num)*(xb-xa+1)*(yb-(d*y));
		return;
	}
	if (c-d==2)
	{
		if (a<=b) ans+=(long long)count(a,b,c-1,c-1,num)*(yb-ya+1)*x;
		if (a-1>=1) ans+=(long long)count(a-1,a-1,c-1,c-1,num)*(yb-ya+1)*(((a-1)*x)+1-xa);
		if (b+1<=nb) ans+=(long long)count(b+1,b+1,c-1,c-1,num)*(yb-ya+1)*(xb-(b*x));
		return;
	}

	if (a<=b && c<=d) ans+=(long long)count(a,b,c,d,num)*x*y;

	if (a-1>=1 && c<=d) ans+=(long long)count(a-1,a-1,c,d,num)*(((a-1)*x)+1-xa)*y;
	if (b+1<=nb && c<=d) ans+=(long long)count(b+1,b+1,c,d,num)*(xb-(b*x))*y;

	if (c-1>=1 && a<=b) ans+=(long long)count(a,b,c-1,c-1,num)*(((c-1)*y)+1-ya)*x;
	if (d+1<=mb && a<=b) ans+=(long long)count(a,b,d+1,d+1,num)*(yb-(d*y))*x;

	if (a-1>=1 && c-1>=1) ans+=(long long)count(a-1,a-1,c-1,c-1,num)*(((a-1)*x)+1-xa)*(((c-1)*y)+1-ya);
	if (a-1>=1 && d+1<=mb) ans+=(long long)count(a-1,a-1,d+1,d+1,num)*(((a-1)*x)+1-xa)*(yb-(d*y));
	if (b+1<=nb && c-1>=1) ans+=(long long)count(b+1,b+1,c-1,c-1,num)*(xb-(b*x))*(((c-1)*y)+1-ya);
	if (b+1<=nb && d+1<=mb) ans+=(long long)count(b+1,b+1,d+1,d+1,num)*(xb-(b*x))*(yb-(d*y));

//	cout<<ans<<endl;

};
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d%s",&na,&ma,st+1);
	for (int i=0;i<=na+1;i++)
		for (int j=0;j<=ma+1;j++)
			Va[i].push_back(0);
	for (int i=1;i<=na;i++)
		for (int j=1;j<=ma;j++)
			Va[i][j]=st[(i-1)*ma+j]-48;
	scanf("%d%d%s",&nb,&mb,st+1);
	for (int i=0;i<=nb+1;i++)
		for (int j=0;j<=mb+1;j++)
			Vb[i].push_back(0);
	for (int i=1;i<=nb;i++)
		for (int j=1;j<=mb;j++)
			Vb[i][j]=st[(i-1)*mb+j]-48;
	ng=gcd(na,nb),mg=gcd(ma,mb);
	for (int i=1;i<=nb;i++)
		for (int j=1;j<=mb;j++)
			Vb[i][j]=(Vb[i][j]+Vb[i-1][j]+Vb[i][j-1]-Vb[i-1][j-1]);

	for (int i=1;i<=na;i++)
		for (int j=1;j<=ma;j++)
		{
			long long xa=(long long)(i-1)*nb/ng+1,xb=(long long)i*nb/ng;
			long long ya=(long long)(j-1)*mb/mg+1,yb=(long long)j*mb/mg;
			calc(xa,xb,ya,yb,Va[i][j]);
		}
	printf("%lld\n",ans);
	return 0;
}