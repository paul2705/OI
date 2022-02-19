#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int a[MAXN];
int qmin[MAXN],lmin=1,rmin;
int qmax[MAXN],lmax=1,rmax;
int n,k;
void mininsert(int x){
	while (lmin<=rmin&&a[qmin[rmin]]>=a[x]) rmin--;
	qmin[++rmin]=x;
}
int minquery(){ return a[qmin[lmin]]; }
void minpop(int x){
	if (x==qmin[lmin]) lmin++;
}
void maxinsert(int x){
	while (lmax<=rmax&&a[qmax[rmax]]<=a[x]) rmax--;
	qmax[++rmax]=x;
}
int maxquery(){ return a[qmax[lmax]]; }
void maxpop(int x){
	if (x==qmax[lmax]) lmax++;
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<k;i++) mininsert(i);
	for (int i=k;i<=n;i++){
		mininsert(i);
		printf("%d ",minquery());
		minpop(i-k+1);
	}
	printf("\n");
	for (int i=1;i<k;i++) maxinsert(i);
	for (int i=k;i<=n;i++){
		maxinsert(i);
		printf("%d ",maxquery());
		maxpop(i-k+1);
	}
	printf("\n");
	return 0;
}
