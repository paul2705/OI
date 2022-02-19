#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=2e5+1;
const int MAXN=2e5+5;
int T,n,h,a[MAXN];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&h,&n);
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int cnt=0;
		a[n+1]=h+1;
		for (int l=1,r=1;r<=n;l=r+1,r=l){
			while (a[r]-1==a[r+1]) r++;
			if (r==n&&a[r]==1) break;
//			cout<<l<<" "<<r<<endl;
			if (l!=1) l--;
//			cout<<"2: "<<l<<" "<<r<<endl;
			if ((r-l+1)%2==0) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
