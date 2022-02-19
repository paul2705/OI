#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=3e6+6;
int a[MAXN],qn[MAXN],qx[MAXN];
int ln,rn,lx,rx,ans,pre;
int n,k;
int main(){
	scanf("%d%d",&k,&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	qn[1]=qx[1]=1; ln=lx=1,rn=rx=1,pre=1;
	for (int i=2;i<=n;i++){
		while (ln<=rn&&a[qn[rn]]<=a[i]) rn--;
		while (lx<=rx&&a[qx[rx]]>=a[i]) rx--;
		qx[++rx]=qn[++rn]=i;
		while (ln<=rn&&lx<=rx&&a[qn[ln]]-a[qx[lx]]>k){
			if (qn[ln]<qx[lx]){ pre=qn[ln]+1,ln++; }
			else {pre=qx[lx]+1,lx++; }
		}
		ans=max(ans,i-pre+1);
	}
	printf("%d\n",ans);
	return 0;
}
