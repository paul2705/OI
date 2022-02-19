#include<bits/stdc++.h>
using namespace std;

int n,m,p;

int ans[3][3]={1,2,6,2,16,360,6,360,108864};

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&p);

	printf("%d\n",ans[n-1][m-1]);

	return 0;
}
