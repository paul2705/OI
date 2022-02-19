#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int n,a[MAXN],pos,ans=1e9;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=105;i++){
		int cnt=0;
		for (int j=1;j<=n;j++){
			cnt+=min(min(abs(a[j]-i),abs(a[j]-i-1)),abs(a[j]-i+1));
		}
//		cout<<i<<" "<<cnt<<endl;
		if (ans>cnt){
			pos=i;
			ans=cnt;
		}
	}
	printf("%d %d\n",pos,ans);
	return 0;
}
