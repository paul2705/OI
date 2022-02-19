#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char c='a';
int main(){
	cout<<c+2<<endl;
	cout<<char(c+2)<<endl;
	c+=2;
	cout<<c<<endl;
	return 0;
}
