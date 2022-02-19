#include<bits/stdc++.h>
using namespace std;
const int N=1020,M=1020,L=1020;
int H,W,h1,w1,h2,w2,ans=0;
char s1[L],s2[L];
int t1[N][M],t2[N][M];
inline int mgcd(int a,int b)
{
	int c;
	if(a<b) swap(a,b);
	while(b>0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	int temp,i,j,x,y,pos,col;
	scanf("%d%d",&h1,&w1);
	scanf("%s",&s1);
	scanf("%d%d",&h2,&w2);
	scanf("%s",&s2);
	temp=mgcd(h1,h2);
	H=h1*h2/temp;
	temp=mgcd(w1,w2);
	W=w1*w2/temp;
	for(i=1;i<=h1;++i)
	{
		for(j=1;j<=w1;++j)
		{
			pos=(i-1)*w1+j-1; 
		    if(s1[pos]=='0') col=0;
		    else col=1;
		    for(x=(i-1)*(H/h1)+1;x<=i*(H/h1);++x)
		    {
		    	for(y=(j-1)*(W/w1)+1;y<=j*(W/w1);++y)
		    	{
		    		t1[x][y]=col;
		    	}
		    }
		}
	}
	
	for(i=1;i<=h2;++i)
	{
		for(j=1;j<=w2;++j)
		{
			pos=(i-1)*w2+j-1; 
		    if(s2[pos]=='0') col=0;
		    else col=1;
		    for(x=(i-1)*(H/h2)+1;x<=i*(H/h2);++x)
		    {
		    	for(y=(j-1)*(W/w2)+1;y<=j*(W/w2);++y)
		    	{
		    		t2[x][y]=col;
		    	}
		    }
		}
	}
	
	for(i=1;i<=H;++i)
	{
		for(j=1;j<=W;++j)
		{
			if(t1[i][j]==t2[i][j])
			{
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
