#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=17;
typedef long long ll;
ll f[MAXN][1<<MAXN],ans;
int n,a[MAXN],k;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&a[i]),f[i][1<<i]=1;
	for (int s=0;s<(1<<n);s++){
		for (int i=0;i<n;i++){
			if (s&(1<<i)){
				for (int j=0;j<n;j++){
					if (!(s&(1<<j))&&abs(a[j]-a[i])>k){
						f[j][s|(1<<j)]+=f[i][s];
					}
				}
			}
		}
	}
	for (int i=0;i<n;i++) ans+=f[i][(1<<n)-1];
	printf("%lld\n",ans);
	return 0;
}
