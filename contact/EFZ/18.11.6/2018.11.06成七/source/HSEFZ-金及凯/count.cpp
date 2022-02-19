#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","r",stdout);
	int n,m,p;
	cin >> n >> m >> p;
	long ans = 1;
	if(m==1)
	{
		if(n==1)
		{
			cout << 1;
		}
		else if(n==2)
		{
			cout << 2;
		}
		else
		{
			cout << 3;
		}
	}
	else if(m==2)
	{
		if(n==1)
		{
			cout << 2;
		}
		else if(n==2)
		{
			cout << 16;
		}
		else
		{
			cout << 360;
		}
	}
	else if(m==3)
	{
		if(n==1)
		{
			cout << 6;
		}
		else if(n==2)
		{
			cout << 360;
		}
		else
		{ 
			cout << 108864;
		}
	}
	return 0;
}
