#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt;
int main(){
	while (1){
		cnt++;
		system("./getinA");
		system("./A");
		system("./A_bl");
		if (system("diff redistricting.out redistricting1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
