#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
int a[MAXN][MAXN],b[MAXN][MAXN];
int n,m,tot;
bool check(int r,int c){
	if (tot%(r*c)!=0) return 0;
	else{
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++) b[i][j]=a[i][j];
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
			if (b[i][j]){
				int t=b[i][j];
				for (int q=0;q<r;q++){
					for (int w=0;w<c;w++){
						if (i+q>n||j+w>m) return 0;
						b[i+q][j+w]-=t;
						if (b[i+q][j+w]<0) return 0;
					}
				}
			}
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				if (b[i][j]) return 0;
			}
		}
		return 1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]),tot+=a[i][j];
	}
	int ans=1e9;
	for (int r=1;r<=n;r++){
		for (int c=1;c<=m;c++){
			if (check(r,c)) ans=min(ans,tot/(r*c));
		}
	}
	printf("%d\n",ans);
	return 0;
i
