#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=3e18;
const int MAXN=3e6+6;
ll a[MAXN],b[MAXN];
int n;
int st[MAXN],top;
ll mn[3][MAXN],mx[3][MAXN];
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
//	cout<<inf<<endl;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
		b[i]+=b[i-1];
		mn[1][i]=mn[2][i]=inf; mx[1][i]=mx[2][i]=-inf;
	}
	for (int i=1;i<=n;i++){
		while (top&&a[st[top]]>=a[i]){
			mn[1][i]=min(mn[1][i],min(mn[1][st[top]],b[st[top]]));
			mx[1][i]=max(mx[1][i],max(mx[1][st[top]],b[st[top]]));
			top--;
		}
		mn[1][i]=min(mn[1][i],b[st[top]]);
		mx[1][i]=max(mx[1][i],b[st[top]]);
		st[++top]=i;
	}
	top=0;
	for (int i=n;i>=1;i--){
		while (top&&a[st[top]]>=a[i]){
			mx[2][i]=max(mx[2][i],mx[2][st[top]]);
			mn[2][i]=min(mn[2][i],mn[2][st[top]]);
			top--;
		}
		mx[2][i]=max(mx[2][i],b[i]);
		mn[2][i]=min(mn[2][i],b[i]);
		st[++top]=i;
	}
	ll ans=-inf;
	for (int i=1;i<=n;i++){
//		cout<<a[i]<<" "<<mx[2][i]<<" "<<mn[2][i]<<endl;
		if (a[i]>0) ans=max(ans,a[i]*(mx[2][i]-mn[1][i]));
		else ans=max(ans,a[i]*(mn[2][i]-mx[1][i]));
	}
	printf("%lld\n",ans);
//	fclose(stdin); fclose(stdout);
	return 0;
}
