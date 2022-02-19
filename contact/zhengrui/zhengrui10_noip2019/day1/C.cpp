#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=6e5+5;
const int MAXT=MAXN*32;
int t[MAXT][2],f[MAXT],d[MAXT],tag;
int ext[MAXT];
int n,M,T,rt;
int st[35],top;
int ans[MAXN],cnt;
queue<int> q;
int read(){
	int ret=0; char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret;
}
void ins(int x,int val){
	int u=rt;
	for (int i=0;i<30;i++){
		int tmp=x&1;
		if (t[u][tmp]) u=t[u][tmp];
		else u=t[u][tmp]=++M;
		x>>=1;
	}
	ext[u]+=val;
}
void chg(int x){
	int u=rt; top=0;
	for (int i=0;i<=30;i++){
		st[++top]=u;
		int tmp=x&1;
		if (t[u][tmp]) u=t[u][tmp];
		else break;
		x>>=1;
	}
	while (top){
		int x=st[top--];
		swap(t[x][0],t[x][1]);
	}
}
/*void prt(){
//	cout<<"------------------"<<endl;
	cnt=0;
	q.push(rt); f[rt]=0; d[rt]=-1;
	while (!q.empty()){
		int u=q.front(); q.pop();
		int fl=0;
		for (int i=0;i<=1;i++){
			int v=t[u][i];
			if (!v){
				fl++;
				continue;
			}
			d[v]=d[u]+1;
			f[v]=f[u]+(1<<d[v])*i;
			q.push(v);
		}
		if (ext[u]) for (int i=1;i<=ext[u];i++) ans[cnt++]=f[u]^tag;
	}
	sort(ans,ans+cnt);
	for (int i=0;i<cnt;i++) printf("%d ",ans[i]);
//	cout<<"-------------"<<endl;
}*/
void dfs(int u,int d,int x){
	if (d==30){
		for (int i=1;i<=ext[u];i++) ans[cnt++]=x^tag;
		return;
	}
	if (t[u][0]) dfs(t[u][0],d+1,x);
	if (t[u][1]) dfs(t[u][1],d+1,x+(1<<d));
	return;
}
void prt(){
	cnt=0;
	dfs(rt,0,0);
	sort(ans,ans+cnt);
	for (int i=0;i<cnt;i++) printf("%d ",ans[i]);
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	n=read(); T=read();
	for (int i=1;i<=n;i++){
		int x; x=read();
		ins(x,1);
	}
//	prt();
	for (int i=1;i<=T;i++){
//		cout<<i<<endl;
		int op,x; op=read();
		if (op==1) x=read(),ins(x^tag,1);
		if (op==2) x=read(),ins(x^tag,-1);
		if (op==3) chg(((1<<30)-1)^tag);
		if (op==4) x=read(),tag^=x;
//		prt();
	}
	prt();
	fclose(stdin); fclose(stdout);
	return 0;
}
