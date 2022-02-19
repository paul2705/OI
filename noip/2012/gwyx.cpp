#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
const int MAXS=2e5+5;
struct rec{
	ll x,y,key;
} a[MAXN];
ll n,ans[MAXS],sum[MAXS],ret[MAXS];
bool cmp(rec a,rec b){ return a.key<b.key; }
void mul(ll x){
//	cout<<__func__<<endl;
	ll k=0; //cout<<"mulx: "<<x<<endl;
	for (int i=1;i<=sum[0];i++){
//		cout<<"mul: "<<sum[i]<<" "<<k<<endl;
		sum[i]=sum[i]*x+k;
		k=sum[i]/10; sum[i]%=10;
	}
//	cout<<"mul: "<<k<<endl;
	while (k>0) sum[++sum[0]]=k%10,k/=10;
}
void div(ll x){
//	cout<<__func__<<endl;
	ll res=x,cnt=0;
	while (res>0) cnt++,res/=10;
	ll k=0,r=sum[0]; cnt--;
//	cout<<"fuck"<<endl;
//	cout<<r<<" "<<cnt<<endl; 
	while (cnt>0) k=k*10+sum[r],r--,cnt--;
	ret[0]=0; int las=r;
	for (;r>=1;r--){
		k=k*10+sum[r];
//		cout<<"divp: "<<k<<endl;
		if (r!=las||(k>=x)) ret[++ret[0]]=k/x;
		k=k%x;
	}
	for (int i=1,j=ret[0];i<j;i++,j--) swap(ret[i],ret[j]);
//	for (int i=1;i<=ret[0];i++) sum[i]=ret[i];
//	sum[0]=ret[0];
}
void cp(){
//	cout<<__func__<<endl;
//	cout<<"cp: "<<ret[0]<<" "<<ans[0]<<endl;
	if (ret[0]<ans[0]) return;
	if (ret[0]>ans[0]){
		ans[0]=ret[0];
		for (int i=1;i<=ret[0];i++) ans[i]=ret[i];
		return;
	}
	bool f=0;
	for (int i=ret[0];i>=1;i--){
//		cout<<ret[i]<<" "<<ans[i]<<endl;
		if (ret[i]>ans[i]){
			f=1;
			break;
		}
		if (ret[i]<ans[i]) break;
	}
	if (f) for (int i=1;i<=ret[0];i++) ans[i]=ret[i];
}
int main(){
	freopen("gwyx.in","r",stdin);
	freopen("gwyx.out","w",stdout);
	scanf("%lld",&n);
	for (int i=0;i<=n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].key=a[i].x*a[i].y;
	}
	sort(a+1,a+n+1,cmp);
	sum[1]=1; ans[0]=sum[0]=1;
	for (int i=1;i<=n;i++){
		mul(a[i-1].x);
		div(a[i].y);
		cp();
//		cout<<"sum: ";
//		for (int i=sum[0];i>=1;i--) printf("%lld",sum[i]);
//		cout<<endl<<"ans: ";
//		for (int i=ans[0];i>=1;i--) printf("%lld",ans[i]);
//		cout<<endl;
	}
	for (int i=ans[0];i>=1;i--) printf("%lld",ans[i]);
	cout<<endl;
	return 0;
}
