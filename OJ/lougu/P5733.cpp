#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=105;
char s[MAXN];
int main(){
	cin>>s;
	for (int i=0;i<strlen(s);i++){
		if (s[i]>='a'&&s[i]<='z') s[i]+='A'-'a';
	}
	cout<<s<<endl;
	return 0;
}
