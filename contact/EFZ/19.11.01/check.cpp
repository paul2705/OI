#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		cout<<cnt<<endl;
		system("./getinA");
		system("./highway");
		system("./A");
		if (system("diff highway.out highway.ans")) break;
	}
	return 0;
}
