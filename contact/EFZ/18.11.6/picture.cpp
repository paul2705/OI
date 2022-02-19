#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;
ll h1,h2,w1,w2;
ll a,b,c,d,ans=0;
mat A;
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
ll lcm(ll a,ll b){ return a*b/gcd(a,b); }
ll sum(ll x1,ll y1,ll x2,ll y2){
//	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	return A[x2][y2]-A[x1-1][y2]-A[x2][y1-1]+A[x1-1][y1-1];
}
ll calc(ll x,ll y){
//	cout<<x<<" : "<<y<<endl;
	ll ax=x/a,ay=y/b;
	ll lx=x%a,ly=y%b;
	ll ret=0;
	if (!x||!y) return 0;
	ret+=A[ax][ay]*a*b;
	ret+=sum(ax+1,1,ax+1,ay)*lx*b;
	ret+=sum(1,ay+1,ax,ay+1)*ly*a;
	ret+=sum(ax+1,ay+1,ax+1,ay+1)*lx*ly;
	return ret;
}
int main(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%lld%lld",&h1,&w1);
	A=mat((int)h1+3,vec((int)w1+3,0));
	for (ll i=1;i<=h1;i++){
		for (ll j=1;j<=w1;j++){
			char c=getchar(); while (c!='0'&&c!='1') c=getchar();
			A[i][j]=-A[i-1][j-1]+A[i-1][j]+A[i][j-1]+c-'0';
//			cout<<c<<" ";
		}
//		cout<<endl;
	}
	scanf("%lld%lld",&h2,&w2);
//	cout<<"fuck"<<endl;
	ll lh=lcm(h1,h2),lw=lcm(w1,w2);
	a=lh/h1,b=lw/w1,c=lh/h2,d=lw/w2;
//	cout<<"fuck"<<endl;
	for (ll i=1;i<=h2;i++){
		for (ll j=1;j<=w2;j++){
//			cout<<i<<" "<<j<<endl;
			char cc=getchar(); while (cc!='0'&&cc!='1') cc=getchar();
//			cout<<cc<<endl;
			ll val=cc-'0';
//			cout<<": "<<val<<" ";
			ll x=i*c,y=j*d;
			ll con=calc(x,y)-calc(x-c,y)-calc(x,y-d)+calc(x-c,y-d);
			if (val==0) con=c*d-con;
			ans+=con;
		}
//		cout<<endl;
	}
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
