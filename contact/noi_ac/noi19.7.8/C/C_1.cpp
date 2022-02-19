#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=3e6+6;
ll mx[MAXN][21],mn[MAXN][21],b[MAXN];
int a[MAXN],n;
int bin[25];
int st[MAXN],top,pre[MAXN],nxt[MAXN];
ll qry_mx(int l,int r){
	int k=log2(r-l+1);
	return max(mx[l][k],mx[r-bin[k]+1][k]);
}
ll qry_mn(int l,int r){
	int k=log2(r-l+1);
	return min(mn[l][k],mn[r-bin[k]+1][k]);
}
int main(){
	freopen("1.in","r",stdin);
	freopen("C_1.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int k=1;k<=20;k++){
		for (int i=0;i<=n;i++) mx[i][k]=-1e16,mn[i][k]=1e16;
	}
	mx[0][0]=0; mn[0][0]=0;
	for (int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
		b[i]+=b[i-1];
		mx[i][0]=b[i]; mn[i][0]=b[i];
	}
	bin[0]=1;
	for (int i=1;i<=23;i++) bin[i]=bin[i-1]*2;
	for (int k=1;k<=20;k++){
		for (int i=0;i<=n;i++){
			mx[i][k]=max(mx[i][k-1],mx[i+bin[k-1]][k-1]);
			mn[i][k]=min(mn[i][k-1],mn[i+bin[k-1]][k-1]);
		}
	}
//	cout<<"done"<<endl;
	for (int i=1;i<=n;i++){
		while (top&&a[st[top]]>=a[i]) top--;
		pre[i]=st[top]+1;
		st[++top]=i;
	}
	top=0;
	for (int i=n;i>=1;i--){
		while (top&&a[st[top]]>=a[i]) top--;
		if (top>0) nxt[i]=st[top]-1;
		else nxt[i]=n;
		st[++top]=i;
	}
//	cout<<"done"<<endl;
	ll ans=-1e18;
	for (int i=1;i<=n;i++){
//		cout<<"in "<<pre[i]<<" "<<nxt[i]<<endl;
		ll mn=qry_mn(pre[i]-1,i-1);
		ll mx=qry_mx(i,nxt[i]);
//		cout<<i<<" "<<mx<<" "<<mn<<endl;
		ans=max(ans,a[i]*(mx-mn));
	}
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
