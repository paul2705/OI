#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=1e2+5;
int s[MAXN][MAXM];
int h[MAXN];
int n,m,ans;
int nxt[MAXN];
int solve(int n){
	nxt[0]=-1;
	for (int i=1;i<=n;i++){
		int pre=nxt[i-1];
		while (pre>=0&&h[pre+1]!=h[i]) pre=nxt[pre];
		nxt[i]=pre+1;
	}
	return n-nxt[n];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c<'A'||c>'Z') c=getchar();
			s[i][j]=c;
			h[i]=h[i]*27+c-'A';
		}
	}
	ans=solve(n);
	for (int i=1;i<=m;i++){
		h[i]=0;
		for (int j=1;j<=n;j++){
			h[i]=h[i]*27+s[j][i]-'A';
		}
	}
	ans*=solve(m);
	printf("%d\n",ans);
	return 0;
}
