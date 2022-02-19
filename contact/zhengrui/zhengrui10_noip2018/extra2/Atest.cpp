#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,m,ans=0;
int cnt[MAXN];
int main(){
	scanf("%d",&n);
	for (int j=1;j<=n;j++){
		for (int k=j;k<=n;k++){
			memset(cnt,0,sizeof(cnt));
			for (int i=j-1;i;i-=i&-i) cnt[i]--;
//			for (int i=1;i<=m;i++) cout<<cnt[i]<<" ";cout<<endl;
			for (int i=k;i;i-=i&-i) cnt[i]++;
			for (int i=1;i<=k;i++) if (cnt[i]!=0) ans++;
//			cout<<endl;
		}
	}
	printf("%d\n",ans);
	return 0;
}
