#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinsort");
		system("./main");
		system("./sort_");
		if (system("diff sort.out sort1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
