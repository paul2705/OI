#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const int MAXM=5e4+5;
const int MAXP=1e3+5;
ll f[MAXM][MAXP];
int n,m,p,d[MAXN];
struct rec{
	int h,t;
	ll val;
} a[MAXM];
bool cmp(rec a,rec b){ return a.val<b.val; }
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for (int i=2;i<=n;i++){
		scanf("%d",&d[i]);
		d[i]+=d[i-1];
	}
	for (int i=1;i<=m;i++){
		scanf("%d%d",&a[i].h,&a[i].t);
		a[i].val=a[i].t-d[a[i].h];
	}
	sort(a+1,a+m+1,cmp);
	for (int i=0;i<=m;i++){
		for (int j=0;j<=p;j++) f[i][j]=1e15;
	}
	f[0][0]=0;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=p;j++){
			ll res=0,tmp=a[i].val;
			ll ret=1e15;
			for (int k=i-1;k>=0;k--){
				res+=tmp-a[k+1].val;
				ret=min(ret,f[k][j-1]+res);
//				cout<<res<<" "<<f[k][j-1]<<" "<<ret<<endl;
			}
			f[i][j]=ret;
			cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
//			cout<<endl;
		}
	}
	printf("%lld\n",f[m][p]);
	return 0;
}
