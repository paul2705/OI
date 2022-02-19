#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long LL;
#define foru(i,a,b) for(LL i=a;i<=b;i++)
#define ford(i,a,b) for(LL i=a;i>=b;i--)
const LL N=100005;
LL head[N],d[N],a[3][N],ans[N],fans[N],vans[N];
LL n,ne,a1,a2,sum,mins,fa;
struct edge{LL to,nxt;}e[N<<1];
void add(LL a,LL b){
	e[++ne]=(edge){b,head[a]};head[a]=ne;
}
int main(){
	LL u,v;
	ne=0;
	memset(d,0,sizeof(d));
	scanf("%I64d",&n);
	foru(j,0,2)foru(i,1,n)scanf("%I64d",&a[j][i]);
	foru(i,1,n-1){
		scanf("%I64d%I64d",&u,&v);
		d[u]++;d[v]++;
		if(d[u]>2||d[v]>2){printf("-1\n");return 0;}
		add(u,v);add(v,u);
	}
	mins=9223372036854775807;
	foru(i,1,n)if(d[i]==1){a1=i;break;}
	a2=e[head[a1]].to;
	foru(i,0,2){
		ans[1]=vans[a1]=i;
		foru(j,0,2){
			if(i==j)continue;
			ans[2]=vans[a2]=j;
			sum=a[i][a1]+a[j][a2];
			u=a2;fa=a1;
			foru(k,3,n){
				for(LL l=head[u];l;l=e[l].nxt){
					v=e[l].to;
					if(v==fa)continue;
					ans[k]=vans[v]=3-ans[k-1]-ans[k-2];
					sum+=a[ans[k]][v];
					fa=u;u=v;
					break;
				}
			}
			if(sum<mins){
				foru(k,1,n)fans[k]=vans[k];
				mins=sum;
			}
		}
	}
	printf("%I64d\n",mins);
	foru(i,1,n)printf("%I64d ",fans[i]+1);
}
