#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=1e2+5;
int n,m,q,a[MAXN][MAXM];
int cnt[MAXM],ret,ans;
bool cmp(int a,int b){ return a>b; }
int main(){
	while (~scanf("%d%d%d",&n,&m,&q)){
	ans=0; ret=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]),ans+=a[i][j]==0;
	}
	for (int i=2;i<=n;i++){
		if (a[i][1]==0&&a[i][2]==0){
			int las=0;
			for (int j=m;j>0;j--){
				if (a[i-1][j]==1) break;
				else las++;
			}
			cnt[ret++]=las+2;
		}
	}
	sort(cnt,cnt+ret,cmp);
	for (int i=0;i<q-1;i++) ans-=cnt[i];
	for (int i=m;i>0;i--){
		if (a[n][i]==1) break;
		else ans--;
	}
	printf("%d\n",ans-2);
	}
	return 0;
}
