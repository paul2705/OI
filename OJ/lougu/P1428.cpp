#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int MAXN=105;
int a[MAXN],n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		int cnt=0;
		for (int j=1;j<i;j++){
			if (a[j]<a[i]) cnt++;
		}
		printf("%d ",cnt);
	}
	cout<<endl;
	return 0;
}
