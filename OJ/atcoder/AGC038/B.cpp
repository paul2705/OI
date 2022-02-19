#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int n,k,a[MAXN];
int mn[MAXN],mnl,mnr;
int mx[MAXN],mxl,mxr;
int ans;
void mnpush(int x){
	while (mnl<mnr&&a[mn[mnr-1]]>a[x]) mnr--;
	mn[mnr++]=x;
}
void mnpop(int x){
	while (mnl<mnr&&mn[mnl]<=x) mnl++;
}
void mxpush(int x){
	while (mxl<mxr&&a[mx[mxr-1]]<a[x]) mxr--;
	mx[mxr++]=x;
}
void mxpop(int x){
	while (mxl<mxr&&mx[mxl]<=x) mxl++;
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]++;
//	for (int i=1;i<=n;i++) printf("%d ",a[i]);
//	cout<<endl;
	mnl=mnr=mxl=mxr=1;
	for (int i=1;i<k;i++) mnpush(i),mxpush(i);
	mxpush(k);
	for (int i=k;i<=n;i++){
		ans++;
		mnpush(i); mnpop(i-k);
		mxpush(i+1); mxpop(i-k+1);
		int x=a[mn[mnl]],y=a[mx[mxl]];
//		cout<<i-k+1<<" "<<i<<" mn: "<<x<<" "<<mn[mnl]<<endl;
//		cout<<i-k+2<<" "<<i+1<<" mx: "<<y<<" "<<mx[mxl]<<endl;
		if (a[i-k+1]==x&&a[i+1]==y) ans--;
	}
	printf("%d\n",ans);
	return 0;
}
