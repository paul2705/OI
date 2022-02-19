#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=1e15;
const int MAXN=505;
int n,m;
struct rec{
	int w,s,p;
	// p=1 member
	// p=2 both
	// p=3 captain
} a[MAXN];
bool cmp(rec a,rec b){ return a.w==b.w?a.p<b.p:a.w<b.w; }
ll f[MAXN][MAXN/2][MAXN/2];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].w,&a[i].s,&a[i].p);
		if (a[i].p==1) a[i].p=3;
		else if (a[i].p==2) a[i].p=1;
		else a[i].p=2;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=0;i<=n+1;i++){
		for (int j=0;j<=m+1;j++){
			for (int k=0;k<=m+1;k++) f[i][j][k]=inf;
		}
	}
	f[0][0][0]=0;
	for (int i=1;i<=n;i++){
//		cout<<"i: "<<a[i].w<<" "<<a[i].s<<" "<<a[i].p<<endl;
		for (int j=0;j<=min(i/2,m);j++){
			for (int k=0;k<=min(i,m);k++){
				f[i][j][k]=f[i-1][j][k];
				if (a[i].p==1){ 
					if (k){
//						printf("(%d %d %d,%d) ",i-1,j,k-1,f[i-1][j][k-1]);
						f[i][j][k]=min(f[i][j][k],f[i-1][j][k-1]+a[i].s);
					}
				}
				if (a[i].p==2){
					if (j){
//						printf("(%d %d %d,%d) ",i-1,j-1,k+1,f[i-1][j-1][k+1]);
						f[i][j][k]=min(f[i][j][k],f[i-1][j-1][k+1]+a[i].s);
					}
					if (k){
//						printf("(%d %d %d,%d) ",i-1,j,k-1,f[i-1][j][k-1]);
						f[i][j][k]=min(f[i][j][k],f[i-1][j][k-1]+a[i].s);
					}
				}
				if (a[i].p==3){
					if (j){
//						printf("(%d %d %d,%d) ",i-1,j-1,k+1,f[i-1][j-1][k+1]);
						f[i][j][k]=min(f[i][j][k],f[i-1][j-1][k+1]+a[i].s);
					}
				}
//				cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
			}
		}
	}
	ll ans=inf;
	for (int i=0;i<=m;i++) ans=min(ans,f[n][m][i]);
	printf("%lld\n",ans==inf?-1:ans);
	return 0;
}
