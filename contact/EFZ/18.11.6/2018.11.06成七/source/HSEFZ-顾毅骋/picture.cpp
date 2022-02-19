#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int h1,hh1,H,h2,hh2,w1,ww1,W,w2,ww2;
int ans,i,j;
int a[1000][1000],b[1000][1000];
char blank;
int gcd(int x,int y)
{
	if (y==0) return x;
	  else return gcd(y,x%y);
}
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d",&h1,&w1);
	for (i=0;i<h1;i++)
	  for (j=0;j<w1;j++)
	  {
	    do {scanf("%c",&blank);}
	    while (blank!='0' && blank!='1');
	    if (blank=='1') a[i][j]=1;
	      else a[i][j]=0;
	  }
	scanf("%d%d",&h2,&w2);
	for (i=0;i<h2;i++)
	  for (j=0;j<w2;j++)
	  {
	    do {scanf("%c",&blank);}
	    while (blank!='0' && blank!='1');
	    if (blank=='1') b[i][j]=1;
	      else b[i][j]=0;
	  }
	H=gcd(h1,h2);
	W=gcd(w1,w2);
	hh1=h2/H;
	hh2=h1/H;
	ww1=w2/W;
	ww2=w1/W;
	for (i=0;i<hh1*hh2*H;i++)
	  for (j=0;j<ww1*ww2*W;j++)
	  {
	  	if (a[i/hh1][j/ww1]==b[i/hh2][j/ww2])
	  	  ans++;
	  }
	printf("%d",ans);
	return 0;
}
