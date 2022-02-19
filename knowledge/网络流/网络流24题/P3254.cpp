#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=3e2+5;
const int MAXM=2e2+5;
int d[MAXN],z[MAXN],wow[MAXN];
int m,n;
struct lpl{
	int num,data;
} desk[MAXN],people[MAXM];
bool operator < (lpl a,lpl b){ 
	return a.data>b.data;
}
vector<int> ld[MAXM];
int main(){
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++){
		scanf("%d",&d[i]);
		people[i].num=i; people[i].data=d[i];
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&z[i]);
		desk[i].num=i; desk[i].data=z[i];
	}
	sort(desk+1,desk+n+1);
	sort(people+1,people+m+1);
	for (int i=1;i<=m;i++){
		int qwe=1;
		for (int j=0;j<people[i].data;j++){
			bool flag=0;
			for (int t=qwe;t<=n;t++){
				if (wow[desk[t].num]<desk[t].data){
					wow[desk[t].num]++;
					qwe=t+1;
					flag=1;
					ld[people[i].num].push_back(desk[t].num);
					break;
				}
			}
			if (flag==0) return printf("0\n"),0;
		}
	}
	printf("1\n");
	for (int i=1;i<=m;i++){
		for (int j=0;j<ld[i].size();j++){
			printf("%d ",ld[i][j]);
		}
		printf("\n");
	}
	return 0;
}
