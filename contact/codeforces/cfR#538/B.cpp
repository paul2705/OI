#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int a[MAXN],b[MAXN],c[MAXN],n,m,k;
int cnt[MAXN],f[MAXN];
ll ans=0;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) b[i]=a[i],c[i]=a[i];
	sort(b+1,b+n+1); sort(c+1,c+n+1);
	for (int i=n,cnt=1;cnt<=m*k;cnt++,i--) ans+=b[i];
	cout<<ans<<endl;
	int nn=unique(c+1,c+n+1)-c-1;
	for (int i=1;i<=n;i++){
		b[i]=lower_bound(c+1,c+nn+1,b[i])-c;
		a[i]=lower_bound(c+1,c+nn+1,a[i])-c;
	}
	for (int i=n,cn=1;cn<=m*k;cn++,i--) cnt[b[i]]++;
	for (int i=1;i<=n;i++){
		if (cnt[a[i]]>0) f[i]=1,cnt[a[i]]--;
//		cout<<f[i]<<" ";
	}
//	cout<<endl;
	int sum=0,cnt=0;
	for (int i=1;i<=n;i++){
		sum+=f[i];
		if (sum==m) printf("%d ",i),sum=0,cnt++;
		if (cnt==k-1) break;
	}
	cout<<endl;
	return 0;
}
