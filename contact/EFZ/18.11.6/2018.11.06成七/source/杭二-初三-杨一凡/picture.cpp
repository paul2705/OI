#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n1,m1,n2,m2,n,m;
int a1[1000010],a2[1000010];
ll ans=0,w[20000010];
int rt=0,tot=0,ch[4][20000010];

inline void file() {
	freopen("picture.in","r",stdin);freopen("picture.out","w",stdout);
}
template <typename T> inline T Min(T x,T y) { return x<y?	x:y; }
template <typename T> inline T Max(T x,T y) { return x>y?	x:y; }
inline int read() {
	register char c=getchar(); while(c!='0'&&c!='1')	c=getchar(); return c-'0';
}
ll gcd(ll x,ll y) { return y?	gcd(y,x%y):x; }
void Insert(int &u,ll lx,ll ly,ll rx,ll ry,ll x,ll y,ll xx,ll yy,int v) {
	if(lx>xx||rx<x||ly>yy||ry<y||lx>rx||ly>ry)	return ;
	if(!u)	u=++tot;
	if(lx>=x&&ly>=y&&rx<=xx&&ry<=yy) { w[u]=(ll)v*(rx-lx+1ll)*(ry-ly+1ll);return ; }
//	printf(">>> %d %d %d %d : %d %d %d %d\n",lx,ly,rx,ry,x,y,xx,yy);
	ll midx=(lx+rx)/2,midy=(ly+ry)/2;
	Insert(ch[0][u],lx,ly,midx,midy,x,y,xx,yy,v),Insert(ch[1][u],lx,midy+1,midx,ry,x,y,xx,yy,v);
	Insert(ch[2][u],midx+1,ly,rx,midy,x,y,xx,yy,v),Insert(ch[3][u],midx+1,midy+1,rx,ry,x,y,xx,yy,v);
	w[u]=w[ch[0][u]]+w[ch[1][u]]+w[ch[2][u]]+w[ch[3][u]];
}
void Ask(int u,ll lx,ll ly,ll rx,ll ry,ll x,ll y,ll xx,ll yy,int v) {
	if(lx>xx||rx<x||ly>yy||ry<y||lx>rx||ly>ry)	return ;
	if(lx>=x&&ly>=y&&rx<=xx&&ry<=yy) {
		if(v)	ans+=w[u]; else	ans+=(rx-lx+1ll)*(ry-ly+1ll)-w[u]; return ;
	}
	if(!w[u]||w[u]==(rx-lx+1ll)*(ry-ly+1ll)) {
		if((v&&w[u])||(!v&&!w[u]))	ans+=(Min(rx,xx)-Max(lx,x)+1ll)*(Min(ry,yy)-Max(ly,y)+1ll); return ;
	}
	ll midx=(lx+rx)/2,midy=(ly+ry)/2;
	Ask(ch[0][u],lx,ly,midx,midy,x,y,xx,yy,v),Ask(ch[1][u],lx,midy+1,midx,ry,x,y,xx,yy,v);
	Ask(ch[2][u],midx+1,ly,rx,midy,x,y,xx,yy,v),Ask(ch[3][u],midx+1,midy+1,rx,ry,x,y,xx,yy,v);
}
int main() {
	file();
	scanf("%d%d",&n1,&m1); for(register ll i=1;i<=n1*m1;++i)	a1[i]=read();
	scanf("%d%d",&n2,&m2); for(register ll i=1;i<=n2*m2;++i)	a2[i]=read();
	n=n1/gcd(n1,n2)*n2,m=m1/gcd(m1,m2)*m2;
	for(register ll i=1;i<=n1;++i)
		for(register ll j=1;j<=m1;++j)
			Insert(rt,1ll,1ll,n,m,(i-1ll)*(n/n1)+1ll,(j-1ll)*(m/m1)+1ll,i*(n/n1),j*(m/m1),a1[(i-1)*m1+j]);
//	for(ll i=1;i<=n;++i) {
//		for(ll j=1;j<=m;++j)
//			Ask(rt,1ll,1ll,n,m,i,j,i,j,1),printf("%d",ans),ans=0;
//		printf("\n");
//	}
	for(register ll i=1;i<=n2;++i)
		for(register ll j=1;j<=m2;++j)
			Ask(rt,1ll,1ll,n,m,(i-1ll)*(n/n2)+1ll,(j-1ll)*(m/m2)+1ll,i*(n/n2),j*(m/m2),a2[(i-1)*m2+j]);
	printf("%lld\n",ans);
	return 0;
}
