#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXX=1e6+6;
int mx[MAXX],mn[MAXX];
int n,d,mxa,qx[MAXX],qn[MAXX];
bool check(int x){
	int mxl=0,mxr=0,mnl=0,mnr=0;
	for (int i=0;i<=mxa;i++){
		if (mx[i]!=-1){
			while (i-qx[mxl]>x&&mxl<mxr) mxl++;
			while (i-qn[mnl]>x&&mnl<mnr) mnl++;
			while (mx[i]>=mx[qx[mxr-1]]&&mxl<mxr) mxr--;
			while (mn[i]<=mn[qn[mnr-1]]&&mnl<mnr) mnr--;
			qx[mxr++]=i,qn[mnr++]=i;
			if (mx[qx[mxl]]-mn[qn[mnl]]>=d) return 1;
		}
	}
	return 0;
}
int main(){
	for (int i=0;i<=1e6;i++) mx[i]=-1,mn[i]=1e9;
	scanf("%d%d",&n,&d);
	for (int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		mx[x]=max(mx[x],y); mxa=max(mxa,x);
		mn[x]=min(mn[x],y);
	}
	int l=1,r=mxa+1,mid;
	while (l<r){
//		cout<<l<<" "<<r<<endl;
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",(r==mxa+1?-1:r));
	return 0;
}
