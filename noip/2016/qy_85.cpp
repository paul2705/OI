#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const int MAXN=1e5+5;
int n,m,len,t;
double u,v,p;
int ans[MAXN],cnt;
priority_queue<int> q;
int main(){
	scanf("%d%d%d%lf%lf%d",&n,&m,&len,&u,&v,&t);
	for (int i=1,x;i<=n;i++){
		scanf("%d",&x);
		q.push(x);
	}
	p=u/v;
	for (int i=1;i<=m;i++){
		int del=(i-1)*len;
		int x=q.top(); q.pop();
		x+=del;
		cout<<x-del<<" "<<x<<" ";
		int l=floor(x*p),r=x-l;
		cout<<l<<" "<<r<<endl;
		q.push(l-del-len); q.push(r-del-len);
		if (i%t==0) ans[cnt++]=x;
	}
	for (int i=0;i<cnt;i++) cout<<ans[i]<<" ";
	cout<<endl;
	int now=0;
	while (!q.empty()){
		now++;
		int x=q.top(); q.pop();
		if (now%t==0) cout<<x+m*len<<" ";
	}
	cout<<endl;
	return 0;
}
