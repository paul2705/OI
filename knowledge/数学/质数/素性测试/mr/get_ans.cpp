#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int pri[MAXN];
bool use[MAXN];
int n;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.ans","w",stdout);
	scanf("%d",&n);
	for (int i=2;i<=n;i++){
		if (!use[i]) pri[++pri[0]]=i;
		for (int j=1;j<=pri[0]&&pri[j]*i<=n;j++){
			use[pri[j]*i]=1;
			if (i%pri[j]==0) break;
		}
	}
	for (int i=1;i<=pri[0];i++) printf("%d\n",pri[i]);
	fclose(stdin); fclose(stdout);
	return 0;
}
