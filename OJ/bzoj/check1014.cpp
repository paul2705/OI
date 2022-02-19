#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt;
int main(){
	cnt++;
	while (1){
		cout<<cnt<<endl;
		system("./get_1014");
		system("./bzoj1014_bl");
		system("./bzoj1014");
		if (system("diff 1014.out 1014.ans")) break;
		cnt++;
	}
	return 0;
}
