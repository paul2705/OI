#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinnew");
		system("time ./new_bl");
		system("time ./C");
		if (system("diff new.out new1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
