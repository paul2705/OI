#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int n,k,a[MAXN];
int q[MAXN],l=1,r=0;
int mx,mn;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		while (r>=l&&a[q[r]]>a[i]) r--;
		q[++r]=i;
		while (q[r]-q[l]>=k) l++;
		if (i>=k) cout<<a[q[l]]<<" ";
	}
	cout<<endl;
	l=1;r=0;
	for (int i=1;i<=n;i++){
		while (r>=l&&a[q[r]]<a[i]) r--;
		q[++r]=i;
		while (q[r]-q[l]>=k) l++;
		if (i>=k) cout<<a[q[l]]<<" ";
	}
	cout<<endl;
	return 0;
}
