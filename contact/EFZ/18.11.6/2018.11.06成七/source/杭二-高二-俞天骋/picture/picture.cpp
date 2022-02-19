#include<cstdio>
long long n,m,h,w,ti,t,n1,m1,h1,w1,pre[1000011],ans;
char c[1000011],ci[1000011];
int gcd(int x,int y)
{
	if(x==0)return(y);
	return(gcd(y%x,x));
}
long long ask(int x,int y)
{
	if((x==0)||(y==0))return(0);
	else return(pre[(x-1)*w+y]);
}
long long calc(long long x,long long y,long long xi,long long yi)
{
	long long l,r,li,ri,sum;
	l=(x-1)/n1;
	r=(xi-1)/n1;
	li=(y-1)/m1;
	ri=(yi-1)/m1;
	l++;
	r++;
	li++;
	ri++;
	sum=0;
	if(l==r)
	{
		if(li==ri)sum=sum+(xi-x+1)*(yi-y+1)*(ask(l,ri)-ask(l-1,ri)-ask(l,ri-1)+ask(l-1,ri-1));
		else
		{
			sum=sum+(xi-x+1)*m1*(ask(l,ri-1)-ask(l-1,ri-1)-ask(l,li)+ask(l-1,li));
			sum=sum+(xi-x+1)*(m1*li-y+1)*(ask(l,li)-ask(l-1,li)-ask(l,li-1)+ask(l-1,li-1));
			sum=sum+(xi-x+1)*(yi-m1*(ri-1))*(ask(l,ri)-ask(l-1,ri)-ask(l,ri-1)+ask(l-1,ri-1));
		}
	}
	else
	{
		if(li==ri)
		{
			sum=sum+n1*(yi-y+1)*(ask(r-1,ri)-ask(l,ri)-ask(r-1,ri-1)+ask(l,ri-1));
			sum=sum+(n1*l-x+1)*(yi-y+1)*(ask(l,li)-ask(l-1,li)-ask(l,li-1)+ask(l-1,li-1));
			sum=sum+(xi-n1*(r-1))*(yi-y+1)*(ask(r,ri)-ask(r-1,ri)-ask(r,ri-1)+ask(r-1,ri-1));
		}
		else
		{
			sum=sum+n1*m1*(ask(r-1,ri-1)-ask(r-1,li)-ask(l,ri-1)+ask(l,li));
			sum=sum+(n1*l-x+1)*(m1*li-y+1)*(ask(l,li)-ask(l-1,li)-ask(l,li-1)+ask(l-1,li-1));
			sum=sum+(xi-n1*(r-1))*(yi-m1*(ri-1))*(ask(r,ri)-ask(r-1,ri)-ask(r,ri-1)+ask(r-1,ri-1));
			sum=sum+(n1*l-x+1)*(yi-m1*(ri-1))*(ask(r,li)-ask(r-1,li)-ask(r,li-1)+ask(r-1,li-1));
			sum=sum+(xi-n1*(r-1))*(m1*li-y+1)*(ask(l,ri)-ask(l-1,ri)-ask(l,ri-1)+ask(l-1,ri-1));
			sum=sum+(n1*l-x+1)*m1*(ask(l,ri-1)-ask(l-1,ri-1)-ask(l,li)+ask(l-1,li));
			sum=sum+(xi-n1*(r-1))*m1*(ask(r,ri-1)-ask(r-1,ri-1)-ask(r,li)+ask(r-1,li));
			sum=sum+n1*(yi-m1*(ri-1))*(ask(r-1,ri)-ask(r-1,ri-1)-ask(l,ri)+ask(l,ri-1));
			sum=sum+n1*(m1*li-y+1)*(ask(r-1,li)-ask(r-1,li-1)-ask(l,li)+ask(l-1,li-1));
		}
	}
	return(sum);
}
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",c+1);
	scanf("%lld%lld",&h,&w);
	t=gcd(h,n);ti=gcd(m,w);
	scanf("%s",ci+1);
	for(int i=1;i<=h;i++)
	{
		pre[(i-1)*w+1]=ci[(i-1)*w+1]-'0';
		for(int j=2;j<=w;j++)pre[(i-1)*w+j]=pre[(i-1)*w+j-1]+ci[(i-1)*w+j]-'0';
	} 
	for(int j=1;j<=w;j++)
	for(int i=2;i<=h;i++)pre[(i-1)*w+j]=pre[(i-2)*w+j]+pre[(i-1)*w+j];
	n1=n/t;
	m1=m/ti;
	h1=h/t;
	w1=w/ti;
	ans=0;
	for(long long i=1;i<=n;i++)
	for(long long j=1;j<=m;j++)
	{
		if(c[(i-1)*m+j]=='1')ans=ans+calc((i-1)*h1+1,(j-1)*w1+1,i*h1,j*w1);
		else ans=ans+h1*w1-calc((i-1)*h1+1,(j-1)*w1+1,i*h1,j*w1);
	}
	printf("%lld\n",ans); 
}
