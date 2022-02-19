#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
const int MAXM=1e6+6;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int T,n,m,a[MAXN],col[MAXN];
int mn[MAXN];
int s1[MAXN],top1;
int s2[MAXN],top2;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
bool color(int u,int c){
	col[u]=c;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (col[v]==col[u]) return 0;
		if (!col[v]){
			if (!color(v,3-c)) return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d",&T);
	while (T--){
		bool fl=0;
		edge=0; memset(head,0,sizeof(head));
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		mn[n+1]=n+1;
		for (int i=n;i>=1;i--) mn[i]=min(mn[i+1],a[i]);
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				if (a[i]<a[j]&&mn[j]<a[i]) add(i,j),add(j,i);
			}
		}
		for (int i=1;i<=n;i++) col[i]=0;
		for (int i=1;i<=n;i++){
			if (!col[i]){
				if (!color(i,1)){
					printf("0\n");
					fl=1;
					break;
				}
			}
		}
		if (fl) continue;
		int now=1;
		for (int i=1;i<=n;i++){
			if (col[i]==1) s1[++top1]=a[i],printf("a ");
			else s2[++top2]=a[i],printf("c ");
			while (s1[top1]==now||s2[top2]==now){
				if (s1[top1]==now) top1--,printf("b ");
				else top2--,printf("d ");
				now++;
			}
		}
		printf("\n");
	}
	return 0;
}
