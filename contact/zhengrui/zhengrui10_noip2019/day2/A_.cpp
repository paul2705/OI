#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
int n,m;
char a[MAXN],b[MAXN];
int ans[MAXN],tot;
int s[MAXN],top;
int res[MAXN],use[MAXN],tp;
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",a+1);
	scanf("%s",b+1);
	int now=1;
	for (int i=1;i<=n;++i){
		if (now>m) break;
		if (b[now]==a[i]){
			s[++top]=i;
			use[i]=1; now++;
		}
	}
	for (int i=1;i<=n;i++){
		if (a[i]!=a[i+1]&&i!=n) res[++tp]=i;
	}
	for (int i=tp;i>0;i--){
		int x=res[i];
		if (use[x]||use[x+1]) continue;
		if (!top) return printf("-1\n"),0;
		if (a[x]==a[s[top]]) use[s[top--]]=0,use[x]=1;
		else use[x+1]=1,use[s[top--]]=0;
	}
	for(int i=1;i<=n;++i){
		if (use[i]) printf("%d ",i);
	}
	printf("\n");
	return 0;
}
