#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e7+1e6+5;
int pri[MAXN];
bool use[MAXN];
int main(){
	use[1]=1;
	for (int i=2;i<MAXN;i++){
		if (!use[i]){
			pri[++pri[0]]=i;
			use[i]=1;
		}
		for (int j=1;j<=pri[0]&&i*pri[j]<MAXN;j++){
			use[i*pri[j]]=1;
			if (i%pri[j]==0) break;
		}
	}
	printf("%d\n",pri[pri[0]]);
	return 0;
}
