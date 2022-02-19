#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,a,b,c;
int ans;
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&a,&b,&c);
		ans=0;
		for (int i=0;i<=a;i++){
			for (int j=0;j<=b-2*i;j++){
				if (2*j<=c) ans=max(ans,3*i+3*j);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
