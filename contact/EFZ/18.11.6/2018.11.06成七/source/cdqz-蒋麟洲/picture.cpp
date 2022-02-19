#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int h=0,w=0,h1=0,w1=0,h2=0,w2=0,gh=0,gw=0;
char s1[1001000],s2[1001000];
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int i=0,j=0,ans=0;
	scanf("%d%d",&h1,&w1);
	scanf("%s",s1+1);
	scanf("%d%d",&h2,&w2);
	scanf("%s",s2+1);
	gh=gcd(h1,h2);
	h=(int)h1*(long long)h2/gh;
	gw=gcd(w1,w2);
	w=(int)w1*(long long)w2/gw;
	for (i=1;i<=h;i++)
	{
		for (j=1;j<=w;j++)
			ans+=s1[(int)ceil((i*(float)gh/h2)-1)*w1+j*gw/w2]==s2[(int)ceil((i*(float)gh/h1)-1)*w2+j*gw/w1]?1:0;
	}
	printf("%d",ans);
	return 0;
}
