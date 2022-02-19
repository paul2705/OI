#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long h1,w1,h2,w2,h,w,ans;
int line1[1000011],line2[1000011];
char l1[1000011],l2[1000011];
long long gcd(int m,int n)
{
	if(n==0)return m;else
	return gcd(n,m%n);
}
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	cin>>h1>>w1;
	cin>>l1;
	cin>>h2>>w2;
	cin>>l2;
	for(int i=1;i<=h1*w1;i++)
	{
		line1[i]=l1[i-1]-'0';
	}
	for(int i=1;i<=h2*w2;i++)
	{
		line2[i]=l2[i-1]-'0';
	}
	h=h1*h2/gcd(h1,h2);
	w=w1*w2/gcd(w1,w2);
	for(long long i=1;i<=h1;i++)
	{
		for(long long t=1;t<=w1;t++)
		{
			long long x1=(i-1)*h/h1;
			long long y1=(t-1)*w/w1;
			long long x2=i*h/h1;
			long long y2=t*w/w1;
			long long leftupx=x1*h2/h;
			long long leftupy=y1*w2/w;
			x1++;y1++;
			long long rightdownx=x2*h2/h;
			if(x2*h2%h)rightdownx++;
			long long rightdowny=y2*w2/w;
			if(y2*w2%w)rightdowny++;
			for(long long x=leftupx+1;x<=rightdownx;x++)
			{
				for(long long y=leftupy+1;y<=rightdowny;y++)
				{
					long long xx1=(x-1)*h/h2+1;
					long long yy1=(y-1)*w/w2+1;
					long long xx2=x*h/h2;
					long long yy2=y*w/w2;
					if(line1[(i-1)*w1+t]==line2[(x-1)*w2+y])
					{
						//cout<<i<<' '<<t<<' '<<x<<' '<<y<<' '<<ans<<endl;
						//cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<xx1<<' '<<yy1<<' '<<xx2<<' '<<yy2<<endl;
						ans=ans+(min(yy2,y2)-max(yy1,y1)+1)*(min(xx2,x2)-max(xx1,x1)+1);
					}
				}
			}
		}
	}
	cout<<ans;
}
