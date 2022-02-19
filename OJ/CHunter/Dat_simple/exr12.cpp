#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int t[MAXN][10];
int n,M,T,rt,cnt[MAXN];
char s[MAXN];
bool fl=1;
void ins(char *s){
	int n=strlen(s+1),u=0;
	for (int i=1;i<=n;i++){
		int x=s[i]-'0';
		if (t[u][x]) u=t[u][x];
		else{
			t[u][x]=++M;
			u=t[u][x];
		}
		if (cnt[u]>0) fl=0;
	}
	cnt[u]++;
	if (u!=M) fl=0;
}
int main(){
	scanf("%d",&T);
	while (T--){
		fl=1;
		M=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%s",s+1);
			ins(s);
		}
		for (int i=0;i<=M;i++){
			cnt[i]=0;
			for (int j=0;j<10;j++) t[i][j]=0;
		}
		if (fl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
