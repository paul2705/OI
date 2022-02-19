#include<cstdio>
const int N=1000010;
int h1,w1,h2,w2,a[1000][1000],b[1000][1000];
char s1[N],s2[N];
void judge(){freopen("picture.in","r",stdin);freopen("picture.ans","w",stdout);}
int gcd(int a,int b){return a%b==0?b:gcd(b,a%b);}
int main()
{
	judge();
	scanf("%d%d%s",&h1,&w1,s1+1);
	scanf("%d%d%s",&h2,&w2,s2+1);
	int H=h1*h2/gcd(h1,h2),W=w1*w2/gcd(w1,w2);
	int HH=H/h1,WW=W/w1;
	for (int i=1;i<=h1*w1;i++)
	{
		int x=(i-1)/h1+1,y=(i-1)%w1+1;
		for (int j=1;j<=HH;j++)
			for (int k=1;k<=WW;k++)
				a[(x-1)*HH+j][(y-1)*WW+k]=s1[i]-'0';
	}
	HH=H/h2; WW=W/w2;
	for (int i=1;i<=h2*w2;i++)
	{
		int x=(i-1)/h2+1,y=(i-1)%w2+1;
		for (int j=1;j<=HH;j++)
			for (int k=1;k<=WW;k++)
				b[(x-1)*HH+j][(y-1)*WW+k]=s2[i]-'0';
	}
	int ans=0;
	for (int i=1;i<=H;i++)
		for (int j=1;j<=W;j++)
			if (a[i][j]==b[i][j]) ans++;
	printf("%d",ans);
	return 0;
}
