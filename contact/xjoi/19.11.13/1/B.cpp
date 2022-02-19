#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int MAXN=2e6+6;
int head[MAXN],nex[MAXN],pre[MAXN],ed[MAXN];
int n,m,M;
ll a[MAXN],tag[MAXN],sz[MAXN];
int main(){
	freopen("problem2.in","r",stdin);
	freopen("problem2.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) head[i]=0;
	for (int i=1;i<=m;i++){
		int op,x; scanf("%d%d",&op,&x);
//		cout<<i<<" ; "<<endl;
		head[0]=nex[0]=pre[0]=ed[0]=0;
		if (op==1){
			ll tmp,t=tag[x]; scanf("%lld",&tmp);
			M++;
			if (head[x]==0) ed[x]=M;
			nex[M]=head[x],pre[head[x]]=M,head[x]=M,a[M]=(tmp-t+mod)%mod;
			sz[x]++;
		}
		if (op==2){
			ll tmp=a[head[x]],t=tag[x]; 
			if (head[x]==0) t=tag[x]=0;
			printf("%lld\n",(tmp%mod+t%mod+mod)%mod);
			head[x]=nex[head[x]]; pre[head[x]]=0;
			if (head[x]==0) ed[x]=0;
			sz[x]=max(0ll,sz[x]-1);
			if (sz[x]==0) tag[x]=0;
		}
		if (op==3){
			ll tmp,t=tag[x]; scanf("%lld",&tmp);
			M++; sz[x]++;
			if (ed[x]==0) head[x]=M;
			a[M]=(tmp-t+mod)%mod; pre[M]=ed[x];
			nex[ed[x]]=M; ed[x]=M;
			nex[M]=0;
		}
		if (op==4){
			ll tmp=a[ed[x]],t=tag[x]; 
			if (ed[x]==0) t=tag[x]=0;
			printf("%lld\n",(tmp%mod+t%mod+mod)%mod);
			ed[x]=pre[ed[x]]; nex[ed[x]]=0;
			if (ed[x]==0) head[x]=0;
			sz[x]=max(0ll,sz[x]-1);
			if (sz[x]==0) tag[x]=0;
		}
		if (op==5){
			ll tmp; scanf("%lld",&tmp);
			tag[x]=(tag[x]+tmp)%mod;
		}
		if (op==6){
			ll y; scanf("%lld",&y);
//			cout<<x<<" "<<sz[x]<<" "<<y<<" "<<sz[y]<<endl;
			if (sz[x]>sz[y]){
				ll t1=tag[y],t2=tag[x];
				if (head[y]==0&&ed[y]==0) continue;
				for (int j=head[y];j>0;j=nex[j]){
					nex[ed[x]]=j;
					pre[j]=ed[x];
					ed[x]=j;
					a[j]=(a[j]+t1-t2)%mod;
				}
				tag[y]=0;
				head[y]=0; ed[y]=0;
				sz[x]+=sz[y]; sz[y]=0;
			}
			else {
				ll t1=tag[y],t2=tag[x];
				if (!(head[x]==0&&ed[x]==0)){
//					cout<<ed[x]<<" "<<a[ed[x]]<<endl;
					for (int j=ed[x];j>0;j=pre[j]){
						pre[head[y]]=j;
						nex[j]=head[y];
						head[y]=j;
						a[j]=(a[j]+t2-t1)%mod;
					}
				}
				head[x]=head[y];
				ed[x]=ed[y];
				head[y]=0; ed[y]=0;
				tag[x]=tag[y];
				sz[x]+=sz[y]; sz[y]=0;
				tag[y]=0;
			}
		}
/*		cout<<endl;
		cout<<i<<endl;
		for (int j=1;j<=n;j++){
			printf("%d: ",j);
			ll tmp=tag[j];
			for (int e=head[j];e;e=nex[e]){
				ll v=a[e];
				printf("%lld ",(v+tmp)%mod);
			}
			printf("head:%d end:%d",head[j],ed[j]);
			printf("\n");
		}
		cout<<endl;
*/	}
	fclose(stdin); fclose(stdout);
	return 0;
}
