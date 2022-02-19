#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int a[MAXN][MAXN];
int n,m,q;
int main(){
	freopen("seg.in","r",stdin);
	freopen("seg1.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	for (int i=1;i<=q;i++){
		int op,sx,sy,tx,ty,val;
		scanf("%d%d%d%d%d",&op,&sx,&sy,&tx,&ty);
		if (sx>tx) swap(sx,tx),swap(sy,ty);
		if (op==1){
			scanf("%d",&val);
			a[sx][sy]+=val;
		}
		else {
			int sum=0;
			for (int i=sx;i<=tx;i++){
				for (int j=sy;j<=ty;j++){
					sum+=a[i][j];
				}
			}
			printf("%d\n",sum);
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
