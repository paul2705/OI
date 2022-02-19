#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int x;
char s[15];
int main(){
	cin>>s;
	if (s[0]=='S') printf("Cloudy\n");
	else if (s[0]=='C') printf("Rainy\n");
	else printf("Sunny\n");
	return 0;
}
