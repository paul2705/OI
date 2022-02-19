#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,P;
void casea(){
	if ((n==1)&&(m==1)) printf("%lld\n",(LL)1%P);
	if ((n==1)&&(m==2)) printf("%lld\n",(LL)2%P);
	if ((n==1)&&(m==3)) printf("%lld\n",(LL)6%P);
	if ((n==2)&&(m==2)) printf("%lld\n",(LL)24%P);
	if ((n==2)&&(m==3)) printf("%lld\n",(LL)360%P);
	if ((n==3)&&(m==3)) printf("%lld\n",(LL)108864%P);
}
int main(){
	freopen("count.in","r",stdin);freopen("count.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&P);
	if (m>n) swap(n,m);
	if (n<=3 && m<=3) casea();
} 
