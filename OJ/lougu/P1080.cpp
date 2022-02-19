#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
struct rec{
	int a,b;
} t[MAXN];
int n,ans,mul,x;
bool cmp(rec a,rec b){ return a.a*a.b<b.a*b.b; }
int main(){
	scanf("%d",&n);
	scanf("%d%d",&mul,&x);
	for (int i=1;i<=n;i++) scanf("%d%d",&t[i].a,&t[i].b);
	sort(t+1,t+n+1,cmp);
	for (int i=1;i<=n;i++){
		ans=max(ans,mul/t[i].b);
		mul*=t[i].a;
	}
	printf("%d\n",ans);
	return 0;
}
