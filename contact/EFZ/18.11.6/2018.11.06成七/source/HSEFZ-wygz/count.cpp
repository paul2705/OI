#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int n,m,d[5],a[5][5];
int s1[5],s2[5],cnt;
ll mod,ans;
int main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	read(n); read(m); read(mod);
	for (int i=1;i<=n*m;i++) d[i]=i;
	do {
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			a[i][j]=d[(i-1)*m+j],
			s1[i]=max(s1[i],a[i][j]),
			s2[j]=max(s2[j],a[i][j]);
		cnt=0;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]==s1[i]&&a[i][j]==s2[j]) cnt++;
		if (cnt==1) ans++; ans%=mod;
	} while (next_permutation(d+1,d+n*m+1));
	printf("%lld\n",ans);
	return 0;
}
