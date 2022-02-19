#include <bits/stdc++.h>
using namespace std;
long w1,h1,w2,h2;
string pic1,pic2;
long gcd(long x,long y)
{
	if(x==0||y==0)
	{
		return max(x,y);
	}
	else if(x==1||y==1)
	{
		return 1;
	}
	else
	{
		long tmp ;
		if(x<y)
		{
			tmp = x;
			x = y;
			y = tmp;
		}
		return gcd(y,x%y);
	}
}
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	cin >> h1 >> w1;
	cin >> pic1;
	cin >> h2 >> w2;
	cin >> pic2;
	long gw = gcd(w1,w2),gh = gcd(h1,h2),infx,supx,infy,supy;
	long long siminum = 0;
	for(long x1=0;x1<w1;x1++)
	{
		for(long y1=0;y1<h1;y1++)
		{
			for(long x2=w2*x1/w1;x2<=floor((x1+1)*w2/w1);x2++)
			{
				for(long y2=h2*y1/h1;y2<=floor((y1+1)*h2/h1);y2++)
				{
					if(pic1[x1*h1+y1]==pic2[x2*h2+y2])
					{
						if(x2*w1<x1*w2)
						{
							infx = w2*x1/gw;
						}
						else
						{
							infx = x2*w1/gw;
						}
						if(y2*h1<y1*h2)
						{
							infy = h2*y1/gh;
						}
						else
						{
							infy = y2*h1/gh;
						}
						if((x2+1)*w1>(x1+1)*w2)
						{
							supx = (x1+1)*w2/gw-1;
						}
						else
						{
							supx = (x2+1)*w1/gw-1;
						}
						if((y2+1)*h1>(y1+1)*h2)
						{
							supy = (y1+1)*h2/gh-1;
						}
						else
						{
							supy = (y2+1)*h1/gh-1;
						}
						//cout << x1 << y1 << infx << supx << infy << supy << "\n";
						siminum += (supx-infx+1)*(supy-infy+1);
					}
				}
			}
		}
	}
	cout << siminum;
	return 0;
}
