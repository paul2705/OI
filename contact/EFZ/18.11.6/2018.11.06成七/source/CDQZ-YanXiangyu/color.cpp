#include<bits/stdc++.h>
using namespace std;
const int N=120,M=120,S=10;
int n,m,T,bh,cnt,kw,bz;
int p[N],col[M],cv[S];
vector <int> l[N];
bool npd;
bool ud[M];
inline void mread(int &rx)
{
	int fx=1;char c=getchar();
	rx=0;
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	rx*=fx;
}
inline void mdfs(int wz,int nf)
{
	if(npd==0)
	{
		return ;
	}
	if(p[wz]!=bz&&ud[p[wz]]==0&&col[p[wz]]!=0&&col[p[wz]]!=bh) 
	{
		npd=0;return ;
	}
	int vsiz,i,vv;
	if(p[wz]!=bz&&ud[p[wz]]==0) col[p[wz]]=bh;
	vsiz=l[wz].size();
	for(i=0;i<vsiz;++i)
	{
		vv=l[wz][i];
		if(vv==nf) continue;
		mdfs(vv,wz);
	}
}
inline int mfind(int wz,int nf)
{
	int vsiz,i,vv,nfh=0,nkw;
	if(p[wz]==bz) nfh=wz;
	vsiz=l[wz].size();
	for(i=0;i<vsiz;++i)
	{
		vv=l[wz][i];
		if(vv==nf) continue;
		nkw=mfind(vv,wz);
		if(nkw>0) nfh=nkw;
	}
	return nfh;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int i,j,k,x,uu,vv,vsiz;
	bool nud;
	mread(n);mread(m);
	T=m;
	for(i=1;i<=n;++i)
	{
		mread(p[i]);
	}
	for(i=1;i<n;++i)
	{
		mread(uu);mread(vv);
		l[uu].push_back(vv);
		l[vv].push_back(uu);
	}
	for(i=1;i<=m;++i)
	{
		nud=0;
		for(j=1;j<=n;++j)
		{
			if(p[j]==i) nud=1;
		}
		if(nud==0)
		{
			ud[i]=1;T--;
			printf("%d 1 1\n",i);
		}
	}
	while(T--)
	{
		for(i=1;i<=m;++i)
		{
			if(ud[i]==1) continue;
			npd=1;bz=i;
			for(j=1;j<=n&&npd==1;++j)
			{
				if(p[j]==i)
				{
					memset(col,0,sizeof(col));
					bh=0;
					vsiz=l[j].size();
					for(k=0;k<vsiz&&npd==1;++k)
					{
						bh++;
						vv=l[j][k];
						mdfs(vv,j);
					}
				}
			}
			if(npd==1)
			{
				for(x=1;p[x]!=i;++x){}
				vsiz=l[x].size();
				memset(cv,0,sizeof(cv));
				cnt=0;
				ud[i]=1;
				for(j=0;j<vsiz;++j)
				{
					vv=l[x][j];
					kw=mfind(vv,x);
					if(kw>0)
					{
						cv[++cnt]=kw;
					}
				}
				if(cnt==0) 
				{
					printf("%d %d %d\n",i,x,x);
				}
				if(cnt==1)
				{
					printf("%d %d %d\n",i,x,cv[1]);
				}
				if(cnt==2)
				{
					printf("%d %d %d\n",i,cv[1],cv[2]);
				}
				break;
			}
		}
	}
	return 0;
}
