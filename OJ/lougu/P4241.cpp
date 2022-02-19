#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
const int mod=19260817;
struct rec{
	int k,d;
} a[MAXN];
int n,m,tot,cur,ans;
int dp[3][MAXN];
inline int Add(int x){ return x%mod; }
void ins(int k,int w){
	int sum,h;
	for (int d=0;d<=w-1;d++){
		sum=h=0;
		for (int j=0;j<=(m-d)/w;j++){
			sum=Add(sum+dp[cur^1][j*w+d]);
			if (h<j-k) sum=Add(sum-dp[cur^1][(h++)*w+d]+mod);
			dp[cur][j*w+d]=sum;
		}
	}
}
bool cmp(rec a,rec b){ return a.d>b.d; }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].k,&a[i].d),tot+=a[i].k*a[i].d;
	if (tot<=m) return printf("1\n"),0;
	sort(a+1,a+n+1,cmp);
	dp[0][0]=1;
	for (int i=1;i<=n;i++){
		tot-=a[i].k*a[i].d;
		cur^=1;
		ins(a[i].k-1,a[i].d);
		for (int j=max(m-tot-a[i].d+1,0);j<=m-tot;j++) ans=Add(ans+dp[cur][j]);
		ins(a[i].k,a[i].d);
	}
	printf("%d\n",ans);
	return 0;
}
