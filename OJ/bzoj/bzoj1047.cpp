#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int n,m,len;
int qmx[MAXN],mxl,mxr;
int qmn[MAXN],mnl,mnr;
int a[MAXN][MAXN];
int lmn[MAXN][MAXN],lmx[MAXN][MAXN];
int ans=1e9;
int main(){
	scanf("%d%d%d",&n,&m,&len);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	for (int i=1;i<=n;i++){
		mxl=mxr=mnl=mnr=0;
		for (int j=1;j<=m;j++){
			while (mxr>mxl&&a[i][qmx[mxr-1]]<a[i][j]) mxr--;
			qmx[mxr++]=j;
			while (j-qmx[mxl]>=len) mxl++;
			while (mnr>mnl&&a[i][qmn[mnr-1]]>a[i][j]) mnr--;
			qmn[mnr++]=j;
			while (j-qmn[mnl]>=len) mnl++;
			lmx[i][j]=a[i][qmx[mxl]]; lmn[i][j]=a[i][qmn[mnl]];
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=m;j++) printf("(%d %d) ",lmn[i][j],lmx[i][j]);
//		printf("\n");
//	}
	for (int i=len;i<=m;i++){
		mxl=mxr=mnl=mnr=0;
		for (int j=1;j<=n;j++){
			while (mxr>mxl&&lmx[qmx[mxr-1]][i]<lmx[j][i]) mxr--;
			qmx[mxr++]=j;
			while (j-qmx[mxl]>=len) mxl++;
			while (mnr>mnl&&lmn[qmn[mnr-1]][i]>lmn[j][i]) mnr--;
			qmn[mnr++]=j;
			while (j-qmn[mnl]>=len) mnl++;
			if (j>=len) ans=min(ans,lmx[qmx[mxl]][i]-lmn[qmn[mnl]][i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
