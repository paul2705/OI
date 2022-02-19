#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinpra");
		system("./practice");
		system("./practice_bl");
		if (system("diff practice.out practice1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
