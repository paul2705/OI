#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getA");
		system("./A");
		system("./A_");
		if (system("diff A.out A1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
