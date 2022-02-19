#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
int f[MAXN];
int main(){
	f[0]=1; f[1]=1;
	cout<<1<<" "<<1<<endl;
	for (int i=2;i<=35;i++){
		f[i]=f[i-1]+f[i-2];
		cout<<i<<" "<<f[i]<<endl;
	}
	return 0;
}
