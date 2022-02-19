#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1e5+5;
int G[3][MAXN],n,m,use[3][MAXN];
char s[10];
int main(){
	scanf("%s",s);
	while (s[0]!='E'){
		switch(s[0]){
			case 'C':
				int x1,y1,x2,y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				G[x1][y1]++,G[x2][y2]++;
				if (G[x1][y1]>=2) use[x1][y1]=1;
				if (G[x2][y2]>=2) use[x2][y2]=1;
				if (x1==x2&&use[x1][y1]&&use[x2][y2]) 
				break;
			case 'O':
				int x1,y1,x2,y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				G[x1][y1]--,G[x2][y2]--;
				 
