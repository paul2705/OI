#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e4+5;
const int MAXM=5e3+5;
struct rec{
	int l,r,c;
} a[MAXM];
int n,m,ans,use[MAXN];
bool cmp(rec a,rec b){ return a.r==b.r?a.l<b.l:a.r<b.r; }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].c);
	sort(a+1,a+m+1,cmp);
	for (int i=1;i<=m;i++){
		int res=0;
		for (int j=a[i].l;j<=a[i].r;j++){
			if (use[j]) res++;
		}
		if (res>=a[i].c) continue;
		else for (int j=a[i].r;j>=(a[i].r-a[i].c+1)&&res<a[i].c;j--){
			if (!use[j]) use[j]=1,ans++,res++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
