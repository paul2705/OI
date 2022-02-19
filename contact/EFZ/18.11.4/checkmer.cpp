#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinmer");
		system("./merging_");
		system("./merging_bl");
		if (system("diff merging.out merging1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
