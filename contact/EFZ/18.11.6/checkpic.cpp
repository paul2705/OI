#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinpic");
		system("./picture");
		system("./pic_std");
		if (system("diff picture.out picture1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
