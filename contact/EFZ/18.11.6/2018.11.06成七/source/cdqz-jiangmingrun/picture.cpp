#include<stdio.h>
char s1[1048576],s2[1048576];
int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
int a1[2097152],b1[2097152],c1[2097152],num1=0;
int a2[2097152],b2[2097152],c2[2097152],num2=0;
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	int h1,w1,h2,w2;
	scanf("%d%d%s%d%d%s",&h1,&w1,s1,&h2,&w2,s2);
	int h=gcd(h1,h2);
	int w=gcd(w1,w2);
	int now1=0,now2=0;
	long long now=0;
	while(now1<h1&&now2<h2)
	{
		if((long long)(now1+1)*h2<(long long)(now2+1)*h1)
		{
			a1[num1]=now1;
			b1[num1]=now2;
			c1[num1]=(long long)(now1+1)*h2-now;
			now=(long long)(now1+1)*h2;
			now1++;
		}
		else
		{
			a1[num1]=now1;
			b1[num1]=now2;
			c1[num1]=(long long)(now2+1)*h1-now;
			now=(long long)(now2+1)*h1;
			now2++;
		}
		num1++;
	}
	now1=0;
	now2=0;
	now=0;
	while(now1<w1&&now2<w2)
	{
		if((long long)(now1+1)*w2<(long long)(now2+1)*w1)
		{
			a2[num2]=now1;
			b2[num2]=now2;
			c2[num2]=(long long)(now1+1)*w2-now;
			now=(long long)(now1+1)*w2;
			now1++;
		}
		else
		{
			a2[num2]=now1;
			b2[num2]=now2;
			c2[num2]=(long long)(now2+1)*w1-now;
			now=(long long)(now2+1)*w1;
			now2++;
		}
		num2++;
	}
	long long ans=0;
	for(int i=0;i<num1;i++)
	{
		for(int j=0;j<num2;j++)
		{
			if(s1[a1[i]*w1+a2[j]]==s2[b1[i]*w2+b2[j]])
			{
				ans+=(long long)c1[i]*c2[j];
			}
		}
	}
	ans/=h;
	ans/=w;
	printf("%lld\n",ans);
	return 0;
}
