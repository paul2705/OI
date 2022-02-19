#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=50;
int a[MAXN];
int n,k,ans;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<(1<<n);i++){
		int cnt=0,cnt1=0;
		for (int j=0;j<n;j++) if (i&(1<<j)) cnt++;
		if (cnt!=k) continue; cnt=0;
		for (int j=0;j<n;j++){
			if (!(i&(1<<j))){
				cnt++;
				if (a[j]==cnt) cnt1++;
			}
		}
//		cout<<cnt1<<endl;
		ans=max(ans,cnt1);
	}
	printf("%d\n",ans);
	return 0;
}
