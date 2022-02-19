#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=205;
int n,a[MAXN];
ll ans=0;
int main(){
	scanf("%d",&n);
	int las=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (i==1) continue;
		if (a[i]==1&&a[i-1]==3) ans+=4;
		if (a[i]==1&&a[i-1]==2) ans+=3;
		if (a[i]==2&&a[i-1]==1) ans+=3;
		if (a[i]==2&&a[i-1]==3) ans=1e12;
		if (a[i]==3&&a[i-1]==1) ans+=4;
		if (a[i]==3&&a[i-1]==2) ans=1e12;
		if (i>=3){
			if (a[i]==2&&a[i-1]==1&&a[i-2]==3) ans--;
		}
	}
	if (ans>=1e12) printf("Infinite\n");
	else printf("Finite\n%lld\n",ans);
	return 0;
}
