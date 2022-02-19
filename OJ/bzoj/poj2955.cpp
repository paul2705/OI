#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[205];
int f[205][205],n;
bool check(char a,char b){
	if (a=='('&&b==')') return 1;
	if (a=='['&&b==']') return 1;
	return 0;
}
int main(){
	cin>>s;
	while (s[0]!='e'){
		int n=strlen(s); memset(f,0,sizeof(f));
		for (int l=1;l<n;l++){
			for (int i=0;i<n;i++){
				int j=i+l; if (j>=n) continue;
				if (check(s[i],s[j])) f[i][j]=max(f[i][j],f[i+1][j-1]+2);
				for (int k=i;k<j;k++) f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
//				cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
			}
		}
		printf("%d\n",f[0][n-1]);
		cin>>s;
	}
	return 0;
}
