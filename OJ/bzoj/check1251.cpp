#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt;
int main(){
	while (1){
		cout<<cnt<<endl;
		system("./getin1251");
		system("./bzoj1251");
		system("./bzoj1251_");
		if (system("diff bzoj1251.out bzoj1251_.out")) break;
		cnt++;
	}
	return 0;
}
