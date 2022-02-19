#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
int x[MAXN],y[MAXN];
deque<int> q[MAXN];
vector<ll> c[MAXN];
int n,m,Q;
int t[MAXN<<1],ct[MAXN<<1];
ll col_id[MAXN<<1];
int rsel(int k){
	int c=0;
	for (int i=1<<19;i>0;i>>=1){
		c+=i;
		if (c<=m+Q&&ct[c]<k) k-=ct[c];
		else c-=i;
	}
	return c;
}
ll col_pop_id(int k){
//	cout<<__func__<<endl;
	int c=0;
	for (int i=1<<19;i>0;i>>=1){
		c+=i;
		if (c<=n+Q&&t[c]<k) k-=t[c];
		else c-=i;
	}
	c++;
	for (int i=c;i<=n+Q;i+=i&-i) t[i]--;
//	cout<<"done"<<endl;
	return col_id[c];
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for (int i=0;i<Q;i++){
		scanf("%d%d",&x[i],&y[i]);
		if (y[i]<m) q[x[i]].push_back(i);
	}
	for (int i=1;i<=n+Q;i++) t[i]=i&-i;
	for (int i=1;i<=m+Q;i++) ct[i]=i&-i;
	for (int i=1;i<=n;i++){
		for (deque<int>::iterator it=q[i].begin();it!=q[i].end();it++){
			int k=y[*it],pos=rsel(k)+1; *it=pos;
			for (int j=pos;j<=m+Q;j+=j&-j) ct[j]--;
		}
		for (deque<int>::iterator it=q[i].begin();it!=q[i].end();it++){
			int pos=*it;
			for (int j=pos;j<=m+Q;j+=j&-j) ct[j]++;
		}
	}
//cout<<"done"<<endl;
	for (int i=1;i<=n;i++) col_id[i]=m*(ll)i;
	int col_pos=n+1;
	for (int i=0;i<Q;i++){
		ll ans; //cout<<i<<endl;
		if (y[i]<m){
//			cout<<"in"<<endl;
//			cout<<x[i]<<" "; cout<<q[x[i]].front()<<endl;
			int k=q[x[i]].front();
//			cout<<k<<endl;
			if (k<m) ans=(x[i]-1ll)*m+k;
			else ans=c[x[i]][k-m];
			q[x[i]].pop_front();
			c[x[i]].push_back(col_pop_id(x[i]));
		}
		else ans=col_pop_id(x[i]);
		col_id[col_pos++]=ans;
		printf("%lld\n",ans);
	}
	return 0;
}
