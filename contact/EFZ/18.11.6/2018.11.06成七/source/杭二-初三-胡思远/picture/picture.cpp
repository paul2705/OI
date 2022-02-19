#include <bits/stdc++.h> 
using namespace std;

#define ll long long

ll h1,w1,h2,w2,len1,len2,ans;
char c1[1000002],c2[1000002];

ll gcd(ll x,ll y)
{
	if (!y) return x;else return gcd(y,x%y);
}

ll lcm(ll x,ll y)
{
	return x*y/gcd(x,y);
}

int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	cin>>h1>>w1;
	for (int i=1;i<=h1*w1;i++)
	{
		char s=getchar();
		while (s<'0'||s>'1') s=getchar();
		c1[++len1]=s;
	}
	cin>>h2>>w2;
	for (int i=1;i<=h2*w2;i++)
	{
		char s=getchar();
		while (s<'0'||s>'1') s=getchar();
		c2[++len2]=s;
	}
	for (int i=1;i<=lcm(h1,h2);i++)
	    for (int j=1;j<=lcm(w1,w2);j++)
	        if (c1[(i-1)/h2*w1+(j-1)/w2+1]==c2[(i-1)/h1*w2+(j-1)/w1+1]) ans++;
	cout<<ans<<endl;
	return 0;
}

