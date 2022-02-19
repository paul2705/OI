#include<bits/stdc++.h>
using namespace std;
long long w1,h1,w2,h2;
long long ww,hh;
char s1[1000009],s2[1000009];
long long len1,len2;
long long gw,gh;
long long ans;
long long read()
{
	long long tot=0,fs=1;
	char ch;
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') ch=getchar(),fs=-1;
	while(ch>='0'&&ch<='9') tot=tot*10+ch-'0',ch=getchar();
	return tot*fs;
}
long long gcd(long long a,long long b)
{
	if(b) while((a %= b) && (b %= a));
	return a + b;	
} 
int main ()
{
    freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
    w1=read(),h1=read();
    len1=w1*h1;
    scanf("%s",s1+1);
    w2=read(),h2=read();
    len2=w2*h2;
    scanf("%s",s2+1);
    gw=gcd(w1,w2);
    gh=gcd(h1,h2);
    ww=w1*w2/gw,hh=h1*h2/gh;
    long long ls1=w2/gw,ls2=h2/gh,ls3=w1/gw,ls4=h1/gh;
    for(long long i=1;i<=ww;++i)
    {
    	for(long long j=1;j<=hh;++j)
		{
			if(s1[((i-1)/(ls1))*h1+(j-1)/(ls2)+1]==s2[((i-1)/(ls3))*h2+(j-1)/(ls4)+1]) ++ans;
		}
    } 
    printf("%lld",ans);
    return 0; 	
}
/*
1 2
01
2 1
01
*/
