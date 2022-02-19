#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1555;
int cnt=0;
int main(){
	char c=' ';
	while (c!='\n'){
		c=getchar();
		if (c!=' '&&c!='\n') cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
