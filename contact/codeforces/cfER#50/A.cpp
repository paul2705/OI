#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll ans,a,b;
int main(){
	cin>>a>>b;
	ans=b/a;
	if (b%a) ans++;
	cout<<ans<<endl;
	return 0;
}
