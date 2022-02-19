#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int a[MAXN],n,k;
bool use[MAXN];
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]=i-a[i];
	while (k--){
		int cnt0=0,cnt1=0;
		int pos=-1,mx=0;
		for (int i=n;i>=1;i--){
			if (!use[i]){
				if (a[i]>1&&cnt1-cnt0>=mx) mx=cnt1-cnt0,pos=i;
				if (a[i]==0) cnt0++;
				if (a[i]==1) cnt1++;
			}
		}
		if (pos==-1) break;
//		cout<<mx<<" "<<pos<<endl;
		use[pos]=1;
		for (int i=pos;i<=n;i++) a[i]--;
	}
	int ans=0;
	k++;
	for (int i=1;i<=n-k;i++){
		if (!use[i]) if (a[i]==0) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
