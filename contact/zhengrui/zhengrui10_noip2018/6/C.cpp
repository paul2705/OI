#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll T,k,l,r;
int main(){
	cin>>T;
	while (T--){
		cin>>k;
		if (k!=1) break;
		cin>>l>>r;
		cout<<r-l+1<<endl;
	}
	return 0;
}
