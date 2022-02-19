#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,k,x;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>k>>x;
		ll ans=(ll)9*(k-1)+x;
		cout<<ans<<endl;
	}
	return 0;
}
