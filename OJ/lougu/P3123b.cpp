#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,use[8][8],ans;
vector<int> a[8];
int get(char c){
	switch (c){
		case 'B': return 1;
		case 'E': return 2;
		case 'S': return 3;
		case 'I': return 4;
		case 'G': return 5;
		case 'O': return 6;
		case 'E': return 7;
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		char c; int x;
		cin>>c>>x;
		use[get(c)][abs(x)%7]=1;
	}
	for (int i=1;i<=7;i++){
		for (int j=0;j<=6;j++) if (use[i][j]) a[i].push_back(j);
	}
	for (int i=0;
