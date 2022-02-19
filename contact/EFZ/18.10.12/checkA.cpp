#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int cnt;
int main(){
	while (1){
		cnt++;
		system("./getinA");
		system("./mayan");
		system("./mayan1");
		if (system("diff mayan.out mayan1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
