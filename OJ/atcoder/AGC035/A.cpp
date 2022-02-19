#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int k1,k2,k3;
int c1,c2,c3;
int n;
bool fl=0;
int main(){
	scanf("%d",&n);
	k1=k2=k3=-1;
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		if (k1==-1) k1=x,c1=1;
		else if (x!=k1){
			if (k2==-1) k2=x,c2=1;
			else if (x!=k2){
				if (k3==-1) k3=x,c3=1;
				else if (k3!=x) fl=1;
				else c3++;
			}
			else c2++;
		}
		else c1++;
	}
	if (fl) return printf("No\n"),0;
//	cout<<k1<<" "<<k2<<" "<<k3<<endl;
	if (k3==-1&&k2==-1){
		if (k1==0) printf("Yes\n");
		else printf("No\n");
	}
	else if (k3==-1){
		if ((k1==0||k2==0)&&(c1==2*c2||c2==2*c1)) printf("Yes\n");
		else printf("No\n");
	}
	else if (c1==c2&&c2==c3&&(k1^k2)==k3) printf("Yes\n");
	else printf("No\n");
	return 0;
}
