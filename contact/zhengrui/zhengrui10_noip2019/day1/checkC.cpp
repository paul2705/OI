#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++; cout<<cnt<<endl;
		system("./getinC");
		system("./C");
		system("./C_");
		if (system("diff C.out C.ans")) break;
	}
	return 0;
}
