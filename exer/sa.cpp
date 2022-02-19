#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int sa[MAXN],rk[MAXN];
int x[MAXN],cnt[MAXN];
int n,m,h[MAXN];
char s[MAXN];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	m=250;
	for (int i=1;i<=n;i++) cnt[rk[i]=s[i]]++;
	for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
	for (int i=n;i>=1;i--) sa[cnt[rk[i]]--]=i;
	for (int k=1;k<=n;k<<=1){
		int tmp=1;
		for (int i=n-k+1;i<=n;i++) x[tmp++]=i;
		for (int i=1;i<=n;i++){
			if (sa[i]>k) x[tmp++]=sa[i]-k;
		}
		for (int i=1;i<=m;i++) cnt[i]=0;
		for (int i=1;i<=n;i++) cnt[rk[x[i]]]++;
		for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
		for (int i=n;i>=1;i--) sa[cnt[rk[x[i]]]--]=x[i];
		for (int i=1;i<=n;i++) swap(rk[i],x[i]);
		tmp=1; rk[sa[1]]=1;
		for (int i=2;i<=n;i++){
			if (!(x[sa[i]]==x[sa[i-1]]&&x[sa[i]+k]==x[sa[i-1]+k])) tmp++;
			rk[sa[i]]=tmp;
		}
		if (tmp==n) break;
		m=tmp+1;
	}
	for (int i=1;i<=n;i++) rk[sa[i]]=i;
	int tmp=1;
	for (int i=1;i<=n;i++){
		int pre=sa[rk[i]-1];
		if (tmp) tmp--;
		while (s[pre+tmp]==s[i+tmp]&&max(pre,i)+tmp<=n) tmp++;
		h[rk[i]]=tmp;
	}
//	for (int i=1;i<=n;i++) printf("%d %d\n",sa[i],h[i]);
	for (int i=1;i<=n;i++) printf("%d ",sa[i]);
	cout<<endl;
	return 0;
}
