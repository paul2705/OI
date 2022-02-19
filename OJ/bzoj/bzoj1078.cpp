#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
struct rec{
	int cl,cr,fa;
	rec(){ cl=cr=fa=-1; }
	void swp(){ swap(cl,cr); }
} t[MAXN];
int n,rt=0;
int ans[MAXN];
void solve(int id){
	int u=rt;
	while (t[u].cr!=-1) u=t[u].cl;
	int tmp=t[u].cl;
	if (t[tmp].cl==-1&&t[tmp].cr==-1&&tmp!=-1) u=t[u].cl;
	ans[id]=u;
	if (u==rt) rt=t[rt].cl;
	if (t[u].fa!=-1) t[t[u].fa].cl=t[u].cl,t[t[u].cl].fa=t[u].fa;
	while (t[u].fa!=-1){
		t[t[u].fa].swp();
		u=t[u].fa;
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		if (x<100) t[x].cl=i,t[i].fa=x;
		else t[x-100].cr=i,t[i].fa=x-100;
	}
	for (int i=1;i<=n+1;i++) solve(i);
	for (int i=n+1;i>=1;i--) printf("%d ",ans[i]);
	return 0;
}
