#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=3e6+5;
int a[MAXN],qx[MAXN],qn[MAXN];
int n,k,ans,pre;
int main(){
	scanf("%d%d",&k,&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	qx[1]=qn[1]=pre=1;
	int ln=1,rn=2,lx=1,rx=2;
	for (int i=2;i<=n;i++){
		while (ln<rn&&a[qn[rn-1]]>a[i]) rn--;
		while (lx<rx&&a[qx[rx-1]]<a[i]) rx--;
		qx[rx++]=qn[rn++]=i;
		while (a[qx[lx]]-a[qn[ln]]>k){
			if (qx[lx]<qn[ln]) pre=qx[lx++]+1;
			else pre=qn[ln++]+1;
		}
		ans=max(ans,i-pre+1);
	}
	printf("%d\n",ans);
	return 0;
}
