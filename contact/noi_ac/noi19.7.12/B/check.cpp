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
		system("./getin");
		system("./B_bl");
		system("./B_1");
		if (system("diff 1.out 1.ans")) break;
	}
	return 0;
}
