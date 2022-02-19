#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int p[MAXN],q[MAXN];
bool use1[MAXN],use2[MAXN];
int n,m,ans[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++){
		if (use1[i]) continue;
		int pos=i,cnt=0;
		while (!use1[pos]){
			cout<<pos<<" ";
			use1[pos]=1;
			q[cnt++]=pos;
			pos=p[pos];
		}
		cout<<endl<<i<<" "<<cnt<<endl;
		pos=m%cnt;
		int now=0;
		for (int j=pos;j!=pos;j=(j+1)%cnt){
			ans[q[now++]]=p[q[j]];
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
