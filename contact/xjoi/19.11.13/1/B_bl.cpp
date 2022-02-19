#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int MAXN=1e3+5;
ll a[MAXN][MAXN],cnt[MAXN];
int n,m;
int main(){
	freopen("problem2.in","r",stdin);
	freopen("problem2.ans","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int op,x; scanf("%d%d",&op,&x);
		if (op==1){
			ll tmp; scanf("%lld",&tmp);
			tmp%=mod;
			for (int i=cnt[x];i>=1;i--){
				swap(a[x][i+1],a[x][i]);
			}
			a[x][1]=tmp; cnt[x]++;
		}
		if (op==2){
			ll tmp=a[x][1]; 
			if (!cnt[x]) tmp=0;
			printf("%lld\n",(tmp%mod+mod)%mod);
			for (int i=1;i<=cnt[x];i++){
				swap(a[x][i],a[x][i+1]);
			}
			cnt[x]=max(0ll,cnt[x]-1);
		}
		if (op==3){
			ll tmp; scanf("%lld",&tmp);
			tmp%=mod;
			a[x][++cnt[x]]=tmp;
		}
		if (op==4){
			ll tmp=a[x][cnt[x]--]; printf("%lld\n",(tmp%mod+mod)%mod);
			cnt[x]=max(0ll,cnt[x]);
		}
		if (op==5){
			ll tmp; scanf("%lld",&tmp);
			for (int i=1;i<=cnt[x];i++) a[x][i]=((a[x][i]+tmp)%mod+mod)%mod;
		}
		if (op==6){
			ll y; scanf("%lld",&y);
			for (int i=1;i<=cnt[y];i++) a[x][++cnt[x]]=a[y][i];
			cnt[y]=0;
		}
/*		cout<<endl;
		cout<<i<<endl;
		for (int j=1;j<=n;j++){
			printf("%d: ",j);
			for (int k=1;k<=cnt[j];k++) printf("%lld ",a[j][k]);
			printf("\n");
		}
		cout<<endl;
*/	}
	fclose(stdin); fclose(stdout);
	return 0;
}
