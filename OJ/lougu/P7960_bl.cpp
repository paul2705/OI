 #include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int pri[MAXN],f[MAXN];
int T;
bool check(int x){
	while (x){
		if (x%10==7) return 1;
		x/=10;
	}
	return 0;
}
int main(){
	freopen("P7960.in","r",stdin);
	freopen("P7960.ans","w",stdout);
	scanf("%d",&T);
	while (T--){
		int x; scanf("%d",&x);
		for (int i=x;;i++){
			int fg=0;
			for (int j=2;j<=i;j++){
				if (i%j==0&&check(j)) fg=1;
			}
			if (fg&&i==x){
				printf("-1\n"); break;
			}
			if (fg==0&&i!=x){
				printf("%d\n",i); break;
			}
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
