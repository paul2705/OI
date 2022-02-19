#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
int nex[10][MAXN],ok[MAXN];
queue<int> num[10];
char buf[MAXN];
int n,tmp;
int main(){
	memset(ok,1,sizeof(ok)); 
	scanf("%d",&n);
	for (int t=1;t<=n;t++){
		scanf("%d %s",&tmp,buf);
		int len=strlen(buf);
		for (int i=0;i<len;i++) num[buf[i]-'0'].push(i);
		for (int i=0;i<len;i++){
			for (int k=0;k<10;k++){
				if (num[k].empty()) nex[k][i]=-1;
				else nex[k][i]=num[k].front();
			}
			num[buf[i]-'0'].pop();
		}
		int i,j,k,l;
		for (int r=0;r<1e4;r++){
			if (ok[r]){
				i=r/1000,j=r/100-i*10,k=r/10-i*100-j*10,l=r%10;
				if (nex[i][0]==-1||nex[j][nex[i][0]]==-1||nex[k][nex[j][nex[i][0]]]==-1||nex[l][nex[k][nex[j][nex[i][0]]]]==-1) ok[r]=0;
			}
		}
	}
	int ans=0;
	for (int i=0;i<1e4;i++) if (ok[i]) ans++;
	printf("%d\n",ans);
	return 0;
}
