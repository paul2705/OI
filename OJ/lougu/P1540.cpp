#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int q[MAXN],l,r;
int n,m,a[MAXN],ans;
int main(){
	scanf("%d%d",&m,&n);
	l=0,r=-1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		bool fg=0;
		for (int j=l;j<=r;j++){
			if (q[j]==a[i]) fg=1;
		}
		if (!fg){
//			cout<<i<<" "<<l<<" "<<r<<endl;
			ans++;
			while (r-l+1>m-1) l++;
			q[++r]=a[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
