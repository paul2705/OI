#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
mat a(2,vec(2));
ll n,m,p,q,x,y;
mat mul(mat &a,mat &b){
	mat c(2,vec(2));
	for (int i=0;i<2;i++){
		for (int k=0;k<2;k++){
			for (int j=0;j<2;j++){
				c[i][j]=(c[i][j]+a[i][k]*b[k][j])%m;
			}
		}
	}
//	cout<<__func__<<endl;
	return c;
}
mat mod_pow(mat a,ll n){
	mat c=a; n--;
	while (n){
//		cout<<n<<endl;
		if (n&1) a=mul(a,c);
		c=mul(c,c);
		n>>=1;
	}
	return a;
}
int main(){
	scanf("%lld%lld%lld%lld%lld%lld",&p,&q,&x,&y,&n,&m);
	if (n==1) return printf("%lld\n",x%m),0;
	if (n==2) return printf("%lld\n",y%m),0;
	a[0][0]=0,a[0][1]=1;
	a[1][0]=q,a[1][1]=p;
	mat A=mod_pow(a,n-1);
	printf("%lld\n",(A[0][0]*x%m+A[0][1]*y%m)%m);
	return 0;
}
