#include<cstdio>

using namespace std;

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define LL long long

const int N=1000005;

int n1,m1,n2,m2,nn,mm,le[N],ri[N],sum[N];
char s0[N],s1[N],s2[N];
LL ans;

int min(int x,int y) {return x<y?x:y;}
int max(int x,int y) {return x>y?x:y;}
void swap(int &x,int &y) {int t=x;x=y;y=t;}
int SUM(int x,int y) {return sum[(x-1)*m2+y];}
int gcd(int x,int y) {return (!y)?x:gcd(y,x%y);}
int S1(int x,int y) {return s1[(x-1)*m1+y]=='1';}
int S2(int x,int y) {return s2[(x-1)*m2+y]=='1';}
void SWAP() {rep(i,1,n1*m1) s0[i]=s1[i];rep(i,1,n2*m2) s1[i]=s2[i];rep(i,1,n1*m1) s2[i]=s0[i];}
void getS()
{
	rep(i,1,n2) rep(j,1,m2)
	  sum[(i-1)*m2+j]=(j==1?0:sum[(i-1)*m2+j-1])+S2(i,j);
}
void getLR()
{
	for (int i=1,j=1;i<=m1||j<=m2;)
	{
		if (!le[i]) le[i]=j;ri[i]=j;
		int en1=i*(m2/mm),en2=j*(m1/mm);
		if (en1<=en2) i++;if (en2<=en1) j++;
	}
}
LL work(int Ln1,int Ln2)
{
	LL res=0;rep(i,1,m1)
	{
		int j=le[i],en=j*(m1/mm),EN=(i-1)*(m2/mm);
		res+=(S1(Ln1,i)==S2(Ln2,j))*(en-EN);
		if (ri[i]-le[i]-1>0)
		{
			LL _=SUM(Ln2,ri[i]-1)-SUM(Ln2,le[i]);
			if (!S1(Ln1,i)) _=(ri[i]-le[i]-1)-_;
			res+=_*(m1/mm);
		}
		if (ri[i]!=le[i])
		{
				j=ri[i],en=i*(m2/mm),EN=(j-1)*(m1/mm);
			res+=(S1(Ln1,i)==S2(Ln2,j))*(en-EN);
		}
	}
	return res;
}
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d",&n1,&m1);scanf("%s",s1+1);
	scanf("%d%d",&n2,&m2);scanf("%s",s2+1);
	if (m1>m2) {SWAP();swap(n1,n2);swap(m1,m2);}
	nn=gcd(n1,n2),mm=gcd(m1,m2);getS();getLR();
	for (int i=1,j=1;i<=n1||j<=n2;)
	{
		int en1=i*(n2/nn),en2=j*(n1/nn);
		int EN1=(i-1)*(n2/nn),EN2=(j-1)*(n1/nn);
		ans+=work(i,j)*(min(en1,en2)-max(EN1,EN2));
		if (en1<=en2) i++;if (en2<=en1) j++;
	}
	printf("%lld\n",ans);
	return 0;
}
