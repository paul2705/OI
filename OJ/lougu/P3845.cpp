#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int T,n,f[MAXN],ans;
struct rec{
	int a,b;
} s[MAXN];
bool cmp(rec a,rec b){ return a.b==b.b?a.a<b.a:a.b<b.b; }
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		memset(s,0,sizeof(s)); memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++){
			scanf("%d-%d",&s[i].a,&s[i].b);
			if (s[i].a>s[i].b) swap(s[i].a,s[i].b);
		}
		sort(s+1,s+n+1,cmp);
		ans=0;
		f[++ans]=s[1].a;
		for (int i=2;i<=n;i++){
			int p=0;
			for (int j=1;j<=ans;j++){
				if (s[i].a>=f[j]&&f[p]<=f[j]) p=j;
			}
			if (!p) f[++ans]=s[i].a; 
			else f[p]=s[i].a;
		}
		printf("%d\n",ans);
	}
	return 0;
}
