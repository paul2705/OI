#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e7+7;
int pri[MAXN];
bool use[MAXN],upr[MAXN];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	use[1]=1;
	for (int i=2;i<=n;i++){
		if (!use[i]){
			pri[++pri[0]]=i;
			upr[i]=1;use[i]=1;
		}
		for (int j=1;i*pri[j]<=n&&j<=pri[0];j++){
//			if (i%pri[j]==0) break;
			use[i*pri[j]]=1;
			if (i%pri[j]==0) break;
		}
	}
	for (int i=1,x;i<=m;i++){
		scanf("%d",&x);
		if (upr[x]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
