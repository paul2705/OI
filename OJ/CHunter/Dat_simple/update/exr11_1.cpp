#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int cnt[MAXN];
char a[MAXN],b[MAXN];
int n,m,q;
int nxt[MAXN],lis[MAXN];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s",a+1);
	scanf("%s",b+1); 
	nxt[0]=-1;
	for (int i=1;i<=m;i++){
		int pre=nxt[i-1];
		while (pre>=0&&b[pre+1]!=b[i]) pre=nxt[pre];
		nxt[i]=pre+1;
	}
	int stp=0;
	for (int i=1;i<=n;i++){
		if (a[i]==b[stp+1]) stp++;
		else{
			while (stp>=0&&a[i]!=b[stp+1]) stp=nxt[stp];
			stp++;
		}
		cnt[stp]++;
	}
	for (int i=n;i>=1;i--) cnt[nxt[i]]+=cnt[i];
	for (int i=1;i<=q;i++){
		int x; scanf("%d",&x);
		printf("%d\n",cnt[x]-cnt[x+1]);
	}
	return 0;
}
