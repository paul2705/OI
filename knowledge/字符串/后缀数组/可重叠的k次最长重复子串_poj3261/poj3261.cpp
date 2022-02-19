#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e4+5;
int n,k,a[MAXN];
int sa[MAXN],rk[MAXN],x[MAXN];
int h[MAXN];
int cnt[MAXN];
bool check(int mid){
	int cnt=1;
	for (int i=2;i<=n;i++){
		if (h[i]>=mid){
			cnt++;
			if (cnt>=k) return 1;
		}
		else cnt=1;
	}
	return cnt>=k;
}
int main(){
	scanf("%d%d",&n,&k);
	int mx=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
	for (int i=1;i<=n;i++) cnt[rk[i]=a[i]]++;
	for (int i=1;i<=mx;i++) cnt[i]+=cnt[i-1];
	for (int i=n;i>=1;i--) sa[cnt[rk[i]]--]=i;
	for (int k=1;k<=n;k<<=1){
		int tmp=1;
		for (int i=n-k+1;i<=n;i++) x[tmp++]=i;
		for (int i=1;i<=n;i++){
			if (sa[i]>k) x[tmp++]=sa[i]-k;
		}
		for (int i=1;i<=mx;i++) cnt[i]=0;
		for (int i=1;i<=n;i++) cnt[rk[x[i]]]++;
		for (int i=1;i<=mx;i++) cnt[i]+=cnt[i-1];
		for (int i=n;i>=1;i--) sa[cnt[rk[x[i]]]--]=x[i];
		for (int i=1;i<=n;i++) swap(rk[i],x[i]);
		tmp=1; rk[sa[1]]=1;
		for (int i=2;i<=n;i++){
			if (!(x[sa[i]]==x[sa[i-1]]&&x[sa[i-1]+k]==x[sa[i]+k])) tmp++;
			rk[sa[i]]=tmp;
		}
		if (tmp==n) break;
		mx=tmp+1;
	}
	for (int i=1;i<=n;i++) rk[sa[i]]=i;
	int stp=0;
	for (int i=1;i<=n;i++){
		int pre=sa[rk[i]-1];
		if (stp) stp--;
		while (a[pre+stp]==a[i+stp]&&max(i,pre)+stp<=n) stp++;
		h[rk[i]]=stp;
	}
//	for (int i=1;i<=n;i++) cout<<sa[i]<<" "<<h[i]<<endl;
	int l=0,r=n+1,mid;
	while (r-l>1){
		mid=(l+r)>>1;
		if (check(mid)) l=mid;
		else r=mid;
	}
	printf("%d\n",l);
	return 0;
}
