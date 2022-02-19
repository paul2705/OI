#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e6+6;
int n;
int cnt[MAXN];
struct rec{
	int d,i,j;
};
queue<rec> q;
void dfs(int d,int i,int j){
	if (max(i,j)>n) return;
	cnt[i]=min(cnt[i],d); cnt[j]=min(cnt[j],d);
	dfs(d+1,i+j,j); dfs(d+1,i+j,i);
}
int main(){
	freopen("coordinate.ans","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) cnt[i]=1e9;
//	cout<<0<<endl;
//	dfs(0,1,1);
	q.push((rec){0,1,1});
	while (!q.empty()){
//		cout<<"in"<<endl;
		rec u=q.front(); q.pop();
		if (u.i>n||u.j>n) continue;
		cnt[u.i]=min(cnt[u.i],u.d);
		cnt[u.j]=min(cnt[u.j],u.d);
		if (u.d<=cnt[u.i+u.j]){
			q.push((rec){u.d+1,u.i+u.j,u.j});
			q.push((rec){u.d+1,u.i+u.j,u.i});
		}
	}
	for (int i=1;i<=n;i++){
		cout<<i<<" "<<cnt[i]<<endl;
//		if (cnt[i]==1e9) break;
	}
//	cout<<cnt[n]<<endl;
	return 0;
}
