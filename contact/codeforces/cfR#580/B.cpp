#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n;
ll a[MAXN],f[MAXN][3];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) cin>>a[i];
	f[0][1]=(ll)1e13;
	for (int i=1;i<=n;i++){
		f[i][1]=min(f[i-1][1]+abs(a[i]-1),f[i-1][0]+abs(a[i]+1));
		f[i][0]=min(f[i-1][0]+abs(a[i]-1),f[i-1][1]+abs(a[i]+1));
	}
	cout<<f[n][0]<<endl;
	return 0;
}
