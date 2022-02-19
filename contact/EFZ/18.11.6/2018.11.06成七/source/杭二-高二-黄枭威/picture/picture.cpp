#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
char s1[1000010],s2[1000010];
LL n1,n2,m1,m2,Ln,Lm,w1,w2,h1,h2,t,t1,t2,ans,L,R;
LL a1[1000010],a2[1000010],s[1000010];
LL id1(LL x,LL y) {return((x-1)*m1+y);}
LL id2(LL x,LL y) {return((x-1)*m2+y);}
LL gcd(LL n,LL m)
{
	if (m==0) return(n);
	return(gcd(m,n%m));
}
LL get(LL d1,LL d2)
{
	LL last,now,res,tmp;
	res=0;
	last=0;
	for (LL i=1;i<=m1;i++)
	{
		now=i*w1/w2;
		tmp=(s[id2(d2,now)]-s[id2(d2,last)])*w2;
		if (a1[id1(d1,i)]==1) res=res+tmp;
		else res=res+(now-last)*w2-tmp;
		if (i!=m1)
		{
			tmp=i*w1-now*w2;
			if (a1[id1(d1,i)]==a2[id2(d2,now+1)]) res=res+tmp;
			if (a1[id1(d1,i+1)]==a2[id2(d2,now+1)]) res=res+w2-tmp;
			last=now+1;
		}
	}
	return(res);
}
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d\n",&n1,&m1);
	scanf("%s",s1);
	scanf("%d%d\n",&n2,&m2);
	scanf("%s",s2);
	if (m1<=m2)
	{
		for (LL i=1;i<=n1*m1;i++) a1[i]=s1[i-1]-'0';
		for (LL i=1;i<=n2*m2;i++) a2[i]=s2[i-1]-'0';
	}
	else
	{
		for (LL i=1;i<=n1*m1;i++) a2[i]=s1[i-1]-'0';
		for (LL i=1;i<=n2*m2;i++) a1[i]=s2[i-1]-'0';
		t=n1;n1=n2;n2=t;
		t=m1;m1=m2;m2=t;
	}
		
	s[0]=0;
	for (LL i=1;i<=n2;i++)
		for (LL j=1;j<=m2;j++) s[id2(i,j)]=s[id2(i,j-1)]+a2[id2(i,j)];
	Ln=n1*n2/gcd(n1,n2);
	Lm=m1*m2/gcd(m1,m2);
	w1=Lm/m1;
	w2=Lm/m2;
	h1=Ln/n1;
	h2=Ln/n2;
	t1=1;t2=1;
	ans=0;
	while(t1<=n1&&t2<=n2)
	{
		L=max((t1-1)*h1,(t2-1)*h2);
		R=min(t1*h1,t2*h2);
		ans=ans+(R-L)*get(t1,t2);
		if (t1*h1<t2*h2) t1++;
		else t2++;
	}
	printf("%lld\n",ans);
	return 0;
}
