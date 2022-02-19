#include<bits/stdc++.h>
using namespace std;

int w1,h1,w2,h2,W,H,ans;
int a[103][103],b[103][103];

inline int read(){
	char c=getchar();
    while (c<'0' || c>'9')
      c=getchar();
    return c & 15;
}

int gcd(int a,int b){
	return b ? gcd(b,a%b) : a;	
}

int main(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d",&h1,&w1);
	for (int i=1;i<=h1;i++)
	  for (int j=1;j<=w1;j++)
	    a[i][j]=read();
	scanf("%d%d",&h2,&w2);
	for (int i=1;i<=h2;i++)
	  for (int j=1;j<=w2;j++)
	    b[i][j]=read();
    H=h1*h2/gcd(h1,h2);W=w1*w2/gcd(w1,w2);
    ans=0;
	for (int i=1;i<=H;i++)
      for (int j=1;j<=W;j++)
	    ans+=(a[(i-1)/(H/h1)+1][(j-1)/(W/w1)+1]==b[(i-1)/(H/h2)+1][(j-1)/(H/w2)+1]); 
	printf("%d\n",ans);    
	return 0;
}
