#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll T,a,b;
int main(){
	cin>>T;
	while (T--){
		cin>>a>>b;
		if (a-b==1ll) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
