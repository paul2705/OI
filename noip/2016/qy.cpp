#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const ll MAXN=7e6+6;
ll q1[MAXN],head1,tail1;
ll q2[MAXN],head2,tail2;
ll q3[MAXN],head3,tail3;
ll n,m,q,t;
double u,v,p;
ll ans[MAXN],cnt;
ll res[MAXN],top;
bool cmp(ll a,ll b){ return a>b; }
int main(){
	scanf("%lld%lld%lld%lf%lf%lld",&n,&m,&q,&u,&v,&t);
	for (ll i=1,x;i<=n;i++){
		scanf("%lld",&x);
		q1[head1++]=x;
	}
	sort(q1,q1+head1,cmp); p=u/v;
	for (ll i=1;i<=m;i++){
		ll del=(i-1)*q,x=0; x=del;
		if (head2>tail2&&head1>tail1&&head3>tail3){
			if (q1[tail1]>q2[tail2]){
				if (q2[tail2]>q3[tail3]) x+=q1[tail1++];
				else if (q1[tail1]>q3[tail3]) x+=q1[tail1++];
				else x+=q3[tail3++];
			}
			else{
				if (q1[tail1]>q3[tail3]) x+=q2[tail2++];
				else if (q2[tail2]>q3[tail3]) x+=q2[tail2++];
				else x+=q3[tail3++];
			}
		}
		else if (head2>tail2&&head1>tail1){
			if (q2[tail2]>q1[tail1]) x+=q2[tail2++];
			else x+=q1[tail1++];
		}
		else if (head2>tail2&&head3>tail3){
			if (q2[tail2]>q3[tail3]) x+=q2[tail2++];
			else x+=q3[tail3++];
		}
		else if (head1>tail1&&head3>tail3){
			if (q1[tail1]>q3[tail3]) x+=q1[tail1++];
			else x+=q3[tail3++];
		}
		else if (head1>tail1) x+=q1[tail1++];
		else if (head2>tail2) x+=q2[tail2++];
		else x+=q3[tail3++];
//		cout<<x-del<<" "<<x<<" ";
		ll l=floor(x*p),r=x-l;
//		cout<<l<<" "<<r<<endl;
		l-=del+q; r-=del+q;
		q2[head2++]=l,q3[head3++]=r;
		if (i%t==0) ans[cnt++]=x;
	}
	for (ll i=0;i<cnt;i++) printf("%lld ",ans[i]);
	cout<<endl;
//	for (ll i=tail1;i<head1;i++) res[top++]=q1[i]+m*q;
//	for (ll i=tail2;i<head2;i++) res[top++]=q2[i]+m*q;
//	for (ll i=tail3;i<head3;i++) res[top++]=q3[i]+m*q;
//	sort(res,res+top,cmp);
	for (ll i=1;i<=n+m;i++){
		ll mx=-1e9;
//		cout<<q1[tail1]<<" "<<q2[tail2]<<" "<<q3[tail3]<<endl;
		if (head1>tail1) mx=max(mx,q1[tail1]);
		if (head2>tail2) mx=max(mx,q2[tail2]);
		if (head3>tail3) mx=max(mx,q3[tail3]);
		if (mx==q1[tail1]&&head1>tail1) tail1++;
		else if (mx==q2[tail2]&&head2>tail2) tail2++;
		else if (mx==q3[tail3]&&head3>tail3) tail3++;
		mx+=m*q;
		if (i%t==0) printf("%lld ",mx);
	}
	cout<<endl;
	return 0;
}
