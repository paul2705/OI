#include<algorithm>
#include<cstdio>
#define LL long long
using namespace std;
int n,N,sl,fh,a[20],p[1<<20],w[1<<20],id[1<<20],ex[1<<20],Ans[1<<20];
LL ans;
int rd(){
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
int main(){
	n=rd();N=1<<n;
	for(int i=0;i<n;++i) a[i]=rd(),id[1<<i]=i;
	for(int i=1;i<N;++i) w[i]=w[i^(i&-i)]^a[id[i&-i]],p[i]=i;
	sort(p+1,p+N,[&](const int &x,const int &y){return w[x]>w[y];});
	Ans[1]=p[1];ex[p[1]]=1;
	for(int S,k=0,l=2,i=2;i<=n;++i)
	{
		S=(1<<i)-1;k=k<<1|1;for(;l<N&&ex[p[l]];++l);
		for(int j=k;~j;--j) ex[Ans[j^S]=Ans[j]^p[l]]=1;
	}
	for(int i=2;i<N;++i) ans+=w[Ans[i]^Ans[i-1]];
	printf("%lld\n",ans);
	for(int i=1;i<N;++i) printf("%d ",Ans[i]);puts("");
	return 0;
}
