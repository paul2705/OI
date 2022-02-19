#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=505;
int r,c,a,b,map[MAXN][MAXN],s[MAXN][MAXN],ans;
bool check(int x){
	int now=0,num=0;
	for (int i=1;i<=r;i++){
		int dis=0,sum=0;
		for (int j=1;j<=c;j++){
			if (dis+(s[i][j]-s[i][j-1])-(s[now][j]-s[now][j-1])<x)
				dis+=s[i][j]-s[i][j-1]-(s[now][j]-s[now][j-1]);
			else sum++,dis=0;
		}
		if (sum>=b) now=i,sum++;
	}
	return num>=a;
}
int main(){
	scanf("%d%d%d%d",&r,&c,&a,&b);
	for (int i=1;i<=r;i++){
		for (int j=1;j<=c;j++) scanf("%d",&map[i][j]);
	}
	for (int i=1;i<=r;i++){
		for (int j=1;j<=c;j++)
