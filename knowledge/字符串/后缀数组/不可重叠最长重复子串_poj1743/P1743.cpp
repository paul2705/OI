#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=4e4+5;
int n;
int a[MAXN],b[MAXN],sa[MAXN],rk[MAXN],x[MAXN];
int h[MAXN],cnt[MAXN];
bool check(int mid){
	int mn=1e9,mx=0;
	for (int i=2;i<=n;i++){
		if (h[i]>=mid){
			mn=min(mn,min(sa[i-1],sa[i]));
			mx=max(mx,max(sa[i-1],sa[i]));
			if (mx-mn>mid) return 1; //之所以不是mx-mn>=mid，是因为我们求的是差分数组，第i位代表(i,i+1),第i+1位代表(i+1,i+2)，他们相交，因此mx-mn>mid
		}
		else mx=0,mn=1e9;
	}
	if (mx-mn>mid) return 1;
	else return 0;
}
int main(){
	scanf("%d",&n);
	while (n>0){
		for (int i=1;i<=n;i++) scanf("%d",&b[i]);
		for (int i=1;i<=n+5;i++) a[i]=0; //多组数据要注意清空
		for (int i=1;i<n;i++) a[i]=b[i+1]-b[i]+88;//注意负数
		n--;
		for (int i=1;i<=n;i++) rk[i]=sa[i]=x[i]=cnt[i]=h[i]=0;
		int mx=200;//加上88的偏移量后，a[]中数字<=176，而非<=88
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
				if (!(x[sa[i]]==x[sa[i-1]]&&x[sa[i]+k]==x[sa[i-1]+k])) tmp++;
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
			while (a[pre+stp]==a[i+stp]&&max(i,pre)+stp<=n) stp++;//注意i+stp,pre+stp超出n的边界
			h[rk[i]]=stp;
		}
		int l=1,r=n+1,mid;
		while (r-l>1){
			mid=(l+r)>>1;
			if (check(mid)) l=mid;
			else r=mid;
		}
		if (l>=4) printf("%d\n",l+1);
		else printf("0\n");
		scanf("%d",&n);
	}
	return 0;
}
