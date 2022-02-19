#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a,b;
int main(){
	cin>>a>>b;
	cout<<"YES"<<endl;
	for (ll i=a;i<=b;i+=2){
		cout<<i<<" "<<i+1<<endl;
	}
	return 0;
}
