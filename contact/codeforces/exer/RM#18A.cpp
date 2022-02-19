#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll x,ans;
int main(){
	cin>>x;
	ans=log2(x);
	cout<<ans+1<<endl;
	return 0;
}
