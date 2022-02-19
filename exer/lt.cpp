#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN=1e7+5;
const int N=1e7;
int f[MAXN],pri[MAXN],cnt=0;
int main(){
	for (int i=1;i<=N;i++) f[i]=0;
	for (int i=2;i<=N;i++){
		if (f[i]==0) pri[++cnt]=i;
		for (int j=1;j<=cnt&&i*pri[j]<=N;j++){
			f[i*pri[j]]=1;
//			if (i%pri[j]==0) break;
		}
	}
	for (int i=1;i<=cnt;i++) printf("%d\n",pri[i]);
	printf("\n");
	return 0;
}
