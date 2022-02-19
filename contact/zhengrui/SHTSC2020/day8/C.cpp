#include<algorithm>
#include<cstring>
#include<cstdio>
//#define debug
#define db double
using namespace std;
db P,f[510][510],g[510][510],C[510][510],F[510][510],G[510][510];
int n,m,K,sl,fh,a[510];
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
int calc(int x,int y) {return (x+y)*(y-x+1)/2;}
int main()
{
	n=rd();m=rd();K=rd();P=1.0/m;
	for(int i=1;i<=n;++i) a[i]=min(m,rd());
	for(int i=1;i<=K;++i) a[i+n]=m;
	sort(a+1,a+n+1);
	for(int i=0;i<=n+K;++i) C[i][0]=C[i][i]=1;
	for(int i=1;i<=n+K;++i)
		for(int j=1;j<i;++j)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	for(int i=1;i<=n+K;++i) f[i][i-1]=1;
	db x,fp;
	for(int i=1;i<=K;++i)
		for(int r,l=1;l+i-1<=n+K;++l)
		{
			r=l+i-1;
			for(int j=l;j<=r;++j)
				if((a[j]^a[l-1])&&(fp=f[l][j-1]*f[j+1][r])>0)
				{
					x=P*(a[j]-a[l-1]);
					f[l][r]+=x*fp*C[i-1][j-l];
					g[l][r]+=x*C[i-1][j-l]*(f[l][j-1]*g[j+1][r]+f[j+1][r]*g[l][j-1]);
					if(j<=n) g[l][r]+=P*fp*C[i-1][j-l]*calc(a[l-1]+1,a[j]);
				}
		}
#ifdef debug
	for(int l=1;l<=n+K;++l,puts(""))
		for(int r=l;r<=n+K;++r)
			printf("%.10lf ",f[l][r]);
	for(int l=1;l<=n+K;++l,puts(""))
		for(int r=l;r<=n+K;++r)
			printf("%.10lf ",g[l][r]);
#endif
	F[0][0]=1;
	for(int j,L,r=1;r<=n+K;++r)
	{
		memcpy(F[r],F[r-1],sizeof(F[r]));
		memcpy(G[r],G[r-1],sizeof(G[r]));
		for(int l=1;l<=r;++l)
			if(f[l][r]>0)
			{
				j=max(0,l-2);L=r-l+1;
				for(int i=0;i<l&&i+L<=K;++i)
					if(F[j][i]>0)
					{
						
						F[r][i+L]+=f[l][r]*F[j][i]*C[i+L][i];
						G[r][i+L]+=C[i+L][i]*(f[l][r]*G[j][i]+F[j][i]*g[l][r]);
					}
			}
	}
	printf("%.10lf\n",G[n+K][K]);
	return 0;
}
