#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=205;
int a[MAXN][MAXN];
int ans,pre;
int T,n,m;
int main(){
	scanf("%d",&T);
	while (T--){
//		cout<<T<<endl;
		scanf("%d",&n);
		bool flag=1;
		for (int i=1;i<=n;i++){
			bool tmp=0;
			for (int j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
				tmp|=a[i][j];
			}
			flag&=tmp;
		}
		for (int i=1;i<=n;i++){
			bool tmp=0;
			for (int j=1;j<=n;j++) tmp|=a[j][i];
			flag&=tmp;
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

