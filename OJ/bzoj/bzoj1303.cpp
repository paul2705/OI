#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int cnt[MAXN*3];
int n,k;
int a[MAXN];
int ans=0;
int main(){
	scanf("%d%d",&n,&k);
	int pos=-1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]<k) a[i]=-1;
		if (a[i]==k) a[i]=0,pos=i;
		if (a[i]>k) a[i]=1;
	}
	int sum=0;
	for (int i=pos;i>=1;i--){
		sum+=a[i];
		cnt[sum+n+1]++;
	}
	ans+=cnt[n+1];
	sum=0;
	for (int i=pos+1;i<=n;i++){
		sum+=a[i];
		ans+=cnt[-sum+n+1];
	}
	printf("%d\n",ans);
	return 0;
}
