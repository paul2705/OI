#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e5+5;
const int MAXM=MAXN*40;
int edge,head[MAXN*8],nex[MAXM],tail[MAXM];
int n,cnt,nxt1[MAXN*40],nxt2[MAXN*40],nxt3[MAXN*40],id3[MAXN*40];
int f[MAXN][20],g[MAXN][20];
// x: A , x+n: B
// f: A , g:   B
int idf[MAXN][20],idg[MAXN][20];
int use[MAXN*40];
int q[MAXN*40],l,r;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
bool check(int x){
	edge=0;
	for (int i=1;i<=2*n;i++) head[i]=0;
	for (int i=1;i<=n;i++){
//		if (n==50000) cout<<i<<" "<<n<<endl;
		int A=i,B=i;
		for (int j=18;j>=0;j--){
			if (x&(1<<j)){
				add(i+n,idf[A][j]); A=f[A][j];
				add(i,idg[B][j]); B=g[B][j];
			}
		}
	}
	for (int i=1;i<=cnt;i++) use[i]=0;
//	cout<<"done"<<endl;
	l=r=0;
	use[1]=use[n+1]=1;
	q[++r]=1; q[++r]=n+1;
	while (l<r){
		int u=q[++l];
		int tmp1=nxt1[u],tmp2=nxt2[u];
		if (!use[tmp1]) use[tmp1]=1,q[++r]=tmp1;
		if (!use[tmp2]) use[tmp2]=1,q[++r]=tmp2;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (!use[v]) use[v]=1,q[++r]=v;
		}
	}
	return use[n]||use[n+n];
}
int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	scanf("%d",&n); cnt=n+n;
	for (int i=1;i<=n;i++){
		int x,y; scanf("%d%d",&x,&y);
		f[i][0]=x; g[i][0]=y;
		idf[i][0]=x; idg[i][0]=y+n;
	}
	for (int k=1;k<19;k++){
		for (int i=1;i<=n;i++){
			f[i][k]=f[f[i][k-1]][k-1];
			idf[i][k]=++cnt;
			nxt1[cnt]=idf[i][k-1];
			nxt2[cnt]=idf[f[i][k-1]][k-1];
			g[i][k]=g[g[i][k-1]][k-1];
			idg[i][k]=++cnt;
			nxt1[cnt]=idg[i][k-1];
			nxt2[cnt]=idg[g[i][k-1]][k-1];
		}
	}
	int l=-1,r=n+1,mid=0;
	while (l+1<r){
		mid=(l+r)>>1;
//		cout<<l<<" "<<r<<" "<<mid<<endl;
		if (check(mid)) r=mid;
		else l=mid;
	}
	if (r==n+1) printf("-1\n");
	else printf("%d\n",r);
	fclose(stdin); fclose(stdout);
	return 0;
}
