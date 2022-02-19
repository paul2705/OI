#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int n,num,minn,kc,ff,c[50001],t,w;
map<int,int> a;
struct rec{
	int k,id;
} f[50001],q[50001];
bool cmp(rec a,rec b){ return a.k<b.k; }
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&f[i].k,&kc);
		if (!a.count(kc)) a[kc]=++ff;
		f[i].id=a[kc];
	}
	sort(f+1,f+n+1,cmp);
	q[1].k=f[1].k; q[1].id=f[1].id;
	c[f[1].id]++; num=t=w=1;
	for (int i=2;i<=n;i++){
		if (!c[f[i].id]){ num++; c[f[i].id]=1; }
		else c[f[i].id]++;
		w++;
		q[w].k=f[i].k; q[w].id=f[i].id;
		while (c[q[t].id]>1){ c[q[t].id]--; t++; }
		if (num==ff) minn=min(minn,q[w].k-q[t].k);
	}
	printf("%d\n",minn);
	return 0;
}
