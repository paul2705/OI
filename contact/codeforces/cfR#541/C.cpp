#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
int n,a[MAXN];
int b[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int cnt=0,i;
	for (i=n;i>=1;i-=2) b[++cnt]=a[i];
	if (i==-1) for (i=2;i<=n;i+=2) b[++cnt]=a[i];
	if (i==0) for (i=1;i<=n;i+=2) b[++cnt]=a[i];
//	cout<<i<<endl;
	//	int ans=abs(b[n]-b[1]);
//	for (int i=2;i<=n;i++){
//		ans=max(ans,abs(b[i]-b[i-1]));
//		}
//	printf("%d\n",ans);
	for (int i=1;i<=n;i++) cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}
