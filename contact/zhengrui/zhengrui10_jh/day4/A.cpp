#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int fa[MAXN],n;
ll b[MAXN],cnt,res[3][MAXN];
ll f[35][2][2];
struct rec{
	int l,r;
} a[MAXN];
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
ll dfs(int d,int oe,int lim,ll aim){
	if (d==-1) return oe==0;
	if (f[d][oe][lim]) return f[d][oe][lim];
	int ub=1,bin=(aim>>d)&1;
	if (lim){
		if (bin){
			f[d][oe][1]+=dfs(d-1,oe^1,1,aim)+dfs(d-1,oe,0,aim);
		}
		else {
			f[d][oe][1]+=dfs(d-1,oe,1,aim);
		}
	}
	else {
		f[d][oe][0]+=dfs(d-1,0,0,aim)+dfs(d-1,1,0,aim);
	}
	return f[d][oe][lim];
}
bitset<35> t;
bool check(ll x,int o){
	t=x;
	return !((t.count()&1)^o);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,y; scanf("%d%d",&x,&y);
		a[i]=(rec){x,y};
		b[++cnt]=x; b[++cnt]=y;
	}
	sort(b+1,b+cnt+1);
	cnt=unique(b+1,b+cnt+1)-b-1;
	res[0][0]=1; res[1][0]=0;
	for (int i=1;i<=cnt;i++){
		memset(f,0,sizeof(f));
		res[0][i]=dfs(31,0,1,b[i]);
		res[1][i]=dfs(31,1,1,b[i]);
		memset(f,0,sizeof(f));
		res[0][i]-=dfs(31,0,1,b[i-1]);
		res[1][i]-=dfs(31,1,1,b[i-1]);
		fa[i]=i;
	}
	fa[cnt+1]=cnt+1;
	ll ans0,ans1;
	for (int i=1;i<=n;i++){
		int l=a[i].l,r=a[i].r;
		l=lower_bound(b+1,b+cnt+1,l)-b;
		r=lower_bound(b+1,b+cnt+1,r)-b;
		l=find(l+1);
		while (l<=r){
			if (fa[l-1]==l-1&&l!=1){
				ans0+=check(b[l-1],0);
				ans1+=check(b[l-1],1);
			}
			if (fa[l+1]!=l+1){
				ans0-=check(b[l],0);
				ans1-=check(b[l],1);
			}
			ans0+=res[0][l];
			ans1+=res[1][l];
			fa[l]=l+1;
			l=find(l);
		}
		printf("%lld\n",ans0*ans1);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}

