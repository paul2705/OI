#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;
const int MAXN=1e5+5;
int tail[MAXN][3];
int h[MAXN];
int n,m,X,disx,disy;
struct rec{
	int x,id;
	bool operator < (const rec &b) const{
		return x<b.x;
	}
	bool operator > (const rec &b) const{
		return x>b.x;
	}
};
set<rec> s;
double res[MAXN],ans;
void dfs(int d,int i,int A,int B){
	if (d==1){
		if (tail[i][1]==-1){
			disx=A; disy=B;
			return;
		}
		int dis=abs(h[i]-h[tail[i][1]]);
		if (A+B+dis>X){
			disx=A; disy=B;
			return;
		}
		else dfs(d^1,tail[i][1],A+dis,B);
	}
	else{
		if (tail[i][0]==-1){
			disx=A; disy=B;
			return;
		}
		int dis=abs(h[i]-h[tail[i][0]]);
		if (A+B+dis>X){
			disx=A; disy=B;
			return;
		}
		else dfs(d^1,tail[i][0],A,B+dis);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&h[i]),s.insert((rec){h[i],i});
//	for (int i=1;i<=n;i++) cout<<i<<" "; cout<<endl;
//	cout<<(*s.begin()).id<<endl;
	for (int i=1;i<=n;i++){
		set<rec>::iterator it=s.lower_bound((rec){h[i],i});
		set<rec>::iterator l=it,r=it,ll=it,rr=it;
		if (it!=s.end()) r++;
		if (r==s.end()) r=it;
		if (it!=s.begin()) l--;
//		cout<<(*l).id<<" "<<h[i]<<" "<<(*r).id<<endl;
		if (l==it&&r==it) tail[i][0]=tail[i][1]=-1;
		else if (l==it){
			rr=r; rr++;
			if (rr==s.end()) rr=r;
			if (rr==r){
				tail[i][0]=(*r).id;
				tail[i][1]=-1;
			}
			else {
				tail[i][0]=(*r).id;
				tail[i][1]=(*rr).id;
			}
		}
		else if (r==it){
			ll=l;
			if (l!=s.begin()) ll--;
			if (ll==l){
				tail[i][0]=(*l).id;
				tail[i][1]=-1;
			}
			else {
				tail[i][0]=(*l).id;
				tail[i][1]=(*ll).id;
			}
		}
		else{
			ll=l;
			if (l!=s.begin()) ll--;
			rr=r; rr++;
			if (rr==s.end()) rr=r;
			if (ll==l&&rr==r){
				if (abs((*l).x-h[i])<=(*r).x-h[i]){
					tail[i][0]=(*l).id;
					tail[i][1]=(*r).id;
				}
				else {
					tail[i][0]=(*r).id;
					tail[i][1]=(*l).id;
				}
			}
			else if (ll==l){
				if (abs((*l).x-h[i])>(*rr).x-h[i]){
					tail[i][0]=(*r).id;
					tail[i][1]=(*rr).id;
				}
				else if (abs((*l).x-h[i])<=(*r).x-h[i]){
					tail[i][0]=(*l).id;
					tail[i][1]=(*r).id;
				}
				else {
					tail[i][0]=(*r).id;
					tail[i][1]=(*l).id;
				}
			}
			else if (rr==r){
				if ((*r).x-h[i]>=abs((*ll).x-h[i])){
					tail[i][0]=(*l).id;
					tail[i][1]=(*ll).id;
				}
				else if ((*r).x-h[i]<abs((*l).x-h[i])){
					tail[i][0]=(*r).id;
					tail[i][1]=(*l).id;
				}
				else {
					tail[i][0]=(*l).id;
					tail[i][1]=(*r).id;
				}
			}
			else {
				if (abs((*ll).x-h[i])<=(*r).x-h[i]){
					tail[i][0]=(*l).id;
					tail[i][1]=(*ll).id;
				}
				else if (abs((*l).x-h[i])<=(*r).x-h[i]){
//					cout<<"In"<<endl;
					tail[i][0]=(*l).id;
					tail[i][1]=(*r).id;
				}
				else if (abs((*l).x-h[i])<=(*rr).x-h[i]){
					tail[i][0]=(*r).id;
					tail[i][1]=(*l).id;
				}
				else{
					tail[i][0]=(*r).id;
					tail[i][1]=(*rr).id;
				}
			}
		}
//		cout<<(*ll).id<<" "<<(*l).id<<" "<<(*r).id<<" "<<(*rr).id<<endl;
//		cout<<tail[i][0]<<" "<<tail[i][1]<<endl;
		s.erase(it);
	}
//	for (int i=1;i<=n;i++){
//		printf("%d<-%d->%d\n",tail[i][0],i,tail[i][1]);
//	}
	scanf("%d",&X);
	ans=1e9;
	for (int i=1;i<=n;i++){
		disx=0,disy=0;
		dfs(1,i,0,0);
		if (disy>0) res[i]=(double)disx/disy;
		else res[i]=1e9;
		ans=min(ans,res[i]);
//		cout<<"x: "<<disx<<" "<<disy<<endl;
//		cout<<res[i]<<" "<<ans<<endl;
	}
	int pos=0,mx=-1e9;
	for (int i=1;i<=n;i++){
		if (res[i]==ans){
			if (h[i]>mx){
				mx=h[i];
				pos=i;
			}
		}	
	}
	printf("%d\n",pos);
	scanf("%d",&m);
//	cout<<m<<endl;
	for (int i=1,s;i<=m;i++){
		scanf("%d%d",&s,&X);
		disx=0; disy=0;
		dfs(1,s,0,0);
		printf("%d %d\n",disx,disy);
	}
	return 0;
}
