#include <bits/stdc++.h>

using namespace std;

const int maxn=5005;
char str[2][maxn];
int h[2],w[2],s[2],hl[2],wl[2];
int hg,wg;
int p[2][maxn][maxn];
int q[2][maxn][maxn];

int gcd(int x,int y)
{
	return x==0?y:gcd(y%x,x);
}

int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	for(int ab=0;ab<2;ab++)
	{
		scanf("%d%d",&h[ab],&w[ab]);
		s[ab]=h[ab]*w[ab];
		scanf("%s",str[ab]);
		for(int i=0;i<s[ab];i++)
			p[ab][i/w[ab]][i%w[ab]]=str[ab][i]-'0';
	}
	
	hg=h[0]*h[1]/gcd(h[0],h[1]);
	wg=w[0]*w[1]/gcd(w[0],w[1]);
	for(int ab=0;ab<2;ab++)
	{
		hl[ab]=hg/h[ab];
		wl[ab]=wg/w[ab];
	}
	
	for(int ab=0;ab<2;ab++)
	{
		for(int i=0;i<h[ab];i++)
		{
			for(int j=0;j<w[ab];j++)
			{
				for(int k=i*hl[ab];k<(i+1)*hl[ab];k++)
				{
					for(int l=j*wl[ab];l<(j+1)*wl[ab];l++)
					{
						q[ab][k][l]=p[ab][i][j];
					}
				}
			}
		}
	}
	
	int ans=0;
	for(int i=0;i<hg;i++)
	{
		for(int j=0;j<wg;j++)
		{
			if(q[0][i][j]==q[1][i][j])
				ans++;
		}
	}
	printf("%d",ans);
	
	return 0;
}









