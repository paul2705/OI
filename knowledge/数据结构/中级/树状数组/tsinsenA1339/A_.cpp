#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
int pri[MAXN];
bool use[MAXN];
int main(){
	use[1]=1;
	for (int i=2;i<=150;i++){
		if (!use[i]) pri[++pri[0]]=i;
		for (int j=1;j<=pri[0]&&pri[j]*i<=150;j++){
			use[i*pri[j]]=1;
			if (i%pri[j]==0) break;
		}
	}
	cout<<pri[0]<<endl;
	for (int i=1;i<=pri[0];i++) printf("%d,",pri[i]);
	return 0;
}
