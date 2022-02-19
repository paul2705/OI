#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int n,sa[MAXN],rk[MAXN];
int x[MAXN];
int cnt[MAXN];
char a[MAXN];
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	int mx=200;
	for (int i=1;i<=n;i++) cnt[rk[i]=a[i]]++;
	for (int i=1;i<=mx;i++) cnt[i]+=cnt[i-1];
	for (int i=n;i>=1;i--) sa[cnt[rk[i]]--]=i;
//	for (int i=1;i<=n;i++) cout<<sa[i]<<" ";
//	cout<<endl;
	for (int i=1;i<=n;i<<=1){
		int tmp=1;
		for (int j=n-i+1;j<=n;j++) x[tmp++]=j;
		for (int j=1;j<=n;j++){
			if (sa[j]>i) x[tmp++]=sa[j]-i;
		}
//		for (int j=1;j<=n;j++) cout<<x[j]<<" ";
//		cout<<";"<<endl;
		memset(cnt,0,sizeof(cnt));
		for (int j=1;j<=n;j++) cnt[rk[x[j]]]++;
		for (int j=1;j<=mx;j++) cnt[j]+=cnt[j-1];
		for (int j=n;j>=1;j--) sa[cnt[rk[x[j]]]--]=x[j];
		for (int j=1;j<=n;j++) swap(rk[j],x[j]);
		tmp=1; rk[sa[1]]=1;
		for (int j=2;j<=n;j++){
			if (!(x[sa[j]]==x[sa[j-1]]&&x[sa[j]+i]==x[sa[j-1]+i])) tmp++;
			rk[sa[j]]=tmp;
		}
		if (tmp==n) break;
		mx=tmp+1;
//		for (int i=1;i<=n;i++) cout<<sa[i]<<" ";
//		cout<<endl;
	}
	for (int i=1;i<=n;i++) rk[sa[i]]=i;
	for (int i=1;i<=n;i++) printf("%d ",sa[i]);
	return 0;
}
