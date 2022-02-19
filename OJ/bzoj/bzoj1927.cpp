#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define inf 1000000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,T,cnt=1,ans;
int a[1605],last[1605],q[1605],dis[1605],from[1605];
bool inq[1605];
struct data{int to,next,from,v,c;}e[3000005];
void ins(int u,int v,int w,int c){
	e[++cnt].to=v;e[cnt].next=last[u];e[cnt].from=u;last[u]=cnt;e[cnt].v=w;e[cnt].c=c;
}
void insert(int u,int v,int w,int c){
	ins(u,v,w,c);
	ins(v,u,0,-c);
}
bool spfa(){
	for(int i=0;i<=T;i++)dis[i]=inf;
	int head=0,tail=1;
	dis[0]=0;q[0]=0;inq[0]=1;
	while(head!=tail){
		int now=q[head++];if(head==1601)head=0;
		for(int i=last[now];i;i=e[i].next)
			if(e[i].v&&e[i].c+dis[now]<dis[e[i].to]){
				dis[e[i].to]=e[i].c+dis[now];
				from[e[i].to]=i;
				if(!inq[e[i].to]){
					inq[e[i].to]=1;
					if(dis[e[i].to]<dis[q[head]]){
						head--;if(head==-1)head=1600;
						q[head]=e[i].to;
					}
					else{
						q[tail++]=e[i].to;
						if(tail==1601)tail=0;
					}
				}
			}
		inq[now]=0;
	}
	if(dis[T]==inf)return 0;
	return 1;
}
void mcf(){
	int x=inf;
	for(int i=from[T];i;i=from[e[i].from])
		x=min(e[i].v,x);
	for(int i=from[T];i;i=from[e[i].from]){
		ans+=x*e[i].c;
		e[i].v-=x;e[i^1].v+=x;
	}
}
int main(){
	n=read();m=read();T=2*n+1;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		insert(0,i,1,0);
		insert(i+n,T,1,0);
		insert(0,i+n,1,a[i]);
	}
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		if(u>v)swap(u,v);
	    insert(u,v+n,1,w);
	}		
	while(spfa())mcf();
	printf("%d\n",ans);
	return 0;
}
