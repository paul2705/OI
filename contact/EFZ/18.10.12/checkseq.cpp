#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinseq");
		system("./sequencesC");
		system("./sequences_zbw");
		if (system("diff sequences.out sequences1.out")) break;
		cout<<cnt<<endl;
	}
	return 0;
}
