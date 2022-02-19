#include<iostream>
#include<cstdio>
using namespace std;
int a[5][5],ans[5];
bool cnt[4][30][30];
void check(int l,int d){
	int lis[3]={-1,-1,-1};
	for (int i=0;i<3;i++){
		switch(d){
			case 0:lis[i]=a[l][i];break;
			case 1:lis[i]=a[i][l];break;
			case 2:lis[i]=a[i][l++];break;
		}
	}  
	if (lis[0]==lis[1]&&lis[1]==lis[2]){
		cnt[0][lis[0]][lis[0]]=1;
		return;
	}
	if (lis[0]==lis[1]) cnt[1][lis[0]][lis[2]]=cnt[1][lis[2]][lis[0]]=1;
	if (lis[1]==lis[2]) cnt[1][lis[1]][lis[0]]=cnt[1][lis[0]][lis[1]]=1;
	if (lis[0]==lis[2]) cnt[1][lis[0]][lis[1]]=cnt[1][lis[1]][lis[0]]=1;
}
int main(){
	freopen("tttt.in","r",stdin);
	freopen("tttt.out","w",stdout);
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			char c=getchar();
			if (c>='a'&&c<='z') c-=32;
			if (c<'A'||c>'Z') c=getchar();
			if (c>='a'&&c<='z') c-=32;
			a[i][j]=c-65;
		}
	}
	for (int i=0;i<3;i++)
		for (int j=0;j<=2;j++){
			if (i>=1&&j==2) continue;
			check(i,j);
		}
	for (int i=0;i<2;i++)
		for (int j=0;j<26;j++)
			for (int k=0;k<26;k++)
				if (cnt[i][j][k]) ans[i]++;
	ans[1]/=2;
	printf("%d\n%d\n",ans[0],ans[1]);
	fclose(stdin);fclose(stdout);
	return 0;
}
