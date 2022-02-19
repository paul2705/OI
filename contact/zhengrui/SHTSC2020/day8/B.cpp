#include<algorithm>
#include<cstdio>
#define mxn 100010
#define LL long long
#define pii pair<int,int>
#define fr first
#define sc second
#define mp make_pair
using namespace std;
const LL inf=1e18;
int n,m,N,M,sl,fh,nowx,nowy,ansx,ansy,ty[mxn];
pii a[mxn];
struct Line
{
	pii A,B;
}e[mxn];
void chkmin(LL &x,LL y) {if(y<x) x=y,ansx=nowx,ansy=nowy;}
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
//l<=at+bm<=r min a
//-r<=-at+-bm<=-l min -b
LL getstep(int m,int t,int l,int r)
{
	if(!l||r<l) return 0;
	if(!t) return -1;
	if(r/t>(l-1)/t) return (l+t-1)/t;
	LL res=getstep(t,m%t,t-r%t,t-l%t);
	if(!~res) return res;
	return (l+m*res+t-1)/t;
}
LL solve(int x,int y,int sx,int yl,int yr,int W,int H,bool flg=0)
{
	LL s2,s1=(sx-x+W)%W;
	y=(y+s1)%H;
	s2=getstep(H,W%H,(yl-y+H)%H,(yr-y+H)%H);
	if(!~s2) return inf;
	nowx=sx;nowy=(y+W*(s2%H))%H;
	if(flg) swap(nowx,nowy);
	return s1+W*s2;
}
int main()
{
	N=rd();M=rd();
	n=rd();
	for(int i=1;i<=n;++i) a[i].fr=rd(),a[i].sc=rd();
	a[n+1]=a[1];
	for(int i=1;i<=n;++i)
		if(a[i].fr==a[i+1].fr)
		{
			if(a[i].sc<a[i+1].sc) e[i]=(Line){a[i],a[i+1]};
			else e[i]=(Line){a[i+1],a[i]};
		}
		else
		{
			ty[i]=1;
			if(a[i].fr<a[i+1].fr) e[i]=(Line){a[i],a[i+1]};
			else e[i]=(Line){a[i+1],a[i]};
		}
	m=n;
	for(int i=1;i<=n;++i)
	{
		e[++m]=e[i];ty[m]=ty[i];e[m].A.fr=N*2-e[m].A.fr;e[m].B.fr=N*2-e[m].B.fr;
		e[++m]=e[i];ty[m]=ty[i];e[m].A.sc=M*2-e[m].A.sc;e[m].B.sc=M*2-e[m].B.sc;
		e[++m]=e[i];ty[m]=ty[i];e[m].A.fr=N*2-e[m].A.fr;e[m].B.fr=N*2-e[m].B.fr;
								e[m].A.sc=M*2-e[m].A.sc;e[m].B.sc=M*2-e[m].B.sc;
	}
	for(int i=n+1;i<=m;++i)
	{
		if(e[i].A.fr>e[i].B.fr) swap(e[i].A,e[i].B);
		if(e[i].A.sc>e[i].B.sc) swap(e[i].A,e[i].B);
	}
	n=m;LL ans;int x,y;
	for(m=rd();m;--m)
	{
		x=rd();y=rd();ans=inf;
		for(int i=1;i<=n;++i)
			if(!ty[i]) chkmin(ans,solve(x,y,e[i].A.fr,e[i].A.sc,e[i].B.sc,N*2,M*2));
			else chkmin(ans,solve(y,x,e[i].A.sc,e[i].A.fr,e[i].B.fr,M*2,N*2,1));
		if(ans<inf)
		{
			if(ansx>N) ansx=N*2-ansx;
			if(ansy>M) ansy=M*2-ansy;
			printf("%lld %d %d\n",ans,ansx,ansy);
		}
		else puts("-1");
	}
	return 0;
}
