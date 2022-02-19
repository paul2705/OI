#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e2+5;
int w[MAXN][MAXN],ans;
int n,m,a,b,l,r,mid;
bool check(int x){
	int sum=0,now=0;
	for (int i=1;i<=n;i++){
		int res=0,s=0;
		for (int j=1;j<=m;j++){
			if (s+w[i][j]-w[i][j-1]-w[now][j]+w[now][j-1]<x){
				s+=w[i][j]-w[i][j-1]-w[now][j]+w[now][j-1];
			}
			else res++,s=0;
		}
		if (res>=b) sum++,now=i;
	}
	return sum>=a;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			scanf("%d",&w[i][j]);
			w[i][j]+=w[i-1][j]+w[i][j-1]-w[i-1][j-1];
		}
	}
	l=0,r=w[n][m];
	while (l+1<r){
		int mid=(l+r)>>1;
		if (check(mid)) l=mid;
		else r=mid;
	}
	printf("%d\n",l);
	return 0;
}
