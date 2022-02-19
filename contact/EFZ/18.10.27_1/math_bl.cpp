#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=25;
int n,m,cnt[MAXN];
bool use[MAXN];
int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int s=0;s<(1<<n);s++){
		int res=0; bool f=1;
		for (int i=1;i<=2*n;i++) use[i]=0;
		for (int i=0;i<n;i++){
			if (s&(1<<i)) res++,use[i+1]=1;
		}
		for (int i=1;i<=n;i++){
			if (use[i]==1&&use[i*2]==1) f=0;
		}
		for (int i=1;i<=n;i++){
			if (use[i]==0){
				if (i*2<=n&&use[i*2]==0) f=0;
			}
		}
		if (f) cnt[res]++;
	}
	for (int i=1,x;i<=m;i++){
		scanf("%d",&x);
		printf("%d\n",cnt[x]);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
