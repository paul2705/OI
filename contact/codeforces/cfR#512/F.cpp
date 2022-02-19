#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
struct rec{
	int l,r,id;
} ask[MAXN];
int n,m,k,T;
int a[MAXN],ans[MAXN];
bool cmp(rec a,rec b){ return a.r<b.r; }
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&T);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d%d",&ask[i].l,&ask[i].r),ask[i].id=i;
	sort(ask+1,ask+m+1,cmp);
	int l
	for (int i=1;i<=m;i++){

