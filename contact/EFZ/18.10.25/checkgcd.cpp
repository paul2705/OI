#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getingcd");
		system("./gcd");
		system("./gcd_bl");
		if (system("diff gcd.out gcd1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
