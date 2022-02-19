#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e5+5;
struct rec{
	int x,y;
} a[MAXN];
int n,f[MAXN],lim;
int b[MAXN*5];
vector<int> lis[MAXN];
bool cmp(rec a,rec b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
int find(int l,int r,int x){
	int mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (f[mid]<x) l=mid;
		else r=mid;
	}
	return l;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=5*n;i++) scanf("%d",&a[i].x);
	for (int i=1;i<=5*n;i++) scanf("%d",&a[i].y);
//	sort(a+1,a+5*n+1,cmp);
	for (int i=1;i<=5*n;i++){
		lis[a[i].y].push_back(i);
	}
	int cnt=0;
	for (int i=1;i<=5*n;i++){
		for (int j=lis[a[i].x].size()-1;j>=0;j--){
			b[cnt++]=lis[a[i].x][j];
		}
	}
//	for (int i=0;i<cnt;i++) printf("%d ",b[i]);
//	cout<<"done"<<endl;
	lim=1; f[1]=b[0];
	for (int i=1;i<cnt;i++){
		int pos=find(0,lim+1,b[i]);
		f[pos+1]=b[i];
		lim=max(lim,pos+1);
	}
	printf("%d\n",lim);
	return 0;
}
