#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
int a[MAXN],n;
bool use[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans=0;
	for (int i=1;i<n;i++){
		int mn=2e4*n+5,pos=0;
		for (int j=1;j<=n;j++){
			if (use[j]) continue;
			if (mn>a[j]) mn=a[j],pos=j;
		}
		use[pos]=1;
		int mn1=2e4*n+5,pos1=0;
		for (int j=1;j<=n;j++){
			if (use[j]) continue;
			if (mn1>a[j]) mn1=a[j],pos1=j;
		}
//		cout<<a[pos1]<<" "<<mn<<" "<<i<<endl;
		a[pos1]+=mn;
		ans+=a[pos1];
	}
	printf("%d\n",ans);
	return 0;
}
