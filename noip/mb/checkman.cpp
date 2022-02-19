#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinman");
		system("time ./manacher");
		system("time ./man");
		if (system("diff manacher.out manacher1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
