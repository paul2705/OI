#include<cstdio>
#include<iostream>
using namespace std;
int w1,h1,w2,h2,ans;
char a[1000010],b[1000010];
int gcd(int x,int y)
{
	while(y!=0)
	{
		int r=y;
		y=x%y;
		x=r;
	}
	return x;
}


int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d",&h1,&w1);
	char c=getchar();
	for(int i=1;i<=w1*h1;i++)
	a[i]=getchar();
	c=getchar();
	scanf("%d%d",&h2,&w2);
	c=getchar();
	for(int i=1;i<=w2*h2;i++)
	b[i]=getchar();
	long long w,h;
	if(w1>w2) w=gcd(w1,w2);
	else w=gcd(w2,w1);
	if(h1>h2) h=gcd(h1,h2);
	else h=gcd(h2,h1);
	w=w1*w2/w;h=h1*h2/h;
	int ww1=w/w1,ww2=w/w2,hh1=h/h1,hh2=h/h2;
	ans=0;
	for(long long i=1;i<=h;i++)
	{
		int h11=i%hh1==0?i/hh1:i/hh1+1;
		int h22=i%hh2==0?i/hh2:i/hh2+1;
		for(long long j=1;j<=w;j++)
		{
			int w11=j%ww1==0?j/ww1:j/ww1+1;
		    int w22=j%ww2==0?j/ww2:j/ww2+1;
		    if(a[(h11-1)*w1+w11]==b[(h22-1)*w2+w22])
			    ans++;
		}
	}
	printf("%d",ans);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
