#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int n,m,q,a[MAXN][MAXN];
struct rec{
	int x,y,a;
} res[MAXN*2][MAXN];
int cnt[MAXN][MAXN];
bool f=1;
bool cmp(rec a,rec b){ return a.a>b.a; }
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			if (a[i][j]!=n*(i-1)+j) f=0;
			res[i][j]=(rec){i,j,a[i][j]};
			res[n+j][i]=(rec){i,j,a[i][j]};
		}
	}
	for (int i=1;i<=n;i++) sort(res[i]+1,res[i]+m+1,cmp);
	for (int i=n+1;i<=n+m;i++) sort(res[i]+1,res[i]+n+1,cmp);
	if (q>400){
		for (int x=1;x<=m;x++){
			for (int y=1;y<=n;y++){
				for (int i=1;i<=n;i++){
				//	int pos=find(i,res[i][x]);
				//	cout<<i<<" "<<res[i][x]<<" "<<pos<<endl;
					if (res[n+res[i][x].y][y].a==res[i][x].a) cnt[x][y]++;
				}
			}
		}
	}
	for (int i=0,x,y;i<q;i++){
		int ans=0;
		scanf("%d%d",&x,&y);
	//	printf("%d\n",cnt[x][y]);
		if (f){ printf("1\n"); continue; }
		if (q>400){ printf("%d\n",cnt[x][y]); continue; }
		for (int j=1;j<=n;j++){
			for (int k=1;k<=m;k++){
				if (res[j][x].a==res[n+k][y].a) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
