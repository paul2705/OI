#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

const int maxn=1e5+5;
int a[maxn*2];
int lis[maxn*4],pre[maxn*4],suf[maxn*4];


void update(int p,int l,int r){
//	if(l==r) return;
	int mid=(l+r)/2;
//	if(p<=mid) update(p*2,l,mid);
//	else update(p*2+1,mid+1,r);
	
	pre[p]=pre[p*2];
	if(pre[p*2]==mid-l+1&&a[mid]<a[mid+1]) pre[p]+=pre[p*2+1];
	suf[p]=suf[p*2+1];
	if(suf[p*2+1]==r-mid&&a[mid]<a[mid+1]) suf[p]+=suf[p*2];
	lis[p]=max(lis[p*2],lis[p*2+1]);
	if(a[mid]<a[mid+1]) lis[p]=max(lis[p],suf[p*2]+pre[p*2+1]);
	
}

void build(int p,int l,int r){
	if(l==r){
		lis[p]=1;
		pre[p]=1;
		suf[p]=1;
	}
	else{
		int mid=(l+r)/2;
		build(2*p,l,mid);
		build(2*p+1,mid+1,r);
		update(p,l,r);
	}
}

int query(int p,int l,int r,int x,int y){
	if(x<=l&&r<=y) return lis[p];
	if(r<x ||y<l ) return 0;
	int m=(l+r)/2;
	int ans=max( query(2*p,l,m,x,y) , query(2*p+1,m+1,r,x,y) );
	if(a[m]<a[m+1]) ans=max( ans , min(suf[2*p],m-x+1) + min(pre[2*p+1],y-m) );
	return ans;
}

int main(){
//	freopen("orz.in","r",stdin);
	int T=0;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int N=1;
		while(N<n) N<<=1;
		build(1,1,N);
		while(m--){
			string opt;
			cin>>opt;
			if(opt=="U"){
				int x;
				scanf("%d",&x);
				x++;
				scanf("%d",&a[x]);
				int l=x,r=x;
				int mask=1;
//				printf("\n");
				x=x+N-1;
				while(x>1){
					if(x%2==0) r+=mask;
					else l-=mask;
					mask*=2;
					x/=2;
//					printf("%d %d %d\n",x,l,r);
					update(x,l,r);
				}
//				printf("\n");
			}
			else if(opt=="Q"){
				int x,y;
				scanf("%d %d",&x,&y);
				x++; y++;
				printf("%d\n",query(1,1,N,x,y));
			}
		}
	}
}
