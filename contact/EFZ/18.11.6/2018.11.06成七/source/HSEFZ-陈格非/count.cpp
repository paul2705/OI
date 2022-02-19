#include <cstdio>
#include <algorithm>
int n,m,a[100],p=1e9,ans,cnt;
bool ok() {
	int h[10]={},w[10]={};
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) {
			h[i] = std::max(h[i],a[i*n+j]);
			w[j] = std::max(w[j],a[i*n+j]);
		}
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) {
//			printf("%d:%d %d:%d\n",i,h[i],j,w[j]);
			if (h[i]==w[j] && h[i] != n*m) return 0;
		}
	return 1;
}
int main() {
	freopen("count.in","r",stdin);
	scanf("%d%d%d",&n,&m,&p);
//	scanf("%d%d",&n,&m);
	for (int i=0; i<n*m; i++) a[i] = i+1;
	do{
		ans+=ok();
	}while(std::next_permutation(a,a+n*m));
	printf("%d\n",ans%p);
}
