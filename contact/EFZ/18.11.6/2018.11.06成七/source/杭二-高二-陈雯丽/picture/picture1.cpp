#include<algorithm>
#include<cstdio>

using namespace std;

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define LL long long

const int N=1000005;

int n1,m1,n2,m2,nn,mm;
char s1[N],s2[N];
LL ans;

int gcd(int x,int y) {return (!y)?x:gcd(y,x%y);}
LL work(int _1,int _2)
{
	LL res=0;
	for (int i=1,j=1;i<=m1||j<=m2;)
	{
		int en1=i*(m2/mm),en2=j*(m1/mm);
		int EN1=(i-1)*(m2/mm),EN2=(j-1)*(m1/mm),EN=max(EN1,EN2);
		if (en1<=en2) {res+=(s1[(_1-1)*m1+i]==s2[(_2-1)*m2+j])*(en1-EN);i++;}
		else {res+=(s1[(_1-1)*m1+i]==s2[(_2-1)*m2+j])*(en2-EN);j++;}
	}
	return res;
}
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.ans","w",stdout);
	scanf("%d%d",&n1,&m1);scanf("%s",s1+1);
	scanf("%d%d",&n2,&m2);scanf("%s",s2+1);
	nn=gcd(n1,n2),mm=gcd(m1,m2);
	for (int i=1,j=1;i<=n1||j<=n2;)
	{
		int en1=i*(n2/nn),en2=j*(n1/nn);
		int EN1=(i-1)*(n2/nn),EN2=(j-1)*(n1/nn),EN=max(EN1,EN2);
		if (en1<=en2) {ans+=work(i,j)*(en1-EN);i++;}
		else {ans+=work(i,j)*(en2-EN);j++;}
	}
	printf("%lld\n",ans);
	return 0;
}
