#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define RI register int
int read() {
	int q=0;char ch=' ';
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') q=q*10+ch-'0',ch=getchar();
	return q;
}
typedef long long LL;
const int N=100005;
int n,tot;LL ans,*g[N],*f[N],tmp[N<<2],*id=tmp;
int h[N],ne[N<<1],to[N<<1],len[N],son[N];
void add(int x,int y) {to[++tot]=y,ne[tot]=h[x],h[x]=tot;}
void dfs1(int x,int las) {
	len[x]=1;
	for(RI i=h[x];i;i=ne[i])
		if(to[i]!=las) {
			dfs1(to[i],x);
			if(len[to[i]]>len[son[x]]) len[x]=len[to[i]]+1,son[x]=to[i];
		}
}
void dfs2(int x,int las) {
	if(son[x]) f[son[x]]=f[x]+1,g[son[x]]=g[x]-1,dfs2(son[x],x);
	f[x][0]=1,ans+=g[x][0];
	for(RI i=h[x];i;i=ne[i]) {
		if(to[i]==las||to[i]==son[x]) continue;
		int y=to[i];f[y]=id,id+=len[y]<<1,g[y]=id,id+=len[y]<<1;
		dfs2(y,x);
		for(RI j=0;j<len[y];++j) {
			if(j) ans+=g[y][j]*f[x][j-1];
			if(j+1<len[x]) ans+=f[y][j]*g[x][j+1];
		}
		for(RI j=0;j<len[y];++j) {
			if(j+1<len[x]) g[x][j+1]+=f[y][j]*f[x][j+1];
			if(j) g[x][j-1]+=g[y][j];
			if(j+1<len[x]) f[x][j+1]+=f[y][j];
		}
	}
}
int main(){
	int x,y;
	n=read();
	for(RI i=1;i<n;++i) x=read(),y=read(),add(x,y),add(y,x);
	dfs1(1,0),f[1]=id,id+=len[1]<<1,g[1]=id,id+=len[1]<<1,dfs2(1,0);
	printf("%lld\n",ans);
	return 0;
}
