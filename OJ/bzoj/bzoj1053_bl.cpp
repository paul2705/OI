#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+5;
int n,a[MAXN];
bool use[MAXN];
int pri[MAXN];
int ans;
int main(){
	scanf("%d",&n);
	for (int i=2;i<=n;i++){
		if (!use[i]) pri[++pri[0]]=i;
		for (int j=1;j<=pri[0]&&i*pri[j]<=n;j++){
			use[i*pri[j]]=1;
			if (i%pri[j]==0) break;
		}
	}
	int mx=0;
	for (int i=1;i<=n;i++){
		int tmp=i,ret=1;
		for (int j=1;j<=pri[0];j++){
			if (tmp==1) break;
			int cnt=0;
			while (tmp%pri[j]==0){
				cnt++;
				tmp/=pri[j];
			}
			if (cnt) ret*=(cnt+1);
		}
//		printf("%d: %d %d ",i,ret,mx);
		if (ret>mx){
			printf("%d %d\n",i,ret);
			ans=i;
			mx=ret;
		}
//		else printf("\n");
	}
//	cout<<ans<<endl;
	return 0;
}
