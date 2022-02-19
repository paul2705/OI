#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinwor");
		system("./neworld");
		system("./neworld_bl");
		if (system("diff neworld.out neworld1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
