#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int sa[MAXN],rnk[MAXN];
int n,a[MAXN],b[MAXN];
char c[MAXN],s[MAXN];
int cnt[MAXN];
void mysort(int src[],int key[],int tar[]){
	for (int i=0;i<=n;i++) cnt[i]=0;
	for (int i=0;i<n;i++) cnt[key[i]]++;
	for (int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
	for (int i=n-1;i>=0;i--){
		int x=key[src[i]];
		tar[cnt[x]-1]=src[i];
		cnt[x]--;
	}
}
int main(){
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<n;i++) rnk[i]=s[i],c[i]=s[i];
	sort(c,c+n);
	int nn=unique(c,c+n)-c-1;
	for (int i=0;i<n;i++) rnk[i]=lower_bound(c,c+nn,rnk[i])-c;
//	for (int i=0;i<n;i++) printf("%d\n",rnk[i]);
	for (int i=0;(1<<i)<n;i++){
		for (int j=0;j<n;j++){
			a[j]=rnk[j]+1;
			if (j+(1<<i)<n) b[j]=rnk[j+(1<<i)]+1;
			else b[j]=0;
		}
		for (int j=0;j<n;j++) sa[j]=j;
		mysort(sa,b,rnk);
//		for (int j=0;j<n;j++) printf("%d ",rnk[j]);
		mysort(rnk,a,sa);
//		for (int j=0;j<n;j++) printf("%d ",sa[j]);
//		cout<<endl;
		rnk[sa[0]]=0;
		for (int j=1;j<n;j++){
			int id=sa[j],las=sa[j-1];
			if (a[id]==a[las]&&b[id]==b[las]) rnk[id]=rnk[las];
			else rnk[id]=rnk[las]+1;
		}
	}
	for (int i=0;i<n;i++) printf("%d ",sa[i]+1);
	
	return 0;
}
