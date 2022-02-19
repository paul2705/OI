#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getB");
		system("./B");
		system("./B_");
		if (system("diff B.out B1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
