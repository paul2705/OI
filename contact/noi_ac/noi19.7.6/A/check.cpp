#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		cout<<cnt<<endl;
		system("./A-gen");
		system("./A_1");
		system("./A_zbw");
		if (system("diff A.out A_.out")) break;
	}
	return 0;
}
