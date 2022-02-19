#include<cstdio>
#define N 100010
int n,m,k,t,pwr[21],a[N],b[N],c[N],f[N][21],dep[N];
int fir[N],nex[N<<1],nod[N<<1],fst[N],nxt[N<<1],nde[N<<1];
int que[N],deg[N],num[N],edg[N];
int read(){
	int ret=0,c=getchar();
	while(c<48||57<c) c=getchar();
	while(47<c&&c<58) ret=ret*10+c-48,c=getchar();
	return ret;
}
void add(int x,int y){nod[++k]=y,nex[k]=fir[x],fir[x]=k;}
void add1(int x,int y){deg[y]++,nde[++k]=y,nxt[k]=fst[x],fst[x]=k;}
void DFS(int u,int fa){
	f[u][0]=fa,dep[u]=dep[fa]+1;
	for(int i=1;pwr[i]<dep[i];i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=fir[u];i;i=nex[i]) if(nod[i]!=fa) DFS(nod[i],u);
}
int getl(int u,int v){
	if(dep[u]<dep[v]) return getl(v,u); int ret=0;
	for(int i=20;i>=0;i--)
		if(dep[f[u][i]]>=dep[v]) ret+=i,u=f[u][i];
	for(int i=20;i>=0;i--)
		if(f[u][i]!=f[v][i]) ret+=i<<1,u=f[u][i],v=f[v][i];
	return u==v?ret:ret+2;
}
void geta(int u,int v,int x){
	if(!u) return;
	if(dep[u]<dep[v]){geta(v,u,x);return;}
	for(int i=1;i<=m;i++) num[i]=0;
	for(;dep[u]>dep[v];u=f[u][0])
		if(!num[a[u]]&&a[u]!=x) num[a[u]]=1,add1(a[u],x);
	for(;u!=v;u=f[u][0],v=f[v][0]){
		if(!num[a[u]]&&a[u]!=x) num[a[u]]=1,add1(a[u],x);
		if(!num[a[v]]&&a[v]!=x) num[a[v]]=1,add1(a[v],x);
	}
	if(u!=v){
		u=f[u][0];
		if(!num[a[u]]&&a[u]!=x) num[a[u]]=1,add1(a[u],x);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	for(int i=pwr[0]=1;i<=20;i++) pwr[i]=pwr[i-1]<<1;
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read(),b[a[i]]=c[a[i]]=i;
	for(int i=1,x,y;i<n;i++) add(x=read(),y=read()),add(y,x);
	k=0,DFS(1,0);
	for(int i=1,u,x;i<=n;i++){
		x=a[i],u=(getl(b[x],i)>getl(c[x],i)?b[x]:c[x]);
		if(getl(u,i)>getl(b[x],c[x])) b[x]=u,c[x]=i;
	}
	for(int i=1;i<=m;i++) edg[b[i]]=edg[c[i]]=1;
	for(int i=1;i<=m;i++) geta(b[i],c[i],i);
	for(int i=1;i<=m;i++) if(!deg[i]) que[++t]=i;
	for(int h=1,u;h<=m;h++)
		for(int i=fst[u=que[h]];i;i=nxt[i])
		if(!--deg[nde[i]]) que[++t]=nde[i];
	for(int i=1;i<=m;i++) printf("%d %d %d\n",que[i],b[que[i]],c[que[i]]);
	return 0;
}
