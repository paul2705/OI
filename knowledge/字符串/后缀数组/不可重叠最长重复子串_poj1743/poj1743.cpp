#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e4+5;
int n,a[MAXN],sa[MAXN],rk[MAXN],x[MAXN];
int h[MAXN];
int cnt[MAXN];
int main(){
	scanf("%d",&n);
	while (n>0){
		int mx=100;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) cnt[rk[i]=a[i]]++;
		for (int i=1;i<=mx;i++) cnt[i]+=cnt[i-1];
		for (int i=n;i>=1;i--) sa[cnt[rk[i]]--]=i;
		for (int k=1;k<=n;k<<=1){
			int tmp=0;
			for (int i=n-k+1;i<=n;i++) x[++tmp]=i;
			for (int i=1;i<=n;i++){
				if (sa[i]>k) x[++tmp]=sa[i]-k;
			}
			for (int i=1;i<=mx;i++) cnt[i]=0;
			for (int i=1;i<=n;i++) cnt[rk[x[i]]]++;
			for (int i=1;i<=mx;i++) cnt[i]+=cnt[i-1];
			for (int i=n;i>=1;i--) sa[cnt[rk[x[i]]]--]=x[i];
			for (int i=1;i<=n;i++) swap(rk[i],x[i]);
			tmp=1; rk[sa[1]]=1;
			for (int i=2;i<=n;i++){
				if (!(rk[sa[i-1]]==rk[sa[i]]&&rk[sa[i-1]+k]==rk[sa[i]+k])) tmp++;
				rk[sa[i]]=tmp;
			}
			if (tmp==n) break;
			mx=tmp+1;
		}
		for (int i=1;i<=n;i++) rk[sa[i]]=i;
		int stp=0;
