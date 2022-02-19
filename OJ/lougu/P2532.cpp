#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int f[MAXN];
int n;
int main(){
	scanf("%d",&n);
	f[0]=f[1]=1;
	for (int i=2;i<=n;i++){
		int res=0;
		for (int j=0;j<i;j++){
			res+=f[j]*f[i-j-1];
//			cout<<j<<" "<<i-j-1<<" "<<f[j]*f[i-j-1]<<endl;
		}
//		cout<<res<<endl;
		f[i]=res;
	}
	printf("%d\n",f[n]);
	return 0;
}
